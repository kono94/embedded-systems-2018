/*******************************************************************************
 * File oneMilliInterrupt.c
 *
 * Sets up the one ms timer/ interrupt.
 * Also handles the corresponding interrupt vector
 * which will eventually trigger the evaluation routine
 * and the routine to send data or instructions to the display
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#include "oneMilliInterrupt.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include "../dcf/signalToDCF.h"
#include "../display/displayInstructions.h"
#include "../util/triggers.h"

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

    g_position = 0;
}
