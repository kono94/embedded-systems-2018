#include "init-input.h"
#include "run-input.h"
#include <avr/io.h>
#include <util/delay.h>

uint8_t lichter(uint8_t pPhase)
{
  uint8_t result;
  switch(pPhase)
    {
    case 0: result = 0b00001001; break;
    case 1: result = 0b00001011; break;
    case 2: result = 0b00001100; break;
    case 3: result = 0b00001010; break;
    case 4: result = 0b00001001; break;
    case 5: result = 0b00010001; break;
    default:
      result = 0b00000000;
    }
  return result;
}

void run()
{
  uint8_t button = 0;
  for (int simcount=3000; simcount>0; simcount--)
    {
      button = PINC;
//      PORTB = lichter(phase);
  }  PORTD = (lichter(phase)>>3)<<5;
      if (button >= 1) {
	    phase = (phase + 1) % 6;
      }
      _delay_ms(1);
    }
}
