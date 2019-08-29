#include <Servo.h>

#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

Servo myServo ;

#include <Key.h>
#include <Keypad.h>

#include "HC595.h"
#include "LED.h" 
#include "CD74HC4067.h"

#define dwt digitalWrite
#define drd digitalRead 
#define ard analogRead
#define awt analogWrite
#define ulg unsigned long

void (*reset) (void) = 0 ;

const int pinPowerLED = 13 ;
const int pinSwitch = A0 ;

const int pinPulse = 11 ; 

int RECV_PIN = 5 ;
IRrecv irrecv(RECV_PIN);
decode_results results;

bool flag = false ; 

void setup() {
    Serial.begin( 9600 ) ;
    pinMode( pinPowerLED , OUTPUT ) ;
    dwt( pinPowerLED , HIGH ) ;

//    myServo.attach( 5 ) ;
            
    init595() ;
    init4067() ;
    initScreen( BASE , CURSOR_OFF ) ;
    irrecv.enableIRIn() ; 
    initGame() ;

//    for ( int k = 0 ; k < 2 ; k++ ) {
//        for ( int i = 0 ; i < 8 ; i++ ) { 
//            rush( i , 90 ) ;
//            delay( 1000 ) ;
//        }
//    }
//    rush( 0 , 90 ) ;

//    writeIn4067( 11 , 255 ) ; 

//    s.attach( 3 ) ;
//    s.write( 90 ) ;
//    analogWrite( 3 , 18 ) ;
    
//    analogWrite( 6 , 128 ) ;
//    pinMode( 6 , OUTPUT ) ;  

//    writeIn4067( 1 , 15 , 255 ) ;
//    writeIn4067( 0 , 5 , 255 ) ; 
//    writeIn4067( 1 , 5 , 1023 ) ;
}

unsigned long lastTime = 0 ; 
unsigned long Limit = 20 ; 
//bool flag = false ;
bool flag2 = false ;

double low = 0 , high = 0 ;

void rush(int num , int angle) {
    int width = angle*11 + 500 ; 

//    for ( int i = 0 ; i < 4 ; i++ ) dwt( pinPowerSG[i] , LOW ) ;
//    dwt( pinPowerSG[(num-1)/2] , HIGH ) ; 
    
    writeIn595( 1 , 128 >> num ) ; 

//    writeIn4067( 1 , 15-num , 255 ) ; 
    
//    analogWrite( pinPulse , 255 ) ; 
//    writeIn595( 1 , 0xFFFF ) ; 
//    digitalWrite( 11 , HIGH ) ;`
    delayMicroseconds( width ) ; 
//    writeIn4067( 1 , 15-num , 0 ) ;
//    analogWrite( pinPulse , 0   ) ;
    writeIn595( 1 , (byte)0 ) ;  
//    digitalWrite( 11 , LOW ) ;  
    delayMicroseconds( 50000 ) ;  

//    writeIn4067( 1 , 15-num , 255 ) ;
//    writeIn4067( 0 , 15-num , 128 ) ; 
//    delayMicroseconds( width ) ; 
//    writeIn4067( 0 , 15-num , 0 ) ;
//    delayMicroseconds( 50000 ) ; 
}

