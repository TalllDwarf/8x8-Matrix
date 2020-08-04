/* 
 * File:   AsciiToMatrix.h
 * Author: TallDwarf
 *
 * Created on 21 July 2020, 02:42
 */

#ifndef ASCIITOMATRIX_H
#define	ASCIITOMATRIX_H

#define CREATE_CHAR(X) {c##X, (sizeof(c##X) / sizeof(c##X[0]))}
#define GET_LETTER(letter) (LETTERS + (letter - 33))
#define FIRST_ASCII_VALUE 33

#define SPACE_ASCII_VALUE 32
#define ZERO_ASCII_VALUE 48
#define NINE_ASCII_VALUE 57
#define A_ASCII_VALUE 65
#define Z_ASCII_VALUE 90
#define a_ASCII_VALUE 97
#define z_ASCII_VALUE 122

//!
const unsigned char c33[] = {
  0b00001100,
  0b10111110,
  0b10111110,
  0b00001100
};

//"
const unsigned char c34[] = {
  0b00000110,
  0b00001110,
  0b00000000,
  0b00001110,
  0b00000110
};

//#
const unsigned char c35[] ={
  0b00101000,
  0b11111110,
  0b11111110,
  0b00101000,
  0b11111110,
  0b11111110,
  0b00101000
};

//$
const unsigned char c36[] = {
  0b01001000,
  0b01010100,
  0b11010110,
  0b01010100,
  0b00100100
};

//%
const unsigned char c37[] = {
  0b01000110,
  0b01100110,
  0b00110000,
  0b00011000,
  0b11001100,
  0b11000100
};

//&
const unsigned char c38[] ={
  0b01100100,
  0b11111110,
  0b10001010,
  0b10011010,
  0b11101110,
  0b11000100,
  0b10100000
};
//'
const unsigned char c39[] ={
  0b00001110,
  0b00001110
};

//(
const unsigned char c40[] ={
  0b00111000,
  0b01111100,
  0b11000110,
  0b10000010
};

//)
const unsigned char c41[] ={
  0b10000010,
  0b11000110,
  0b01111100,
  0b00111000
};

//*
const unsigned char c42[] ={
  0b00010000,
  0b01010100,
  0b01111100,
  0b00111000,
  0b01111100,
  0b01010100,
  0b00010000
};

//+
const unsigned char c43[] ={
  0b00010000,
  0b00010000,
  0b01111100,
  0b00010000,
  0b00010000
};

//,
const unsigned char c44[] ={
  0b10000000,
  0b11110000,
  0b01110000
};

//-
const unsigned char c45[] ={
  0b00010000,
  0b00010000,
  0b00010000,
  0b00010000
};

//.
const unsigned char c46[] ={
  0b11000000,
  0b11000000
};

///
const unsigned char c47[] ={
  0b01000000,
  0b01100000,
  0b00110000,
  0b00011000,
  0b00001100,
  0b00000100
};

//0
const unsigned char c48[] ={
  0b01111100,
  0b11111110,
  0b10010010,
  0b10001010,
  0b11111110,
  0b01111100
};

//1
const unsigned char c49[] ={
  0b10000000,
  0b10001000,
  0b11111110,
  0b11111110,
  0b10000000,
  0b10000000
};

//2
const unsigned char c50[] ={
  0b11000100,
  0b11100110,
  0b10100010,
  0b10010010,
  0b10011110,
  0b10001100
};

//3
const unsigned char c51[] ={
  0b01000100,
  0b11000110,
  0b10010010,
  0b10010010,
  0b11111110,
  0b01101100
};

//4
const unsigned char c52[] ={
  0b00110000,
  0b00101000,
  0b00100100,
  0b11111110,
  0b11111110,
  0b00100000
};

//5
const unsigned char c53[] ={
  0b01001110,
  0b11001110,
  0b10001010,
  0b10001010,
  0b11111010,
  0b01110010
};

//6
const unsigned char c54[] ={
  0b01111100,
  0b11111110,
  0b10010010,
  0b10010010,
  0b11110110,
  0b01100100
};

//7
const unsigned char c55[] ={
  0b00000110,
  0b00000110,
  0b11100010,
  0b11111010,
  0b00011110,
  0b00000110
};

//8
const unsigned char c56[] ={
  0b01101100,
  0b11111110,
  0b10010010,
  0b10010010,
  0b11111110,
  0b01101100
};

