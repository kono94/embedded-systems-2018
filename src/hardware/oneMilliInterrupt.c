//
// Created by Jan Uni on 09.01.19.
//

#include "oneMilliInterrupt.h"
#include "signalToDCF.h"
#include "sendToDisplay.h"


// Interrupt subroutine for external interrupt 0
ISR(TIMER0_OVF_vect)
{
    TCNT0 = 240;
    scanDCF();
    sendToDisplay();
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
