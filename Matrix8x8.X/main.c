/*
 * File:   main.c
 * Author: TallDwarf
 *
 * Created on 18 July 2020, 21:29
 */

#define F_CPU (20000000)

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stddef.h>
#include <string.h>
#include "AsciiToMatrix.h"

//Fuses need to be set or set to 0x00
FUSES = 
{
    .WDTCFG = FUSE_WDTCFG_DEFAULT,
    .BODCFG = FUSE_BODCFG_DEFAULT,
    .OSCCFG = FUSE_OSCCFG_DEFAULT,
    .TCD0CFG = FUSE_TCD0CFG_DEFAULT,
    .SYSCFG0 = FUSE_SYSCFG0_DEFAULT,
    .SYSCFG1 = FUSE_SYSCFG1_DEFAULT,
    .APPEND = 0x00,
    .BOOTEND = 0x00
};

//F_CPU / PRESCALER
#define START_CLOCK 3333333

#define USART0_BAUD_RATE_CLOCK(CLOCK, BAUD_RATE) ((float)(CLOCK * 64 / (16 * (float)BAUD_RATE)) + 0.5)
#define USART0_BAUD_RATE(BAUD_RATE) USART0_BAUD_RATE_CLOCK(START_CLOCK, BAUD_RATE)

#define USART0_READ_READY (USART0.STATUS & USART_RXCIF_bm)
#define USART0_WRITE_READY (USART0.STATUS & USART_DREIF_bm)

#define BUFFER_SIZE (EEPROM_SIZE - 1)

#define LATCH PIN2_bm
#define CLOCK PIN3_bm
#define DATA PIN1_bm

//COMMANDS
#define CMD_SPEED 1
#define CMD_CLEAR_EEPROM 2
#define CMD_SAVE_TO_EEPROM 3

struct {
    uint8_t eepromActive : 1; //Is the eeprom active
    uint8_t charPos : 4; //the next column that needs adding
    uint8_t charUpdate : 1; //should the next column be added
    uint8_t emptyChar : 1; //empty char is pushed to matrix before resetting
    uint8_t saveToEeprom : 1;
} volatile pending = 
{
    .eepromActive = 0,
    .emptyChar = 0,
    .charUpdate = 1,
    .charPos = 0,
    .saveToEeprom = 0
};

struct {
    uint8_t* eepromAddress;
    uint8_t dataSize;
    uint8_t* data;
} volatile eeprom_desc = {
  .eepromAddress = (uint8_t*)EEPROM_START,
  .data = NULL,
  .dataSize = 0
};

//========================
//UART
//========================

//Required functions
void shift_bits(uint32_t const negative, uint8_t positive);
void write_eeprom(uint8_t* const buffer, uint8_t bufferSize);

void init_usart(uint16_t baud)
{
    //Set Pins
    PORTA.DIR &= ~PIN7_bm;
    PORTA.DIR |= PIN6_bm;
    
    USART0.BAUD = (uint16_t)USART0_BAUD_RATE(baud);
    USART0.CTRLB |= (USART_RXEN_bm | USART_TXEN_bm);   
}

void send_char(uint8_t c)
{
    while(!USART0_WRITE_READY)
    { ; }
    
    USART0.TXDATAL = c;
}

void send_string(uint8_t *str)
{
    while(str != NULL && *str != '\0')
    {
        send_char(*str);
        ++str;
    }
}

uint8_t read_char(void)
{
    while(!USART0_READ_READY)
    {   ;   }
    
    return USART0.RXDATAL;
}

uint8_t read_char_timeout(void)
{
    int8_t delay = 4;
    pending.charUpdate = 0;
    
    while(delay > 0)
    {
        if(USART0_READ_READY)
            return read_char();
        
        if(pending.charUpdate == 1)
        {
            delay--;
            pending.charUpdate = 0;
        }
    }
    
    return 0;
}

void flush_uart()
{
    int8_t delay = 4;
    pending.charUpdate = 0;
    
    while(delay > 0)
    {
        if(USART0_READ_READY)
        {
            read_char();
            delay = 4;
        }

        if(pending.charUpdate == 1)
        {
            delay--;
            pending.charUpdate = 0;
        }
    }
}

void parse_command(uint8_t commandChar)
{
    if(commandChar == '+')
    {
        flush_uart();
    }
    else
    {
        uint8_t val;
        switch(commandChar)
        {
            //Lower = faster
            case CMD_SPEED:
                val = read_char_timeout();              
                
                if(val == 0)
                    break;
                
                //max Speed
                if(val < 0x50)
                    val = 0x50;
                
                TCA0.SINGLE.PER = ((uint16_t)val * 2);
                break;
                
            case CMD_CLEAR_EEPROM:
                eeprom_desc.eepromAddress = (uint8_t*)EEPROM_START;     
                
                if(*eeprom_desc.eepromAddress != 0xFF)
                {                
                    //Add value to first eeprom address
                    *eeprom_desc.eepromAddress = 0xFF;

                    //Call eeprom erase will only erase first address
                    CCP = CCP_SPM_gc;
                    NVMCTRL.CTRLA = NVMCTRL_CMD_EEERASE_gc;
                }
                break;
                
            case CMD_SAVE_TO_EEPROM:
                val = read_char_timeout();
                
                if(val == 0)
                    break;
                
                if(val == 1)
                    pending.saveToEeprom = 1;
                else 
                    pending.saveToEeprom = 0;
                
                break;
            default:
                flush_uart();
                break;
        }
    }
}

