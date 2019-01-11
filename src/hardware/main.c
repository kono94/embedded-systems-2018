//
// Created by Jan Uni on 14.11.18.
//
#include "main.h"
#include <stdio.h>
#include <inttypes.h>

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
#include "./signalToDCF.h"
#include "oneSecondInterrupt.h"
#include "../display/displayInstructions.c"

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


bool trigger_sentToDisplay = false;
bool trigger_scanDCF_PIN = false;

int main(int argc, char** argv){
    DCF_init();
    AvrDatetime_init();
    setupInterrupts();
    init_sendToDisplay();
    _delay_ms(118000);
    displayDCF();
    while(true){
        if(trigger_scanDCF_PIN) {
            trigger_scanDCF_PIN = false;
        }

        if(trigger_sentToDisplay){
            trigger_sentToDisplay = false;
        }


        cli();
        sleep_cpu();
        return 0;
    }
}
