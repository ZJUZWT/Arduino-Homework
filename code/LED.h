#ifndef _LED_H__
#define _LED_H__

#include"Arduino.h"  

const byte CLEAN = 0x01 ; 

#define MOVE_LEFT 0 
#define MOVE_RIGHT 1 
#define MOVE_RESET 2 
const byte OFF_SCREEN = 0x08 ;
const byte CURSOR_OFF = 0x0C ;  
const byte CURSOR_ON = 0x0E ; 
const byte CURSOR_BLINK = 0x0D ; 

const byte BASE = 0x38 ;

const byte Line1 = 0x80 ;
const byte Line2 = 0xC0 ;

const int Length = 40 ;

void initScreen(byte base,byte Cursor) ;
void writeByte(byte b,boolean isData) ;
void writeByte(bool w[],boolean isData) ;
void printScreen(char *s) ;
void cleanScreen() ;
void onScreen(byte Cursor) ;
void offScreen() ;
void toLine(int line) ;
void printScreenOneLine(char* s,int line,bool isLoop,bool isDelay,int delayTime) ;

#endif