//9
const unsigned char c57[] ={
  0b01001100,
  0b11011110,
  0b10010010,
  0b10010010,
  0b11111110,
  0b01111100
};

//:
const unsigned char c58[] ={
  0b01101100,
  0b01101100
};

//;
const unsigned char c59[] ={
  0b10000000,
  0b11101100,
  0b01101100
};

//<
const unsigned char c60[] ={
  0b00010000,
  0b00111000,
  0b01101100,
  0b11000110,
  0b10000010
};

//=
const unsigned char c61[] ={
  0b00101000,
  0b00101000,
  0b00101000,
  0b00101000
};

//>
const unsigned char c62[] ={
  0b10000010,
  0b11000110,
  0b01101100,
  0b00111000,
  0b00010000
};

//?
const unsigned char c63[] ={
  0b00000100,
  0b00000110,
  0b10110010,
  0b10110010,
  0b00011110,
  0b00001100
};

//@
const unsigned char c64[] ={
  0b00111100,
  0b01000010,
  0b01011010,
  0b01011010,
  0b01001100,
  0b00100000
};

//A
const unsigned char c65[] ={
  0b11111100,
  0b11111110,
  0b00010010,
  0b00010010,
  0b11111110,
  0b11111100
};

//B
const unsigned char c66[] ={
  0b11111110,
  0b11111110,
  0b10010010,
  0b10010010,
  0b11111110,
  0b01101100
};

//C
const unsigned char c67[] ={
  0b01111100,
  0b11111110,
  0b10000010,
  0b10000010,
  0b11000110,
  0b01000100
};

//D
const unsigned char c68[] ={
  0b11111110,
  0b11111110,
  0b10000010,
  0b10000010,
  0b11111110,
  0b01111100
};

//E
const unsigned char c69[] ={
  0b11111110,
  0b11111110,
  0b10010010,
  0b10010010,
  0b10010010,
  0b10000010
};

//F
const unsigned char c70[] ={
  0b11111110,
  0b11111110,
  0b00010010,
  0b00010010,
  0b00010010,
  0b00000010
};

//G
const unsigned char c71[] ={
  0b01111100,
  0b11111110,
  0b10000010,
  0b10100010,
  0b11100110,
  0b01100100
};

//H
const unsigned char c72[] ={
  0b11111110,
  0b11111110,
  0b00010000,
  0b00010000,
  0b11111110,
  0b11111110
};