void loop() {
//    if ( ard(pinSwitch) < 500 ) {
//        flag = false ; flag2 = false ;
//    }
//    if ( ard(pinSwitch) > 500 && !flag && !flag2 ) {
//        lastTime = millis() ; flag = true ; flag2 = false ;
//    }
//    if ( ard(pinSwitch) > 500 && flag && !flag2 && millis()-lastTime >= Limit ) {
//        flag = false ; flag2 = true ; switchGame() ;
//    }

//    int num = analogRead( A0 ) , num2 = analogRead( A1 ) ; 
//    Serial.print( num );
//    Serial.print( ' ' );
//    Serial.println( num2 ) ;
//    delay( 20 ) ;
 
//    for ( int i = 15 ; i <= 90 ; i++ ) { 
//        myServo.write( i ) ;
//        delay( 15 ) ;
//    }
//    for ( int i = 90 ; i >= 15 ; i-- ) { 
//        myServo.write( i ) ;
//        delay( 15 ) ;
//    }

//    if ( irrecv.decode(&results) ) {
//        char key = getChar( results.value ) ; 
//
//        Serial.println( key ) ;
//
//        if ( key != 'X' ) {
//            Serial.println( "Start" ) ;
//            myServo.write( 20 ) ;
//            delay( 1000 ) ;
//            myServo.write( 90 ) ;
//        }
//                    
//        irrecv.resume();
//    }
    
//    myServo.write( 0 ) ;
//    delay( 200 ) ;
//    myServo.write( 90 ) ;
 
//    for ( int i = 11 ; i < 16 ; i++ ) {
//        writeIn4067( i , 1023 ) ;
//        delay( 200 ) ; 
////        writeIn4067( i , 0 ) ;  
//    }

//    for ( int i = 10 ; i < 170 ; i+=20 ) {
//        analogWrite( 6 , i*1023/180 ) ;
//        delay( 200 ) ; 
//    }
//    for ( int i = 170 ; i >= 10 ; i-=20 ) {
//        analogWrite( 6 , i*1023/180 ) ;
//        delay( 200 ) ; 
//    }

//    int now = analogRead( A0 ) ; 
//    if ( now <= 256 ) low++ ; else high++ ; 
//    Serial.println( high/(high+low) ) ; 
//    delay( 20 ) ; 

//    Serial.println( now ) ;
//    rush( 45 ) ;  

//    for ( int j = 0 ; j < 5 ; j++ ) 
//        for ( int i = 1 ; i <= 50 ; i++ ) rush( j , 90 ) ;
//    delay( 1000 ) ; 
//    for ( int j = 0 ; j < 5 ; j++ ) 
//        for ( int i = 1 ; i <= 50 ; i++ ) rush( j, 0 ) ;

//    writeIn4067( 1 , 15 , 255 ) ;

//    rush( 1 , 90 ) ;
    
//    Serial.println( analogRead( A0 ) ) ;

//    }

//    dwt( pinPowerSG[0] , flag ) ; flag ^= 1 ;

    for ( int i = 0 ; i < 8 ; i++ ) {
        for ( int j = 0 ; j < 1 ; j++ ) {
            rush( i , 15 ) ;    
            delay( 1000 ) ;    
            rush( i , 90 ) ; 
            delay( 1000 ) ;
        }
    }

//    Serial.println( analogRead( A0 ) ) ;
     
}

void initGame() {

    for ( int i = 0 ; i < 8 ; i++ )
        for ( int j = 0 ; j < 8 ; j++ ) {
            rush( i , 90 ) ;
            delay( 20 ) ; 
        }
        
    char ch ; 
    printScreenOneLine( "   Welcome to   " , 1 , false , true , 100 ) ; 
    ulg lastTime = millis() ;
    printScreenOneLine( "  Whac-A-Mole!  " , 2 , false , true , 100 ) ; 
    ulg nowTime = millis() ;
    bool showNum = 0 ;
        
    while ( 1 ) {  
        if ( irrecv.decode(&results) ) {
            ch = getChar( results.value ) ;
            Serial.println( ch ) ;
            if ( ch == '1' ) break ;
            irrecv.resume() ; 
        }
        nowTime = millis() ;
        if ( nowTime - lastTime > 3000 ) {
            if ( showNum ) { 
                printScreenOneLine( "  Press '1' to  " , 1 , false , true , 10 ) ; 
                printScreenOneLine( "  Get  Started  " , 2 , false , true , 10 ) ; 
            } else { 
                printScreenOneLine( "   Welcome to   " , 1 , false , true , 10 ) ; 
                printScreenOneLine( "  Whac-A-Mole!  " , 2 , false , true , 10 ) ;
            }
            lastTime = nowTime ; showNum ^= 1 ;
        }
    }

    irrecv.resume() ; 
    selectModeGame() ;
}

ulg timeInterval2 = 1000 ;

void selectModeGame() { 
    char key ;
    char s[60] = " 1.Single 2.Double 0.Back 1.Single 2.Double 0.Back" ;
    
    printScreenOneLine( "   Play  Mode   " , 1 , false , false , 0 ) ;
    printScreenOneLine( s , 2 , false , false , 0 ) ;
            
    ulg lastTime = millis() ; 
    ulg nowTime = millis() ;
    int num = 0 ;
    
    while ( 1 ) {

        if ( irrecv.decode(&results) ) { 
            key = getChar( results.value ) ;
            if ( key == '1' || key == '2' || key == '0' ) {
                break ; 
            }
            irrecv.resume() ;
        }

        nowTime = millis() ;
        if ( nowTime - lastTime > timeInterval2 ) {
            lastTime = nowTime ; num = ( num + 2 ) % 26 ; 
            printScreenOneLine( s+num , 2 , false , false , 0 ) ;
        }
    
    }    
    
    irrecv.resume() ;
    switch( key ) {
        case '1' : 
            selectDifGame() ; 
            break ; 
        case '2' :
            readyGame(1) ;
            break ; 
        case '0' :
            initGame() ;
            break ;
    }
}

