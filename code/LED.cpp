#include "LED.h"
#include "HC595.h"
#include "Arduino.h"  
#include "CD74HC4067.h"

int pinRS = 12 ; 
int pinE = 7 ;
int vPinE[2] = { 0 , 5 } ; 
int vPinRS[2] = { 1 , 5 } ; 

void initScreen(byte base,byte Cursor) {//初始化屏幕
    
    pinMode( pinRS , OUTPUT ) ;
    pinMode( pinE  , OUTPUT ) ;
    
    cleanScreen() ;//清屏
    
    writeByte( base , false ) ;
    delay( 5 ) ;
    writeByte( base , false ) ;
    delay( 5 ) ;
    writeByte( base , false ) ;
    delay( 5 ) ;
    writeByte( base , false ) ;
    
    writeByte( 0x06 , false ) ; //设置显示模式
    delay( 10 ) ;
    writeByte( Cursor , false ) ;//根据函数变量改变光标属性
//    writeByte( 0x0d , false ) ;
    
    delay( 10 ) ;

}

void writeByte(byte b,boolean isData) {// PPT提供的字节写入方法
    if ( isData ) 
        digitalWrite( pinRS , HIGH ) ; 
//        writeIn4067( vPinRS[0] , vPinRS[1] , 255 ) ;
    else 
        digitalWrite( pinRS , LOW ) ;
//        writeIn4067( vPinRS[0] , vPinRS[1] , 0 ) ;

//    Serial.println( analogRead( 6 ) ) ;
        
//    byte mask = 0x01 ;
    byte mask = 0x01 << 7 ; 

    digitalWrite( pinPT[0] , LOW ) ;

//    Serial.println( b ) ;

    for ( int i = 0 ; i < 8 ; i++ ) {
        digitalWrite(pinHS[0] , LOW) ; 
        digitalWrite(pinData[0] , b&mask) ;
        digitalWrite(pinHS[0] , HIGH ) ;
        mask = mask >> 1 ; 
    }

    digitalWrite( pinPT[0] , HIGH ) ;
    
//    digitalWrite( pinPT , LOW ) ;
//    delayMicroseconds( 100 ) ;
//    shiftOut( pinData , pinHS , MSBFIRST , b ) ;
//    delayMicroseconds( 100 ) ;
//    digitalWrite( pinPT , HIGH ) ;
//    delayMicroseconds( 100 ) ;

    digitalWrite( pinE , HIGH ) ;
//    writeIn4067( vPinE[0] , vPinE[1] , 255 ) ;
    delayMicroseconds( 1 ) ;
    digitalWrite( pinE , LOW ) ;
//    writeIn4067( vPinE[0] , vPinE[1] , 0 ) ;
    delayMicroseconds( 1 ) ; 
}

void printScreen(char* s) { //在屏幕上显示一串字
//    cleanScreen() ;
    int num = 0 ;
    while ( *s != '\0' ) {
        if ( num == 16 ) toLine(2) ;
//        Serial.println( *s ) ;
        writeByte( *s , true ) ;
        s++ ; num++ ;
    }
}

void printScreenOneLine(char* s,int line,bool isLoop,bool isDelay,int delayTime) { //只显示在某一行上
    toLine( line ) ;
    int num = 0 ;
    while ( *s != '\0' ) {
        writeByte( (byte) *s , true ) ;
        s++ ;
        num++ ; 
        if ( num >= Length ) return ;
        if ( isDelay ) delay( delayTime ) ; 
    }
}

void cleanScreen() {//清屏
    writeByte( CLEAN , false ) ;
}

void offScreen() {//关闭屏幕
    writeByte( OFF_SCREEN , false ) ;
//    cleanScreen() ; //关闭屏幕并不会清屏！！！！
}

void onScreen(byte Cursor) {//开启屏幕
    switch ( Cursor ) {
        case 0 : 
            writeByte( CURSOR_OFF , false ) ;
            break ; 
        case 1 :
            writeByte( CURSOR_ON , false ) ;
            break ;
        case 2 : 
            writeByte( CURSOR_BLINK , false ) ;
            break ;
    }
}

void toLine(int line) {//转到第line行行首
    switch( line ) {
        case 1 : 
            writeByte( Line1 , false ) ;
            break ;
        case 2 : 
            writeByte( Line2 , false ) ;
            break ;
    }
}

void moveCursor(int mode) {//移动光标
    switch( mode ) {
        case MOVE_LEFT:
            writeByte( 0x08 , false ) ;
            break ;
        case MOVE_RIGHT:
            writeByte( 0x0C , false ) ;
            break ;
        case MOVE_RESET:
            writeByte( 0x02 , false ) ;
            break ;
    }
}
