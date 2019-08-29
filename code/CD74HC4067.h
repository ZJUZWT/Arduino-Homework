#ifndef CD74HC4067_H
#define CD74HC4067_H

#include "Arduino.h" 

const bool select[16][4] = {            
    {0, 0, 0, 0}, //channel 0
    {1, 0, 0, 0}, //channel 1
    {0, 1, 0, 0}, //channel 2
    {1, 1, 0, 0}, //channel 3
    {0, 0, 1, 0}, //channel 4
    {1, 0, 1, 0}, //channel 5
    {0, 1, 1, 0}, //channel 6
    {1, 1, 1, 0}, //channel 7
    {0, 0, 0, 1}, //channel 8
    {1, 0, 0, 1}, //channel 9
    {0, 1, 0, 1}, //channel 10
    {1, 1, 0, 1}, //channel 11
    {0, 0, 1, 1}, //channel 12
    {1, 0, 1, 1}, //channel 13
    {0, 1, 1, 1}, //channel 14
    {1, 1, 1, 1}  //channel 15
} ;

const int pinS[2][4] = { 12 , 11 , 10 , 8 , A5 , A4 , A3 , A2 } ;
const int pinSIG[2] = { 9 , A1  } ; 
const int pinEN[2] = { A0 , A0 } ;

void writeIn4067(int borad,int pos,int num) ;
void init4067() ;
void cancelIn4067(int borad) ;

#endif 
