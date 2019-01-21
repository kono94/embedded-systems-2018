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
#include "oneMilliInterrupt.h"
#include "../display/displayInstructions.h"
#include "../util/triggers.h"
#include "sendToDisplay.h"


// Definiert den AVR-Typ fuer den Simulator.
AVR_MCU(F_CPU, "atmega32");

// Definiert die Simulatorausgabedatei und die Dauer der Simulation in
// Mikrosekunden.
AVR_MCU_VCD_FILE("output.vcd", 10000);

// Definiert die durch den Simulator auszugebenden Ports.
const struct avr_mmcu_vcd_trace_t _mytrace[] _MMCU_ = {
        { AVR_MCU_VCD_SYMBOL("PORT_D"), .what = (void*)&PORTD, },
        { AVR_MCU_VCD_SYMBOL("PORT_A"), .what = (void*)&PORTA, },
        { AVR_MCU_VCD_SYMBOL("PORT_C"), .what = (void*)&PORTC, },
        { AVR_MCU_VCD_SYMBOL("PIN_C"), .what = (void*)&PINC, },
        { AVR_MCU_VCD_SYMBOL("PORT_B"), .what = (void*)&PORTB, },
};



void setupInterrupts(){
    cli(); // disable global interrupts
    enableOneSecInterrupt();
    enableOneMilliInterrupt();
    sei(); //Enable global Interrupts
}

void setupPorts(){
    // use LED
    DDRD = 0x50;

    // Mark all PORTA pins as output
    DDRA = 0b11111111;

    // Mark all PORTC pins as output
    DDRC = 0b11111111;

    PORTA = 0;
    PORTB = 0;

    //disable JTAG
    MCUCSR |= (1<<7);
    MCUCSR |= (1<<7);

    //disabling Two-wire Serial Bus Clock Line
    TWCR &= ~(1 << TWEN);
}
int main(int argc, char** argv){
    DCF_init();
    AvrDatetime_init();
    init_triggers();
    setupPorts();
    _delay_ms(1);

    p_avrDatetime->hours = 23;
    p_avrDatetime->minutes = 55;
    p_avrDatetime->seconds = 50;

    p_avrDatetime->days = 31;
    p_avrDatetime->months = 12;
    p_avrDatetime->years_hundreds = 20;
    p_avrDatetime->years_tens = 18;

    p_avrDatetime->weekdayIndex = 1;

    resetDisplay();
    _delay_ms(1);
    turnDisplayOn();
    _delay_ms(1);
    sendEmptyDI();

    setupInterrupts();

    while(1){
        sendInstructionData(0b10111011);
        sendWriteData(0b11000101);
    }
    bool lightOn = false;

    while(true){
        if(trigger_signalError){
            trigger_signalError = false;
            // draw SIGNAL-ERROR
        }

        if(trigger_noSignalError){
            trigger_noSignalError = false;
            // clear SIGNAL-ERROR
        }

        if(trigger_evaluateSignal) {
            trigger_evaluateSignal = false;
           // evaluateSignal(PINC);
        }

        if(trigger_sentToDisplay){
            trigger_sentToDisplay = false;
            if(display_toSend > 0){
                sendWriteData(display_data[display_toSend_currentSession - display_toSend]);
                display_toSend--;
                if(display_toSend == 0){
                    // next row
                    setInstructionsForRow(++display_row);
                    changeRowOnDisplayTo(display_row);
                }
            }
        }

        if(trigger_oneSecondPassed){
            trigger_oneSecondPassed = false;
            if(lightOn){
                PORTD |= (1<<5);
                lightOn = false;
            }else{
                PORTD &= ~(1<<5);
                lightOn = true;
            }
            incrementByOneSecond();
            visualizeOnDisplay();
        }
    }
}
