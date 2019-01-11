/*******************************************************************************
 * File main.c
 *
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 14.11.18
 *******************************************************************************/

#include "main.h"
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

#include <avr/io.h>
#include <avr/avr_mcu_section.h>
#include <sim_vcd_file.h>


// Importiert die Stopp-Funktion, um den Simulator anzuhalten (sleep_cpu())
#include <avr/sleep.h>
// Importiert die Interrupt-Funktion, um den Simulator anzuhalten (ISR(), cli(), sei())
#include <avr/interrupt.h>

#include <util/delay.h>

#include "../DCF/dcftype.h"
#include "../util/dateExtractor.h"
#include "../internClock/avrDatetime.h"
#include "../DCF/signalToDCF.h"
#include "oneSecondInterrupt.h"
#include "../display/displayInstructions.c"
#include "../util/triggers.h"

// Definiert den AVR-Typ fuer den Simulator.
AVR_MCU(F_CPU, "atmega32");

// Definiert die Simulatorausgabedatei und die Dauer der Simulation in
// Mikrosekunden.
AVR_MCU_VCD_FILE("output.vcd", 121000);

// Definiert die durch den Simulator auszugebenden Ports.
const struct avr_mmcu_vcd_trace_t _mytrace[] _MMCU_ = {
        { AVR_MCU_VCD_SYMBOL("PORT_D"), .what = (void*)&PORTD, },
        { AVR_MCU_VCD_SYMBOL("PORT_A"), .what = (void*)&PORTA, },
        { AVR_MCU_VCD_SYMBOL("PIN_C"), .what = (void*)&PINC, },
        { AVR_MCU_VCD_SYMBOL("PORT_B"), .what = (void*)&PORTB, },
};



void setupInterrupts(){
    cli(); // disable global interrupts
    enableOneSecInterrupt();
    enableOneMilliInterrupt();
    sei(); //Enable global Interrupts
}

void displayDCF() {
    for (int i = 0; i < DCF_LENGTH; i++) {
        PORTA = i;
        PORTB = rawDCF[i];
        _delay_ms(10);
        PORTB = 0b00000000;
        PORTB = 0b00000001;
    }
}


int main(int argc, char** argv){
    DCF_init();
    AvrDatetime_init();
    setupInterrupts();
    init_sendToDisplay();
    init_triggers();

    while(true){
        if(trigger_SignalError){
            trigger_signalError = false;
            // draw SIGNAL ERROR
        }

        if(trigger_noSignalError){
            trigger_noSignalError = false;
            // clear SIGNAL ERROR
        }

        if(trigger_scanDCF_PIN) {
            trigger_scanDCF_PIN = false;
            evaluateSignal(PINC);
        }

        if(trigger_sentToDisplay){
            trigger_sentToDisplay = false;
            // gets called EVERY 1ms
            if(display_toSend > 0){
                if(sending_phase == 0){
                    // SET ENABLE TO 0 (LOWER)
                    setEnableBit(0);
                    // SET DATA BITS
                    setDataPins(display_data[display_toSend_currentSession - display_toSend]);
                    sending_phase = 1;
                }else if(sending_phase == 1){
                    // SET ENABLE TO HIGH (PULL UP, DATA WILL BE READ IN)
                    setEnableBit(1);
                    display_toSend--;
                    sending_phase = 0;
                    if(display_toSend == 0){
                        setInstructionsForRow(display_row++)
                    }
                }
            }
        }

        if(trigger_oneSecondPassed){
            trigger_oneSecondPassed = false;
            // TODO: count up second


            visualizeOnDisplay();
        }
    }
}
