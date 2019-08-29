#include "CD74HC4067.h"
#include "Arduino.h"

void init4067() {
    for ( int i = 0 ; i < 4 ; i++ ) 
        for ( int j = 0 ; j < 2 ; j++ ) pinMode( pinS[j][i] , OUTPUT ) ; 
}

void writeIn4067( int borad , int pos , int num ) {
    digitalWrite( pinEN[borad] , LOW ) ;
    for ( int i = 0 ; i < 4 ; i++ ) {
        digitalWrite( pinS[borad][i] , select[pos][i] ) ; 
    }
//    analogWrite( pinSIG[borad] , num ) ;
}

void cancelIn4067(int borad) {
    digitalWrite( pinEN[borad] , LOW ) ;
}