//I
const unsigned char c73[] ={
  0b10000010,
  0b11111110,
  0b11111110,
  0b10000010        
};
//J
const unsigned char c74[] ={
  0b01100000,
  0b11100000,
  0b10000010,
  0b11111110,
  0b01111110,
  0b00000010
};
//K
const unsigned char c75[] ={
  0b11111110,
  0b11111110,
  0b00111000,
  0b01101100,
  0b11000110,
  0b10000010
};
//L
const unsigned char c76[] ={
  0b11111110,
  0b11111110,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000
};
//M
const unsigned char c77[] ={
  0b11111110,
  0b11111110,
  0b00001100,
  0b00011000,
  0b00001100,
  0b11111110,
  0b11111110
};
//N
const unsigned char c78[] ={
  0b11111110,
  0b11111110,
  0b00001100,
  0b00011000,
  0b00110000,
  0b11111110,
  0b11111110
};
//O
const unsigned char c79[] ={
  0b01111100,
  0b11111110,
  0b10000010,
  0b10000010,
  0b11111110,
  0b01111100
};
//P
const unsigned char c80[] ={
  0b11111110,
  0b11111110,
  0b00100010,
  0b00100010,
  0b00111110,
  0b00011100
};
//Q
const unsigned char c81[] ={
  0b00111100,
  0b01111110,
  0b01000010,
  0b01100010,
  0b11111110,
  0b10111100
};
//R
const unsigned char c82[] ={
  0b11111110,
  0b11111110,
  0b00110010,
  0b01110010,
  0b11011110,
  0b10001100
};
//S
const unsigned char c83[] ={
  0b01001100,
  0b11011110,
  0b10010010,
  0b10010010,
  0b11110110,
  0b01100100
};
//T
const unsigned char c84[] ={
  0b00000110,
  0b00000010,
  0b11111110,
  0b11111110,
  0b00000010,
  0b00000110
};
//U
const unsigned char c85[] ={
  0b01111110,
  0b11111110,
  0b10000000,
  0b10000000,
  0b11111110,
  0b11111110
};
//V
const unsigned char c86[] ={
  0b00111110,
  0b01111110,
  0b11000000,
  0b11000000,
  0b01111110,
  0b00111110
};
//W
const unsigned char c87[] ={
  0b11111110,
  0b11111110,
  0b01100000,
  0b00110000,
  0b01100000,
  0b11111110,
  0b11111110
};
//X
const unsigned char c88[] ={
  0b11000110,
  0b11101110,
  0b00111000,
  0b00010000,
  0b00111000,
  0b11101110,
  0b11000110
};
//Y
const unsigned char c89[] ={
  0b00001110,
  0b00011110,
  0b11110000,
  0b11110000,
  0b00011110,
  0b00001110
};
//Z
const unsigned char c90[] ={
  0b11000010,
  0b11100010,
  0b10110010,
  0b10011010,
  0b10001110,
  0b10000110
};
//[
const unsigned char c91[] ={
  0b11111110,
  0b11111110,
  0b10000010,
  0b10000010
};
const unsigned char c92[] ={
  0b00000100,
  0b00001100,
  0b00011000,
  0b00110000,
  0b01100000,
  0b01000000
};
//]
const unsigned char c93[] ={
  0b10000010,
  0b10000010,
  0b11111110,
  0b11111110
};
//^
const unsigned char c94[] ={
  0b00010000,
  0b00001000,
  0b00000100,
  0b00000010,
  0b00000100,
  0b00001000,
  0b00010000
};
//_
const unsigned char c95[] ={
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000,
  0b10000000
};
//`
const unsigned char c96[] ={
  0b00000110,
  0b00001110,
  0b00001000
};
//a
const unsigned char c97[] ={
  0b01000000,
  0b11101000,
  0b10101000,
  0b10101000,
  0b11111000,
  0b11110000
};
//b
const unsigned char c98[] ={
  0b11111110,
  0b11111110,
  0b10010000,
  0b10010000,
  0b11110000,
  0b01100000
};
//c
const unsigned char c99[] ={
  0b01110000,
  0b11111000,
  0b10001000,
  0b10001000,
  0b11011000,
  0b01010000
};
//d
const unsigned char c100[] ={
  0b01100000,
  0b11110000,
  0b10010000,
  0b10010000,
  0b11111110,
  0b11111110
};
//e
const unsigned char c101[] ={
  0b01110000,
  0b11111000,
  0b10101000,
  0b10101000,
  0b10111000,
  0b00110000
};
//f
const unsigned char c102[] ={
  0b00100000,
  0b11111100,
  0b11111110,
  0b00100010,
  0b00100110,
  0b00000100
};
//g
const unsigned char c103[] ={
  0b00011000,
  0b10111100,
  0b10100100,
  0b10100100,
  0b11111100,
  0b01111100
};
//h
const unsigned char c104[] ={
  0b11111110,
  0b11111110,
  0b00010000,
  0b00010000,
  0b11110000,
  0b11100000
};
//i
const unsigned char c105[] ={
  0b10000000,
  0b11110100,
  0b11110100,
  0b10000000
};
//j
const unsigned char c106[] ={
  0b01100000,
  0b11100000,
  0b10000000,
  0b11111010,
  0b01111010
};
//k
const unsigned char c107[] ={
  0b11111110,
  0b11111110,
  0b00100000,
  0b01110000,
  0b11011000,
  0b10001000
};
//l
const unsigned char c108[] ={
  0b11111110,
  0b11111110
};
//m
const unsigned char c109[] ={
  0b11111000,
  0b11111000,
  0b00110000,
  0b11100000,
  0b00110000,
  0b11111000,
  0b11111000
};
//n
const unsigned char c110[] ={
  0b11111000,
  0b11111000,
  0b00011000,
  0b00011000,
  0b11111000,
  0b11110000
};
//o
const unsigned char c111[] ={
  0b01110000,
  0b11111000,
  0b10001000,
  0b10001000,
  0b11111000,
  0b01110000
};
//p
const unsigned char c112[] ={
  0b11111100,
  0b11111100,
  0b00100100,
  0b00100100,
  0b00111100,
  0b00011000
};
//q
const unsigned char c113[] ={
  0b00011000,
  0b00111100,
  0b00100100,
  0b11111100,
  0b11111100,
  0b10000000,
  0b11000000
};
//r
const unsigned char c114[] ={
  0b11111000,
  0b11111000,
  0b00001000,
  0b00001000,
  0b00111000,
  0b00110000
};
//s
const unsigned char c115[] ={
  0b10010000,
  0b10101000,
  0b10101000,
  0b10101000,
  0b10101000,
  0b01001000
};
//t
const unsigned char c116[] ={
  0b00010000,
  0b00010000,
  0b11111100,
  0b11111100,
  0b00010000,
  0b00010000
};
//u
const unsigned char c117[] ={
  0b01111000,
  0b11111000,
  0b10000000,
  0b10000000,
  0b11111000,
  0b11111000
};
//v
const unsigned char c118[] ={
  0b00110000,
  0b01110000,
  0b11000000,
  0b11000000,
  0b01110000,
  0b00110000
};
//w
const unsigned char c119[] ={
  0b01111000,
  0b11111000,
  0b10000000,
  0b11110000,
  0b10000000,
  0b11111000,
  0b01111000
};
//x
const unsigned char c120[] ={
  0b10001000,
  0b11011000,
  0b01110000,
  0b01110000,
  0b11011000,
  0b10001000
};
//y
const unsigned char c121[] ={
  0b00011000,
  0b10111000,
  0b10100000,
  0b10100000,
  0b11111000,
  0b01111000
};
//z
const unsigned char c122[] ={
  0b11001000,
  0b11101000,
  0b10111000,
  0b10011000
};
//{
const unsigned char c123[] ={
  0b00010000,
  0b01111100,
  0b11101110,
  0b10000010,
  0b10000010
};
//|
const unsigned char c124[] ={
  0b01111110,
  0b01111110
};
//}
const unsigned char c125[] ={
  0b10000010,
  0b10000010,
  0b11101110,
  0b01111100,
  0b00010000
};
//~
const unsigned char c126[] ={
  0b00010000,
  0b00011000,
  0b00001000,
  0b00011000,
  0b00010000,
  0b00001000
};
//
const unsigned char c127[] ={
  0b00011100,
  0b00111110,
  0b01111100,
  0b11111000,
  0b01111100,
  0b00111110,
  0b00011100
};

