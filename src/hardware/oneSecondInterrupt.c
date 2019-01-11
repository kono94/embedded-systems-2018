//
// Created by Jan Uni on 09.01.19.
//

#include "oneSecondInterrupt.h"


// Interrupt throwing when intern timer should be incremented
ISR(TIMER1_OVF_vect)
{
    TCNT1 = 49912;
}

void enableOneSecInterrupt(){
    TCNT1 = 49912;
    TCCR1A = 0x00;
    // 0b00001101
    TCCR1B = 0b00000101;
    // enable timer1
    TIMSK |= 0b00000100;
}