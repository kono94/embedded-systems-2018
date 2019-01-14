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
void setEnableBit(uint8_t enableBit){
    // SET Enable bit
}

void setDataPins(uint8_t data){
    // setting R/W to 0 and D/I to 1
    PORTB &= ~(1 << PB0);
    PORTB |= (1 << PB1);
    PORTA = data;
}

void turnDisplayOn(){
    // setting R/W and D/I to 0 for instructions
    PORTB &= ~(1<<PB0 | 1<<PB1);
    PORTA = 0b11111111;
}

void turnDisplayOff(){
    // setting R/W and D/I to 0 for instructions
    PORTB &= ~(1<<PB0 | 1<<PB1);
    PORTA = 0b11111110;
}

