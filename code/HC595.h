#ifndef HC595_H 
#define HC595_H

#include "Arduino.h" 

const int pinData[2] = { 4 , 8 } ;
const int pinPT[2] = { 3 , 9 } ; 
const int pinHS[2] = { 2 , 10 } ; 

void writeIn595(int borad,bool w[]) ;
void writeIn595(int borad,byte b) ;
void init595() ;

#endif 