//int TimeHard = 1000 ; 
//int TimeEazy = 5000 ; 
//int TimeNormal = 3000 ;
int TimeDif[3] = { 1000 , 3000 , 5000 } ;  
int timeInterval = 0 ; 

void selectDifGame() {
    char key ;
    printScreenOneLine( "   Difficulty   " , 1 , false , true , 10 ) ;
    char s[80] = " 1.Eszy 2.Normal 3.Hard 0.Back 1.Eszy 2.Normal 3.Hard 0.Back" ;
    printScreenOneLine( s , 2 , false , true , 10 ) ;

    ulg lastTime = millis() ; 
    ulg nowTime = millis() ;
    int num = 0 ;
    
    while ( 1 ) {

        if ( irrecv.decode(&results) ) {   
            key = getChar(results.value) ; 
            if ( key == '0' || key == '1' || key == '2' || key == '3' ) {
                break ;   
            }
            irrecv.resume() ;
        }
        nowTime = millis() ;
        if ( nowTime - lastTime > timeInterval2 ) {
            lastTime = nowTime ; num = ( num + 2 ) % 26 ; 
            printScreenOneLine( s+num , 2 , false , false , 0 ) ;
        }
        
    }

    irrecv.resume() ;
    switch( key ) {
        case '1' : 
            setDifGame( 0 ) ; 
            break ; 
        case '2' :
            setDifGame( 1 ) ; 
            break ;
        case '3' :
            setDifGame( 2 ) ;         
            break ; 
        case '0' : 
            initGame() ;
            break ; 
    }
}

void readyGame(int mode) { // 0 single 1 double 
    char key ;
    printScreenOneLine( " Are You Ready? " , 1 , false , false , 0 ) ; 
    
    char s[60] = " 1:Play  0:Back " ;
    printScreenOneLine( s , 2 , false , false , 0 ) ; 
   
    while ( 1 ) {
        if ( irrecv.decode(&results) ) { 
            key = getChar( results.value ) ; 
            if ( key == '1' || key == '0' ) 
                break ;
            irrecv.resume() ;
        }
    }
    irrecv.resume() ;
    switch( key ) {
        case '1' :
            startGame(mode) ;
            break ;
        case '0' :
            initGame() ;
            break ;
    }
}

void setDifGame(int dif) {
    timeInterval = TimeDif[dif] ; 
    readyGame( 0 ) ;
}

int gamePin = 5 ;

void startGame(int mode) {
  
    ulg num = 0 ; 
    printScreenOneLine( "      Mode:     " , 1 , false , false , 0 ) ;
    printScreenOneLine( "     SINGLE     " , 2 , false , false , 0 ) ;

//    myServo.attach( gamePin ) ;

    randomSeed(analogRead(0));
    if ( !mode ) {
        while ( 1 ) {
            int k = random( 8 ) ;
            rush( k , 30 ) ; 
            delay(500) ; 
            rush( k , 90 ) ;
            delay(timeInterval) ; 

            if ( irrecv.decode(&results) ) {
                char key = getChar( results.value ) ; 
                if ( key == 'E' ) break ;
                irrecv.resume() ; 
            }
        
        }
    } else {
        printScreenOneLine( "     DOUBLE     " , 2 , false , false , 0 ) ;      
//
//        Serial.println( "Get into the right page!" ) ;
        
        while ( 1 ) {
            if ( irrecv.decode(&results) ) {
                char key = getChar( results.value ) ; 
                if ( key <= '7' && key >= '0' ) {
                    int k = key - '0' ;  
                    rush( k , 30 ) ; 
                    delay(500) ; 
                    rush( k , 90 ) ;
                }

            if ( key == 'E' ) break ; 
//              MoleJump( getNumber(result.value) ) ;

                irrecv.resume() ; 
            }
        }
    }
    initGame() ; 
}
    
char getChar(ulg number) {    
    switch( number ) {
        case 0xFF6897 : 
            return '0' ; 
        case 0xFF30CF :
            return '1' ; 
        case 0xFF18E7 :
            return '2' ; 
        case 0xFF7A85 :
            return '3' ; 
        case 0xFF10EF : 
            return '4' ; 
        case 0xFF38C7 : 
            return '5' ; 
        case 0xFF5AA5 : 
            return '6' ; 
        case 0xFF42BD :
            return '7' ; 
        case 0xFF4AB5 :
            return '8' ; 
        case 0xFF52AD : 
            return '9' ;
        case 0xFFA25D : 
            return 'E' ;
        default : 
            return 'X' ; 
    }
}
