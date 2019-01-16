/*******************************************************************************
 * File sendToDisplay.c
 *
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/


#include "sendToDisplay.h"
#include <inttypes.h>
#include <avr/io.h>
#include <stdbool.h>
/*
 * Pin Layout:
 * Using all PORTA pins as output for data bits;
 *
 * Using PORTB for other instructions:
 *
 * () = Index of pin on the self made port, from right to left, starting at 1
 * PB0 = R/W Input   (3)
 * PB1 = D/I Data Read  (4)
 * PB2 = Enable (5)
 * PB3 = Chip Select IC1    (15)
 * PB4 = Chip Select IC2    (16)
 * PB5 = Rest   (17)
 *
 */

void init_sendToDisplay(){
    instructionNextClock = false;
    instructionData = 0b00000000;
}

void setEnableBit(uint8_t enableBit){
    // SET Enable bit
    if(enableBit == 0){
        PORTB &= ~(1 << PB2);
    }else{
        PORTB |= (1 << PB2);
    }
}

void setInstructionMode(){
    // setting R/W to 0 and D/I to 0
    PORTB &= ~(1 << PB0 | 1 << PB1);
}

void setWriteMode(){
    // setting R/W to 0 and D/I to 1
    PORTB &= ~(1 << PB0);
    PORTB |= (1 << PB1);
}

void setDataPins(uint8_t data){
    PORTA = data;
}

void turnDisplayOn(){
    setEnableBit(0);
    wasteTime(30);
    setInstructionMode();
    setDataPins(0b11111111);
    wasteTime(30);
    setEnableBit(1);
}

void turnDisplayOff(){
    setEnableBit(0);
    wasteTime(30);
    setInstructionMode();
    setDataPins(0b11111110);
    wasteTime(30);
    setEnableBit(1);
}

void wasteTime(uint8_t c){
    uint8_t tmp = 0;
    for(int i=0; i < c; i++){
        tmp++;
    }
}


void changeRowOnDisplayTo(uint8_t x){
    instructionData = 0b10111000 | (x & 0b111);
    instructionNextClock = true;
}