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
#include <util/delay.h>

/*
 * Pin Layout:
 * Using all PORTA pins as output for data bits;
 *
 * Using PORTC for other instructions:
 *
 * () = Index of pin on the self made port, from right to left, starting at 1
 * PC0 = R/W Input   (3)
 * PC1 = D/I Data Read  (4)
 * PC2 = Enable (5)
 * PC3 = Chip Select IC1    (15)
 * PC4 = Chip Select IC2    (16)
 * PC5 = Reset   (17)
 */
void wasteTime(uint8_t c){
    uint8_t tmp = 0;
    for(int i=0; i < c; i++){
        tmp++;
    }
}

void clockCycle(){
    // set Enable Bit to 1 (pull high)
    PORTC |= (1 << PC2);
    // wait a bit
    _delay_us(10);
    // set enable bit to 0 (pull down)
    PORTC &= ~(1 << PC2);
}

void setInstructionMode(){
    // setting R/W to 0 and D/I to 0
    PORTC &= ~(1 << PC0 | 1 << PC1);
}

void setWriteMode(){
    // setting R/W to 0 and D/I to 1 AND Chip select 1
    PORTC &= ~(1 << PC0);
    PORTC |= (1 << PC1 | 1 << PC3);
}

void setStatusReadMode(){
    // setting R/W to 1 and D/I to 0
    PORTC |= (1 << PC0);
    PORTC &= ~(1 << PC1);
}

void sendWriteData(uint8_t data){
    setWriteMode();
    setDataPins(data);
    clockCycle();
}


void sendInstructionData(uint8_t instructionData){
    setInstructionMode();
    setDataPins(instructionData);
    clockCycle();
}

void setDataPins(uint8_t data){
    PORTA = data;
}

void turnDisplayOn(){
    sendInstructionData(0b00111111);
}

void turnDisplayOff(){
    sendInstructionData(0b00111110);
}

void changeRowOnDisplayTo(uint8_t x){
    sendInstructionData(0b10111000 | (x & 0b111));
}

void resetDisplay(){
    // setting DB4 to 0 (reset low)
    PORTA &= ~(1 << PA4);
    _delay_us(500);
    PORTA |= (1 << PA4);
    _delay_us(500);
    PORTA &= ~(1 << PA4);
    _delay_us(500);
    PORTA |= (1 << PA4);
}

void sendEmptyDI(){
    setInstructionMode();
    setDataPins(0b00000000);
    clockCycle();
}