#if defined(EXTENDED_ASCII)

const unsigned char c128[] = {

};

const unsigned char c129[] = {

};

const unsigned char c130[] = {

};

const unsigned char c131[] = {

};

const unsigned char c132[] = {

};

const unsigned char c133[] = {

};

const unsigned char c134[] = {

};

const unsigned char c135[] = {

};

const unsigned char c136[] = {

};

const unsigned char c137[] = {

};

cosnt unsigned char c138[] = {

};

const unsigned char c139[] = {

};

const unsigned char c140[] = {

};

const unsigned char 141[] = {

};

const unsigned char 142[] = {

};

const unsigned char 143[] = {

};

const unsigned char 144[] = {
    
};

const unsigned char 145[] = {
    
};

const unsigned char 146[] = {
    
};

const unsigned char 147[] = {
    
};

const unsigned char 148[] = {
    
};

const unsigned char 149[] = {
    
};

const unsigned char 150[] = {
    
};

const unsigned char 151[] = {
    
};

const unsigned char 152[] = {
    
};

const unsigned char 153[] = {
    
};
const unsigned char 154[] = {
    
};
const unsigned char 155[] = {
    
};
const unsigned char 156[] = {
    
};
const unsigned char 157[] = {
    
};
const unsigned char 158[] = {
    
};
const unsigned char 159[] = {
    
};
const unsigned char 160[] = {
    
};
const unsigned char 161[] = {
    
};
const unsigned char 162[] = {
    
};
const unsigned char 163[] = {
    
};
const unsigned char 164[] = {
    
};
const unsigned char 165[] = {
    
};
const unsigned char 166[] = {
    
};
const unsigned char 167[] = {
    
};
const unsigned char 168[] = {
    
};
const unsigned char 169[] = {
    
};
const unsigned char 170[] = {
    
};
const unsigned char 171[] = {
    
};
const unsigned char 172[] = {
    
};
const unsigned char 173[] = {
    
};
const unsigned char 174[] = {
    
};
const unsigned char 175[] = {
    
};
const unsigned char 176[] = {
    
};
const unsigned char 177[] = {
    
};
const unsigned char 178[] = {
    
};
const unsigned char 179[] = {
    
};
const unsigned char 180[] = {
    
};
const unsigned char 181[] = {
    
};
const unsigned char 182[] = {
    
};
const unsigned char 183[] = {
    
};
const unsigned char 184[] = {
    
};
const unsigned char 185[] = {
    
};
const unsigned char 186[] = {
    
};
const unsigned char 187[] = {
    
};
const unsigned char 188[] = {
    
};
const unsigned char 189[] = {
    
};
const unsigned char 190[] = {
    
};
const unsigned char 191[] = {
    
};
const unsigned char 192[] = {
    
};
const unsigned char 193[] = {
    
};
const unsigned char 194[] = {
    
};
const unsigned char 195[] = {
    
};
const unsigned char 196[] = {
    
};
const unsigned char 197[] = {
    
};
const unsigned char 198[] = {
    
};
const unsigned char 199[] = {
    
};
const unsigned char 200[] = {
    
};
const unsigned char 201[] = {
    
};
const unsigned char 202[] = {
    
};
const unsigned char 203[] = {
    
};
const unsigned char 204[] = {
    
};
const unsigned char 205[] = {
    
};
const unsigned char 206[] = {
    
};
const unsigned char 207[] = {
    
};
const unsigned char 208[] = {
    
};
const unsigned char 209[] = {
    
};
const unsigned char 210[] = {
    
};
const unsigned char 211[] = {
    
};
const unsigned char 212[] = {
    
};
const unsigned char 213[] = {
    
};
const unsigned char 214[] = {
    
};
const unsigned char 215[] = {
    
};
const unsigned char 216[] = {
    
};
const unsigned char 217[] = {
    
};
const unsigned char 218[] = {
    
};
const unsigned char 219[] = {
    
};
const unsigned char 220[] = {
    
};
const unsigned char 221[] = {
    
};
const unsigned char 222[] = {
    
};
const unsigned char 223[] = {
    
};
const unsigned char 224[] = {
    
};
const unsigned char 225[] = {
    
};
const unsigned char 226[] = {
    
};
const unsigned char 227[] = {
    
};
const unsigned char 228[] = {
    
};
const unsigned char 229[] = {
    
};
const unsigned char 230[] = {
    
};
const unsigned char 231[] = {
    
};
const unsigned char 232[] = {
    
};
const unsigned char 233[] = {
    
};
const unsigned char 234[] = {
    
};
const unsigned char 235[] = {
    
};
const unsigned char 236[] = {
    
};
const unsigned char 237[] = {
    
};
const unsigned char 238[] = {
    
};
const unsigned char 239[] = {
    
};
const unsigned char 240[] = {
    
};
const unsigned char 241[] = {
    
};
const unsigned char 242[] = {
    
};
const unsigned char 243[] = {
    
};
const unsigned char 244[] = {
    
};
const unsigned char 245[] = {
    
};
const unsigned char 246[] = {
    
};
const unsigned char 247[] = {
    
};
const unsigned char 248[] = {
    
};
const unsigned char 249[] = {
    
};
const unsigned char 250[] = {
    
};
const unsigned char 251[] = {
    
};
const unsigned char 252[] = {
    
};
const unsigned char 253[] = {
    
};
const unsigned char 254[] = {
    
};
const unsigned char 255[] = {
    
};

