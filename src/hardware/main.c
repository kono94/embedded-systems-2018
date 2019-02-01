/*******************************************************************************
 * File main.c
 *
 * Entry point for the whole project.
 * Sets up ports, interrupts and has the main while-loop in it.
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

#include "../dcf/dcftype.h"
#include "../util/dateExtractor.h"
#include "../internClock/avrDatetime.h"
#include "../dcf/signalToDCF.h"
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
    PORTC = 0;

    //disable JTAG
    MCUCSR |= (1<<7);
    MCUCSR |= (1<<7);

    //disabling Two-wire Serial Bus Clock Line
    TWCR &= ~(1 << TWEN);

    GICR = 1<<INT0;					// Enable INT0
    MCUCR = 1<<ISC01 | 1<<ISC00;	// Trigger INT0 on rising edge
}
bool isDisplayOn = false;

ISR(INT0_vect)
{
 if(isDisplayOn){
     turnDisplayOff();
     isDisplayOn = false;
 }  else{
     turnDisplayOn();
     isDisplayOn = true;
 }
}

void startVisualizingOnDisplay(){
    display_row = 0;
    changeRowOnDisplayTo(display_row);
    setInstructionsForRow(display_row);
}

int main(int argc, char** argv){
    DCF_init();
    AvrDatetime_init();
    init_triggers();
    setupPorts();
    _delay_ms(1);

    resetDisplay();
    _delay_ms(1);

    turnDisplayOn();
    isDisplayOn = true;
    _delay_ms(1);

    sendEmptyDI();
    _delay_ms(1);

    clearDisplay();
    _delay_ms(100);

    setupInterrupts();

    while(true){
        if(trigger_evaluateSignal) {
            trigger_evaluateSignal = false;
            evaluateSignal(PIND & 1);
        }

        if(trigger_sentToDisplay){
            trigger_sentToDisplay = false;
            if(display_toSend > 0){
                sendWriteData(display_data[display_toSend_currentSession - display_toSend]);
                display_toSend--;
                if(display_toSend == 0){
                    // Load instructions into display_data for next row
                    if(setInstructionsForRow(++display_row)){
                        // change display row
                        changeRowOnDisplayTo(display_row);
                    }else{
                        // all information got printed to the display
                        // refreshing data on display finished for this "second"
                    }
                }
            }
        }

        if(trigger_oneSecondPassed){
            trigger_oneSecondPassed = false;
            // Skip incrementation of intern time if leap second added
            if(!leapSecondSkip){
                leapSecondSkip = false;
                incrementByOneSecond();
            }
            startVisualizingOnDisplay();
        }
    }
}

