//
// Created by Jan Uni on 09.01.19.
//

#include "oneMilliInterrupt.h"
#include "signalToDCF.h"
#include "../display/displayInstructions.h"


// Interrupt subroutine for external interrupt 0
ISR(TIMER0_OVF_vect)
{
    TCNT0 = 240;
    trigger_scanDCF_PIN = true;
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

void scanDCF_PIN(){

}

// gets called EVERY 1ms
void sendToDisplay(){
    if(display_toSend > 0){
        if(sending_phase == 0){
            // SET ENABLE TO 0 (LOWER)
            // SET DATA BITS
            // ADC = display_data[display_toSend_currentSession - display_toSend];
            sending_phase = 1;
        }else if(sending_phase == 1){
            // SET ENABLE TO HIGH (PULL UP, DATA WILL BE READ IN)
            display_toSend--;
            sending_phase = 0;
            if(display_toSend == 0){
                setInstructionsForRow(display_row++)
            }
        }
    }
}
