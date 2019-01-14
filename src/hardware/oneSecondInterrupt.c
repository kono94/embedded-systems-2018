/*******************************************************************************
 * File oneSecondInterrupt.c
 *
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#include "oneSecondInterrupt.h"
#include "../util/triggers.h"
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>


// Interrupt throwing when intern timer should be incremented
ISR(TIMER1_OVF_vect)
{
    TCNT1 = 49912;
    trigger_oneSecondPassed = true;
}

void enableOneSecInterrupt(){
    TCNT1 = 49912;
    TCCR1A = 0x00;
    // 0b00001101
    TCCR1B = 0b00000101;
    // enable timer1
    TIMSK |= 0b00000100;
}