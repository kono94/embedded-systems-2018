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
#include "../models/internClock/avrDatetime.h"

// Definiert den AVR-Typ fuer den Simulator.
AVR_MCU(F_CPU, "atmega32");

// Definiert die Simulatorausgabedatei und die Dauer der Simulation in
// Mikrosekunden.
AVR_MCU_VCD_FILE("interrupt-sim.vcd", 10000);

// Definiert die durch den Simulator auszugebenden Ports.
const struct avr_mmcu_vcd_trace_t _mytrace[] _MMCU_ = {
        { AVR_MCU_VCD_SYMBOL("PORT_D"), .what = (void*)&PORTD, },
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

// Interrupt subroutine for external interrupt 0
ISR(TIMER1_OVF_vect)
{
          output();
          TCNT1 = 49912;
}


void interrupt_timer(){
    //    cli(); // disable global interrupts

    TCNT1 = 49912;

    TCCR1A = 0x00;
    // 0b00001101
    TCCR1B = 0b00000101;

    TIMSK = 0b00000100;
    sei();                                //Enable globl Interrupts

    for(;;);

    // The main loop stays empty and
    // could contain code you want.

}
int main(int argc, char** argv){
    printf("kek");
    DCF_init();
    AvrDatetime_init();

    return 0;
}