uint8_t check_usart(uint8_t * const bufferSize, uint8_t* const buffer)
{
    if(USART0_READ_READY)
    {
        uint8_t firstChar = read_char();
        
        //Commands start with + so ignore the command text
        if(firstChar < SPACE_ASCII_VALUE || firstChar == '+')
        {
            parse_command(firstChar);
        }
        else
        {
            //Clear matrix
            shift_bits(0x00000000, 0x00);        

            //Reset buffer;
            *bufferSize = 1;
            uint8_t done = 0;            
            
            //Clear buffer
            memset(buffer, '\0', BUFFER_SIZE);
            buffer[0] = firstChar;

            while(done == 0)
            {                
                if(USART0_READ_READY && *bufferSize < BUFFER_SIZE)
                {
                    buffer[*bufferSize] = read_char();

                    if(buffer[*bufferSize] < SPACE_ASCII_VALUE)
                        done = 1;

                    ++(*bufferSize);
                }

                //Overflow
                if(*bufferSize == BUFFER_SIZE)
                {
                    flush_uart();
                    done = 1;
                }
            }

            //Should the message be saved to eeprom
            if(pending.saveToEeprom)
                write_eeprom(buffer, *bufferSize);
            
            return 1;
        }
    }
    
    return 0;
}

//===========================
//TIMER
//===========================

void init_timer()
{
    TCA0.SINGLE.PERL = 0x97;
    TCA0.SINGLE.PERH = 0x01;
    
    TCA0.SINGLE.INTCTRL = TCA_SINGLE_OVF_bm;
    
    TCA0.SINGLE.CTRLA = TCA_SINGLE_CLKSEL_DIV1024_gc | TCA_SINGLE_ENABLE_bm;
    
    //Start timer
    TCA0.SINGLE.INTFLAGS |= TCA_SINGLE_OVF_bm;
}

ISR(TCA0_OVF_vect)
{
    pending.charUpdate = 1;
    
    TCA0.SINGLE.INTFLAGS |= TCA_SINGLE_OVF_bm;
}

//===========================
//EEPROM
//===========================

//Required functions
void load_buffer(uint8_t * buffer, uint8_t* bufferSize);

void init_eeprom(uint8_t* buffer, uint8_t* bufferSize)
{
    load_buffer(buffer, bufferSize);
}

ISR(NVMCTRL_EE_vect)
{       
    if(eeprom_desc.dataSize == 0)
    {
        //Disable EEPROM interrupt3
        
        NVMCTRL.INTFLAGS &= ~NVMCTRL_EEREADY_bm;
        NVMCTRL.INTCTRL &= ~NVMCTRL_EEREADY_bm;
        pending.eepromActive = 0;
    }
    else
    {        
        uint8_t size = ((eeprom_desc.dataSize <= EEPROM_PAGE_SIZE) ? eeprom_desc.dataSize : EEPROM_PAGE_SIZE);
        
        memcpy(eeprom_desc.eepromAddress, eeprom_desc.data, size);    
        eeprom_desc.eepromAddress += size;
        eeprom_desc.data += size;
        eeprom_desc.dataSize -= size;
        
        CCP = CCP_SPM_gc;
        NVMCTRL.CTRLA = NVMCTRL_CMD_PAGEERASEWRITE_gc;
    
        //Clear flag manually
        NVMCTRL.INTFLAGS = NVMCTRL_EEREADY_bm;
    }
}

void write_eeprom(uint8_t* buffer, uint8_t bufferSize)
{
    if(bufferSize == 0)
        return;
    
    //If eeprom is not busy
    while((NVMCTRL.STATUS & NVMCTRL_EEBUSY_bm) != 0x00)
    {;}
    
    //Setup eeprom desc
    eeprom_desc.eepromAddress = (uint8_t*)EEPROM_START;
    eeprom_desc.dataSize = bufferSize;
    eeprom_desc.data = buffer;

    //set eeprom active stopping another message 
    pending.eepromActive = 1;
    
    //First byte is bufferSize
    *eeprom_desc.eepromAddress++ = bufferSize;
    
    uint8_t size = ((eeprom_desc.dataSize <= (EEPROM_PAGE_SIZE - 1)) ? eeprom_desc.dataSize : (EEPROM_PAGE_SIZE - 1));
    
    //Copy data size to 
    memcpy(eeprom_desc.eepromAddress, eeprom_desc.data, size);    
    eeprom_desc.eepromAddress += size;
    eeprom_desc.data += size;
    eeprom_desc.dataSize -= size;
    
    CCP = CCP_SPM_gc;
    NVMCTRL.CTRLA = NVMCTRL_CMD_PAGEERASEWRITE_gc;

    NVMCTRL.INTFLAGS = NVMCTRL_EEREADY_bm;
    NVMCTRL.INTCTRL = NVMCTRL_EEREADY_bm;
}

