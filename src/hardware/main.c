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

bool a = true;
void output(){
   if(a){
	      PORTD = 0b10100000;
      }else{
	      PORTD = 0b01000000;
      }
      a = !a;
}

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
    _delay_ms(118000);
    displayDCF();
    cli();
    sleep_cpu();
    return 0;
}
