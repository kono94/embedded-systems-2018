//
// Created by Jan Uni on 14.11.18.
//
#include <stdio.h>
#include <avr/io.h>
#include <stdint.h>
#include <avr/avr_mcu_section.h>

// Imports fuer den Simulator.
#include <sim_vcd_file.h>

// Importiert die Stopp-Funktion, um den Simulator anzuhalten (sleep_cpu())
#include <avr/sleep.h>

// Importiert die Interrupt-Funktion, um den Simulator anzuhalten (ISR())
#include <avr/interrupt.h>

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



// Interrupt subroutine for external interrupt 0
ISR(TIMER2_COMPA_vect)
{
      printf("%d" , getCalendarDay(&rawDCF));

}

int main(int argc, char** argv){
    DCF_init();
    printf("%d" , getCalendarDay(&rawDCF));
    PORTD = 1;
    // Timer 2 konfigurieren
    GTCCR |= (1 << TSM) | (1 << PSRASY);  //Timer anhalten, Prescaler Reset
    ASSR |= (1 << AS2);                   //Asynchron Mode einschalten
    TCCR2A = (1 << WGM21);                //CTC Modus
    TCCR2B |= (1 << CS22) | (1 << CS21);  //Prescaler 256
    // 32768 / 256 / 1 = 128                Intervall = 1s
    OCR2A = 128 - 1;
    TIMSK2 |= (1<<OCIE2A);                //Enable Compare Interrupt
    GTCCR &= ~(1 << TSM);                 //Timer starten
    sei();                                //Enable global Interrupts

    for(;;);                           // The main loop stays empty and
    // could contain code you want.


    return 0;
}