#elif defined(EXTENDED_MATRIX)

const unsigned char c128[] = {
  B11111111,
  B10000001,
  B10010101,
  B10100001,
  B10100001,
  B10010101,
  B10000001,
  B11111111
};

const unsigned char c129[] = {
  B11111111,
  B10000001,
  B10100101,
  B10010001,
  B10010001,
  B10100101,
  B10000001,
  B11111111
};

const unsigned char c130[] = {
  B00111100,
  B01000010,
  B10010101,
  B10100001,
  B10100001,
  B10010101,
  B01000010,
  B00111100
};

const unsigned char c131[] = {

};

const unsigned char c132[] = {

};

const unsigned char c133[] = {

};

const unsigned char c134[] = {

};

const unsigned char c135[] = {

};

const unsigned char c136[] = {

};

const unsigned char c137[] = {

};

cosnt unsigned char c138[] = {

};

const unsigned char c139[] = {

};

const unsigned char c140[] = {

};

const unsigned char 141[] = {

};

const unsigned char 142[] = {

};

const unsigned char 143[] = {

};

const unsigned char 144[] = {
    
};

const unsigned char 145[] = {
    
};

const unsigned char 146[] = {
    
};

const unsigned char 147[] = {
    
};

const unsigned char 148[] = {
    
};

