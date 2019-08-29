#include "HC595.h"
#include "CD74HC4067.h"
#include "Arduino.h"

void writeIn595(int borad,bool w[]) {
    digitalWrite( pinPT[borad] , LOW ) ;
    for ( int i = 0 ; i < 8 ; i++ ) {
        digitalWrite( pinHS[borad] , LOW ) ;
        digitalWrite( pinData[borad] , w[i] ) ; 
        digitalWrite( pinHS[borad] , HIGH ) ; 
//        Serial.println( w[i] ) ;
    }
    digitalWrite( pinPT[borad] , HIGH ) ;
}

void writeIn595(int borad,byte b) {
    bool w[8] ; 
    for ( int i = 0 ; i < 8 ; i++ ) { 
        w[i] = b%2 ;
        b >>= 1 ;
    }
    writeIn595( borad , w ) ; 
}

void init595() {
    for ( int i = 0 ; i < 2 ; i++ ) {
        pinMode( pinPT[i] , OUTPUT ) ;
        pinMode( pinData[i] , OUTPUT ) ;
        pinMode( pinHS[i] , OUTPUT ) ;
    }
}
