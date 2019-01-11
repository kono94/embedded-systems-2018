/*******************************************************************************
 * File oneMilliInterrupt.c
 *
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#include "oneMilliInterrupt.h"
#include "../DCF/signalToDCF.h"
#include "../display/displayInstructions.h"
#include <avr/io.h>
#include <avr/interrupt.h>

// Interrupt subroutine for external interrupt 0
ISR(TIMER0_OVF_vect)
{
    TCNT0 = 240;
    trigger_evaluateSignal = true;
    trigger_sentToDisplay = true;
}


void enableOneMilliInterrupt(){
    TCNT0 = 240;
    // 1024 prescaler
    TCCR0 = 0b00000101;
    // enable timer0
    TIMSK |= 0b00000001;

    interruptCounter = 0;
    g_position = 0;
}