const unsigned char 149[] = {
    
};

const unsigned char 150[] = {
    
};

const unsigned char 151[] = {
    
};

const unsigned char 152[] = {
    
};

const unsigned char 153[] = {
    
};
const unsigned char 154[] = {
    
};
const unsigned char 155[] = {
    
};
const unsigned char 156[] = {
    
};
const unsigned char 157[] = {
    
};
const unsigned char 158[] = {
    
};
const unsigned char 159[] = {
    
};
const unsigned char 160[] = {
    
};
const unsigned char 161[] = {
    
};
const unsigned char 162[] = {
    
};
const unsigned char 163[] = {
    
};
const unsigned char 164[] = {
    
};
const unsigned char 165[] = {
    
};
const unsigned char 166[] = {
    
};
const unsigned char 167[] = {
    
};
const unsigned char 168[] = {
    
};
const unsigned char 169[] = {
    
};
const unsigned char 170[] = {
    
};
const unsigned char 171[] = {
    
};
const unsigned char 172[] = {
    
};
const unsigned char 173[] = {
    
};
const unsigned char 174[] = {
    
};
const unsigned char 175[] = {
    
};
const unsigned char 176[] = {
    
};
const unsigned char 177[] = {
    
};
const unsigned char 178[] = {
    
};
const unsigned char 179[] = {
    
};
const unsigned char 180[] = {
    
};
const unsigned char 181[] = {
    
};
const unsigned char 182[] = {
    
};
const unsigned char 183[] = {
    
};
const unsigned char 184[] = {
    
};
const unsigned char 185[] = {
    
};
const unsigned char 186[] = {
    
};
const unsigned char 187[] = {
    
};
const unsigned char 188[] = {
    
};
const unsigned char 189[] = {
    
};
const unsigned char 190[] = {
    
};
const unsigned char 191[] = {
    
};
const unsigned char 192[] = {
    
};
const unsigned char 193[] = {
    
};
const unsigned char 194[] = {
    
};
const unsigned char 195[] = {
    
};
const unsigned char 196[] = {
    
};
const unsigned char 197[] = {
    
};
const unsigned char 198[] = {
    
};
const unsigned char 199[] = {
    
};
const unsigned char 200[] = {
    
};
const unsigned char 201[] = {
    
};
const unsigned char 202[] = {
    
};
const unsigned char 203[] = {
    
};
const unsigned char 204[] = {
    
};
const unsigned char 205[] = {
    
};
const unsigned char 206[] = {
    
};
const unsigned char 207[] = {
    
};
const unsigned char 208[] = {
    
};
const unsigned char 209[] = {
    
};
const unsigned char 210[] = {
    
};
const unsigned char 211[] = {
    
};
const unsigned char 212[] = {
    
};
const unsigned char 213[] = {
    
};
const unsigned char 214[] = {
    
};
const unsigned char 215[] = {
    
};
const unsigned char 216[] = {
    
};
const unsigned char 217[] = {
    
};
const unsigned char 218[] = {
    
};
const unsigned char 219[] = {
    
};
const unsigned char 220[] = {
    
};
const unsigned char 221[] = {
    
};
const unsigned char 222[] = {
    
};
const unsigned char 223[] = {
    
};
const unsigned char 224[] = {
    
};
const unsigned char 225[] = {
    
};
const unsigned char 226[] = {
    
};
const unsigned char 227[] = {
    
};
const unsigned char 228[] = {
    
};
const unsigned char 229[] = {
    
};
const unsigned char 230[] = {
    
};
const unsigned char 231[] = {
    
};
const unsigned char 232[] = {
    
};
const unsigned char 233[] = {
    
};
const unsigned char 234[] = {
    
};
const unsigned char 235[] = {
    
};
const unsigned char 236[] = {
    
};
const unsigned char 237[] = {
    
};
const unsigned char 238[] = {
    
};
const unsigned char 239[] = {
    
};
const unsigned char 240[] = {
    
};
const unsigned char 241[] = {
    
};
const unsigned char 242[] = {
    
};
const unsigned char 243[] = {
    
};
const unsigned char 244[] = {
    
};
const unsigned char 245[] = {
    
};
const unsigned char 246[] = {
    
};
const unsigned char 247[] = {
    
};
const unsigned char 248[] = {
    
};
const unsigned char 249[] = {
    
};
const unsigned char 250[] = {
    
};
const unsigned char 251[] = {
    
};
const unsigned char 252[] = {
    
};
const unsigned char 253[] = {
    
};
const unsigned char 254[] = {
    
};
const unsigned char 255[] = {
    
};