void load_buffer(uint8_t * buffer, uint8_t* bufferSize)
{
    while((NVMCTRL.STATUS & NVMCTRL_EEBUSY_bm) != 0x00)
    {;}
    
    uint8_t* eepromMem = (uint8_t*)EEPROM_START;
    
    uint8_t read = *(eepromMem++);
    
    //Max value is 0x7F
    if(read >= 0x80)
    {
        *bufferSize = 12; 
                
        buffer[0] = 'H';
        buffer[1] = 'e';
        buffer[2] = 'l';
        buffer[3] = 'l';
        buffer[4] = 'o';
        buffer[5] = ' ';
        buffer[6] = 'W';
        buffer[7] = 'o';
        buffer[8] = 'r';
        buffer[9] = 'l';
        buffer[10] = 'd';
        buffer[11] = '!';
    }
    else
    {
        *bufferSize = read;        
        memcpy(buffer, eepromMem, read);
    }
}

//===========================
//Shift out
//===========================

void init_shift()
{
    //Set pins as output
    PORTA.DIR |= (LATCH | CLOCK | DATA);
    PORTA.OUT = 0x00;
}

void write_byte(uint8_t data)
{
    PORTA.OUT &= ~(DATA | CLOCK);
    
    for(int8_t i = 7; i >= 0; --i)
    {
        PORTA.OUT &= ~(CLOCK);
        
        if((data >> i) & 0x01)
        {
            PORTA.OUT |= DATA;
        }
        else
        {
            PORTA.OUT &= ~DATA;
        }
        
        PORTA.OUT |= CLOCK;
    }    
}

void shift_bits(uint32_t const negative, uint8_t positive)
{
    PORTA.OUT |= LATCH;    
    write_byte(~(negative >> 24));
    write_byte(~(negative >> 16));
    write_byte(~(negative >> 8));
    write_byte(~ negative);
    write_byte(positive);
    PORTA.OUT &= ~(LATCH);
    
    PORTA.OUT &= ~(DATA | CLOCK);
}

uint8_t scroll_matrix(uint32_t* const matrix, uint8_t letter)
{
    if(pending.charUpdate)
    {      
        pending.charUpdate = 0;
        
        if(pending.emptyChar == 1 || letter < FIRST_ASCII_VALUE)
        {
            for(int8_t i = 0; i < 8; ++i)
            {
                matrix[i] = (matrix[i] << 1);
            }
        }
        else
        {
            const Character* character = GET_LETTER(letter);
            
            if(pending.charPos == character->size)
            {
                //Add single line to split characters
                for(int8_t i = 0; i < 8; ++i)
                {
                    matrix[i] = (matrix[i] << 1);
                }
                    
                //Set charPos to the end to load the next character
                pending.charPos = 7;
            }
            else
            {            
                for(int8_t i = 0; i < 8; ++i)
                {
                    matrix[i] = (matrix[i] << 1);
                    
                    if(character->character[pending.charPos] & (0x01 << i))
                        matrix[i] |= 0x01;
                }
            }
        }
        
        //If the char has finished 
        if(pending.charPos >= 7)
        {
            //Reset char
            pending.charPos = 0;

            //return true to load the next char
            return 1;
        }
        
        pending.charPos++;
    }   
    
    return 0;
}

int main(void) 
{
    uint8_t bufferSize = 0;
    uint8_t buffer[BUFFER_SIZE] = {'\0'};  
    
    uint8_t textPos = 0;
    uint8_t i_Matrix = 0;
    uint32_t matrix[8] = {0};
       
    init_shift();
    init_usart(9600);     
    
    SREG |= CPU_I_bm; // Enable global interrupts
    
    //Initialise things that use interrupts
    init_eeprom(buffer, &bufferSize);
    init_timer();

    while (1) 
    {               
        //If saving previous message ignore incoming usart
        //Check usart if a new message clear matrix
        if(!pending.eepromActive && check_usart(&bufferSize, buffer))
        {
            textPos = 0;
            i_Matrix = 0;
            pending.emptyChar = 1;
            memset(matrix, 0, sizeof(matrix));
        }
             
        //Update matrix
        if(scroll_matrix(matrix, buffer[textPos]))
        {
            if(pending.emptyChar == 1)
            {
                pending.emptyChar = 0;
            }
            else
            {            
                textPos++;

                if(textPos >= bufferSize)
                {
                    pending.emptyChar = 1;
                    textPos = 0;
                }
            }
        }

        //Shift out bits
        shift_bits(matrix[i_Matrix], (0x01 << i_Matrix));
        i_Matrix++;
        
        if(i_Matrix >= 8)
            i_Matrix = 0;
    }
}