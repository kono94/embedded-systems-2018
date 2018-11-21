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

#include "DCF/dcftype.h"
#include "util/dateExtractor.h"

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
uint8_t b = 0;
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
      if(b == 0){
          output();
          TCNT1 = 63974;
      }
}

int main(int argc, char** argv){


    
  //  DCF_init();
//    cli(); // disable global interrupts
    
    // General Interrupt Control Registeri (for external interrupts i.e. buttons)
    // GICR = 0b01000000;
    
    /*
     * Considering this for DCF-77 Receiver!
     * ADCSRA = ADC Control and Status Register A
     *
     * Bit 7 - ADEN: ADC Enable
     * Setting this bit to one enables the ADC.
     *
     * Bit 3 - ADIE: ADC Interrupt Enable
     * When this bit is written to one and the 1-bit in SREG is set, the ADC Conversion Complete
     * Interrupt is actived.
     *
     * Bit 2:0 - ADPS2:0: ADC Prescaler Select Bits
     * These bits determine the division factor between the XTAL frequency and the input clockl to the ADC
     * 0 0 0 = 2
     * 0 0 1 = 2
     * 0 1 0 = 4
     * 0 1 1 = 8
     * 1 0 0 = 16
     * 1 0 1 = 32
     * 1 1 0 = 64
     * 1 1 1 = 128
     */
    // ADCSR = 0b10000111;

    /*
     * Waveform Genetator Mode
     * TCCR1A - Bit 0 = WGM10
     * 		Bit 1 = WGM11
     *
     * TCCR1B - Bit 4 = WGM13
     * 		Bit 3 = WGM12
     * 		Bit 0 = CS10
     * 		Bit 1 = CS11
     * 		Bit 2 = CS12
     *
     * WGM 0100:
     * Timer/Counter Mode of Operation = CTC
     * Top = OCR1A
     * Update of OCR1x = Immediate
     * TOV1 Flag Set on = MAX
     *
     * CS10, 11, 12 = Clock Select - Prescaler
     * The three Clock Select bits select the clock source to be used by the Timer/Counter
     * 0 0 1 = No pescaling
     * 0 1 0 = /8 (From prescaler)
     * 0 1 1 = /64
     * 1 0 0 = /256
     * 1 0 1 = /1024
     * 1 1 0 = External clock source on T1 pin. Clock on failing edge.
     */

    TCNT1 = 15625;

    TCCR1A = 0x00;
    // 0b00001101
    TCCR1B = 0b00000101;

    TIMSK = 0b00000100;
    sei();                                //Enable globl Interrupts

    for(;;);

   // The main loop stays empty and
   // could contain code you want.

    return 0;
}