#endif

typedef struct
{
    const unsigned char* character;
    const unsigned char size;
} Character;

const Character LETTERS[] = 
{
    CREATE_CHAR(33),
    CREATE_CHAR(34),
    CREATE_CHAR(35),
    CREATE_CHAR(36),
    CREATE_CHAR(37),
    CREATE_CHAR(38),
    CREATE_CHAR(39),
    CREATE_CHAR(40),
    CREATE_CHAR(41),
    CREATE_CHAR(42),
    CREATE_CHAR(43),
    CREATE_CHAR(44),
    CREATE_CHAR(45),
    CREATE_CHAR(46),
    CREATE_CHAR(47),
    CREATE_CHAR(48),
    CREATE_CHAR(49),
    CREATE_CHAR(50),
    CREATE_CHAR(51),
    CREATE_CHAR(52),
    CREATE_CHAR(53),
    CREATE_CHAR(54),
    CREATE_CHAR(55),
    CREATE_CHAR(56),
    CREATE_CHAR(57),
    CREATE_CHAR(58),
    CREATE_CHAR(59),
    CREATE_CHAR(60),
    CREATE_CHAR(61),
    CREATE_CHAR(62),
    CREATE_CHAR(63),
    CREATE_CHAR(64),
    CREATE_CHAR(65),
    CREATE_CHAR(66),
    CREATE_CHAR(67),
    CREATE_CHAR(68),
    CREATE_CHAR(69),
    CREATE_CHAR(70),
    CREATE_CHAR(71),
    CREATE_CHAR(72),
    CREATE_CHAR(73),
    CREATE_CHAR(74),
    CREATE_CHAR(75),
    CREATE_CHAR(76),
    CREATE_CHAR(77),
    CREATE_CHAR(78),
    CREATE_CHAR(79),
    CREATE_CHAR(80),
    CREATE_CHAR(81),
    CREATE_CHAR(82),
    CREATE_CHAR(83),
    CREATE_CHAR(84),
    CREATE_CHAR(85),
    CREATE_CHAR(86),
    CREATE_CHAR(87),
    CREATE_CHAR(88),
    CREATE_CHAR(89),
    CREATE_CHAR(90),
    CREATE_CHAR(91),
    CREATE_CHAR(92),
    CREATE_CHAR(93),
    CREATE_CHAR(94),
    CREATE_CHAR(95),
    CREATE_CHAR(96),
    CREATE_CHAR(97),
    CREATE_CHAR(98),
    CREATE_CHAR(99),
    CREATE_CHAR(100),
    CREATE_CHAR(101),
    CREATE_CHAR(102),
    CREATE_CHAR(103),
    CREATE_CHAR(104),
    CREATE_CHAR(105),
    CREATE_CHAR(106),
    CREATE_CHAR(107),
    CREATE_CHAR(108),
    CREATE_CHAR(109),
    CREATE_CHAR(110),
    CREATE_CHAR(111),
    CREATE_CHAR(112),
    CREATE_CHAR(113),
    CREATE_CHAR(114),
    CREATE_CHAR(115),
    CREATE_CHAR(116),
    CREATE_CHAR(117),
    CREATE_CHAR(118),
    CREATE_CHAR(119),
    CREATE_CHAR(120),
    CREATE_CHAR(121),
    CREATE_CHAR(122),
    CREATE_CHAR(123),
    CREATE_CHAR(124),
    CREATE_CHAR(125),
    CREATE_CHAR(126),
    CREATE_CHAR(127)
            
#if defined(EXTENDED_ASCII) || defined(EXTENDED_MATRIX)
    ,
    CREATE_CHAR(128),
    CREATE_CHAR(129),
    CREATE_CHAR(130),
    CREATE_CHAR(131),
    CREATE_CHAR(132),
    CREATE_CHAR(133),
    CREATE_CHAR(134),
    CREATE_CHAR(135),
    CREATE_CHAR(136),
    CREATE_CHAR(137),
    CREATE_CHAR(138),
    CREATE_CHAR(139),
    CREATE_CHAR(140),
    CREATE_CHAR(141),
    CREATE_CHAR(142),
    CREATE_CHAR(143),
    CREATE_CHAR(144),
    CREATE_CHAR(145),
    CREATE_CHAR(146),
    CREATE_CHAR(147),
    CREATE_CHAR(148),
    CREATE_CHAR(149),
    CREATE_CHAR(150),
    CREATE_CHAR(151),
    CREATE_CHAR(152),
    CREATE_CHAR(153),
    CREATE_CHAR(154),
    CREATE_CHAR(155),
    CREATE_CHAR(156),
    CREATE_CHAR(157),
    CREATE_CHAR(158),
    CREATE_CHAR(159),
    CREATE_CHAR(160),
    CREATE_CHAR(161),
    CREATE_CHAR(162),
    CREATE_CHAR(163),
    CREATE_CHAR(164),
    CREATE_CHAR(165),
    CREATE_CHAR(166),
    CREATE_CHAR(167),
    CREATE_CHAR(168),
    CREATE_CHAR(169),
    CREATE_CHAR(170),
    CREATE_CHAR(171),
    CREATE_CHAR(172),
    CREATE_CHAR(173),
    CREATE_CHAR(174),
    CREATE_CHAR(175),
    CREATE_CHAR(176),
    CREATE_CHAR(177),
    CREATE_CHAR(178),
    CREATE_CHAR(179),
    CREATE_CHAR(180),
    CREATE_CHAR(181),
    CREATE_CHAR(182),
    CREATE_CHAR(183),
    CREATE_CHAR(184),
    CREATE_CHAR(185),
    CREATE_CHAR(186),
    CREATE_CHAR(187),
    CREATE_CHAR(188),
    CREATE_CHAR(189),
    CREATE_CHAR(190),
    CREATE_CHAR(191),
    CREATE_CHAR(192),
    CREATE_CHAR(193),
    CREATE_CHAR(194),
    CREATE_CHAR(195),
    CREATE_CHAR(196),
    CREATE_CHAR(197),
    CREATE_CHAR(198),
    CREATE_CHAR(199),
    CREATE_CHAR(200),
    CREATE_CHAR(201),
    CREATE_CHAR(202),
    CREATE_CHAR(203),
    CREATE_CHAR(204),
    CREATE_CHAR(205),
    CREATE_CHAR(206),
    CREATE_CHAR(207),
    CREATE_CHAR(208),
    CREATE_CHAR(209),
    CREATE_CHAR(210),
    CREATE_CHAR(211),
    CREATE_CHAR(212),
    CREATE_CHAR(213),
    CREATE_CHAR(214),
    CREATE_CHAR(215),
    CREATE_CHAR(216),
    CREATE_CHAR(217),
    CREATE_CHAR(218),
    CREATE_CHAR(219),
    CREATE_CHAR(220),
    CREATE_CHAR(221),
    CREATE_CHAR(222),
    CREATE_CHAR(223),
    CREATE_CHAR(224),
    CREATE_CHAR(225),
    CREATE_CHAR(226),
    CREATE_CHAR(227),
    CREATE_CHAR(228),
    CREATE_CHAR(229),
    CREATE_CHAR(230),
    CREATE_CHAR(231),
    CREATE_CHAR(232),
    CREATE_CHAR(233),
    CREATE_CHAR(234),
    CREATE_CHAR(235),
    CREATE_CHAR(236),
    CREATE_CHAR(237),
    CREATE_CHAR(238),
    CREATE_CHAR(239),
    CREATE_CHAR(240),
    CREATE_CHAR(241),
    CREATE_CHAR(242),
    CREATE_CHAR(243),
    CREATE_CHAR(244),
    CREATE_CHAR(245),
    CREATE_CHAR(246),
    CREATE_CHAR(247),
    CREATE_CHAR(248),
    CREATE_CHAR(249),
    CREATE_CHAR(250),
    CREATE_CHAR(251),
    CREATE_CHAR(252),
    CREATE_CHAR(253),
    CREATE_CHAR(254),
    CREATE_CHAR(255)
      
#endif
};

#undef CREATE_CHAR

#endif	/* ASCIITOMATRIX_H */