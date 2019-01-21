/*******************************************************************************
 * File fontConstants.c
 *
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#include "fontConstansts.h"
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

uint8_t CHAR_ZERO[] =   {0b00111110, 0b01010001, 0b01001001, 0b01000101, 0b00111110, 0b00000000};
uint8_t CHAR_ONE[] =  	{0b01000100, 0b01000010, 0b01111111, 0b01000000, 0b01000000, 0b00000000};
uint8_t CHAR_TWO[] = 	{0b01100010, 0b01010001, 0b01010001, 0b01001001, 0b01000110, 0b00000000};
uint8_t CHAR_THREE[] = 	{0b00100010, 0b01000001, 0b01001001, 0b01001001, 0b00110110, 0b00000000};
uint8_t CHAR_FOUR[] = 	{0b00011000, 0b00010100, 0b00010010, 0b01111111, 0b00010000, 0b00000000};
uint8_t CHAR_FIVE[] = 	{0b01000111, 0b01000101, 0b01000101, 0b00101001, 0b00010001, 0b00000000};
uint8_t CHAR_SIX[] = 	{0b00111100, 0b01001010, 0b01001001, 0b01001001, 0b00110000, 0b00000000};
uint8_t CHAR_SEVEN[] = 	{0b00000011, 0b00000001, 0b01111001, 0b00000101, 0b00000011, 0b00000000};
uint8_t CHAR_EIGHT[] = 	{0b00110110, 0b01001001, 0b01001001, 0b01001001, 0b00110110, 0b00000000};
uint8_t CHAR_NINE[] = 	{0b00000110, 0b01001001, 0b01001001, 0b00101001, 0b00011110, 0b00000000};
uint8_t CHAR_M[] = 		{0b11111110, 0b01000000, 0b00110000, 0b01000000, 0b11111110, 0b00000000};
uint8_t CHAR_D[] = 		{0b11111110, 0b10000010, 0b10000010, 0b01000100, 0b00111000, 0b00000000};
uint8_t CHAR_F[] = 		{0b11111110, 0b10010000, 0b10010000, 0b10010000, 0b10000000, 0b00000000};
uint8_t CHAR_S[] = 		{0b01100010, 0b10010010, 0b10010010, 0b10010010, 0b10001100, 0b00000000};
uint8_t CHAR_i[] = 		{0b00000000, 0b00100010, 0b10111110, 0b00000010, 0b00000010, 0b00000000};
uint8_t CHAR_o[] = 		{0b00011100, 0b00100010, 0b00100010, 0b00100010, 0b00011100, 0b00000000};
uint8_t CHAR_r[] = 		{0b00111110, 0b00010000, 0b00100000, 0b00100000, 0b00010000, 0b00000000};
uint8_t CHAR_a[] = 		{0b00000100, 0b00101010, 0b00101010, 0b00101010, 0b00011110, 0b00000000};
uint8_t CHAR_DOUBLE_POINTS[] = 	{0b00000000, 0b00110110, 0b00110110, 0b00000000, 0b00000000, 0b00000000};
uint8_t CHAR_SINGLE_POINT[] = 	{0b00000000, 0b00000110, 0b00000110, 0b00000000, 0b00000000, 0b00000000};
uint8_t CHAR_EMPTY[] = 			{0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};
uint8_t CHAR_INVALID[] = {0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111,};


/* return array with size 6
 * 0 = 0
 * 1 = 1
 * ....
 * 9 = 9
 * 10 = "."
 * 11 = ":"
 */
uint8_t* getInstructionFromNumber(uint8_t n){
    switch(n){
        case 0: return CHAR_ZERO;
        case 1: return CHAR_ONE;
        case 2: return CHAR_TWO;
        case 3: return CHAR_THREE;
        case 4: return CHAR_FOUR;
        case 5: return CHAR_FIVE;
        case 6: return CHAR_SIX;
        case 7: return CHAR_SEVEN;
        case 8: return CHAR_EIGHT;
        case 9: return CHAR_NINE;
        case 10: return CHAR_SINGLE_POINT;
        case 11: return CHAR_DOUBLE_POINTS;
        default: return CHAR_INVALID;
    }
}


// return array with size 12 as it combines
// two characters to represent weekday (Mo, Di, Mi, Do, Fr,...)
uint8_t* getInstructionFromWeekdayIndex(uint8_t weekdayIndex){

    // array to hold the result
    uint8_t* combined = malloc(2 * font_width * 8);

    uint8_t* firstLetter;
    uint8_t* secondLetter;

    switch(weekdayIndex) {
        case 1:
            firstLetter = CHAR_M;
            secondLetter = CHAR_o;
            break;
        case 2:
            firstLetter = CHAR_D;
            secondLetter = CHAR_i;
            break;
        case 3:
            firstLetter = CHAR_M;
            secondLetter = CHAR_i;
            break;
        case 4:
            firstLetter = CHAR_D;
            secondLetter = CHAR_o;
            break;
        case 5:
            firstLetter = CHAR_F;
            secondLetter = CHAR_r;
            break;
        case 6:
            firstLetter = CHAR_S;
            secondLetter = CHAR_a;
            break;
        case 7:
            firstLetter = CHAR_S;
            secondLetter = CHAR_o;
            break;
        default:
            // ERROR DISPLAY "DD"
            firstLetter = CHAR_D;
            secondLetter = CHAR_D;
            break;
    }

    memcpy(combined,     firstLetter, font_width * 8);
    memcpy(combined + font_width, secondLetter, font_width * 8);

    return combined;
}
 /*
0:
0 1 1 1 0 0
1 0 0 0 1 0
1 0 0 1 1 0
1 0 1 0 1 0
1 1 0 0 1 0
1 0 0 0 1 0
0 1 1 1 0 0
0 0 0 0 0 0

1:
0 0 1 0 0 0
0 1 1 0 0 0
1 0 1 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
1 1 1 1 1 0
0 0 0 0 0 0

2:
0 1 1 1 0 0
1 0 0 0 1 0
0 0 0 0 1 0
0 0 0 1 0 0
0 1 1 0 0 0
1 0 0 0 0 0
1 1 1 1 1 0
0 0 0 0 0 0

3:
0 1 1 1 0 0
1 0 0 0 1 0
0 0 0 0 1 0
0 0 1 1 0 0
0 0 0 0 1 0
1 0 0 0 1 0
0 1 1 1 0 0
0 0 0 0 0 0

4:
0 0 0 1 0 0
0 0 1 1 0 0
0 1 0 1 0 0
1 0 0 1 0 0
1 1 1 1 1 0
0 0 0 1 0 0
0 0 0 1 0 0
0 0 0 0 0 0

5:
1 1 1 1 1 0
1 0 0 0 0 0
1 1 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 1 0 0
1 1 1 0 0 0
0 0 0 0 0 0

6:
0 0 1 1 0 0
0 1 0 0 0 0
1 0 0 0 0 0
1 1 1 1 0 0
1 0 0 0 1 0
1 0 0 0 1 0
0 1 1 1 0 0
0 0 0 0 0 0

7:
1 1 1 1 1 0
1 0 0 0 1 0
0 0 0 1 0 0
0 0 1 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
0 0 0 0 0 0

8:
0 1 1 1 0 0
1 0 0 0 1 0
1 0 0 0 1 0
0 1 1 1 0 0
1 0 0 0 1 0
1 0 0 0 1 0
0 1 1 1 0 0
0 0 0 0 0 0

9:
0 1 1 1 0 0
1 0 0 0 1 0
1 0 0 0 1 0
0 1 1 1 1 0
0 0 0 0 1 0
0 0 0 1 0 0
0 1 1 0 0 0
0 0 0 0 0 0

":":
0 0 0 0 0 0
0 1 1 0 0 0
0 1 1 0 0 0
0 0 0 0 0 0
0 1 1 0 0 0
0 1 1 0 0 0
0 0 0 0 0 0

".":
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 1 1 0 0 0
0 1 1 0 0 0
0 0 0 0 0 0

Mo Di Mi Do Fr Sa So:
M D F S o i r a:

M:
1 0 0 0 1 0
1 1 0 1 1 0
1 0 1 0 1 0
1 0 1 0 1 0
1 0 0 0 1 0
1 0 0 0 1 0
1 0 0 0 1 0
0 0 0 0 0 0

D:
1 1 1 0 0 0
1 0 0 1 0 0
1 0 0 0 1 0
1 0 0 0 1 0
1 0 0 0 1 0
1 0 0 1 0 0
1 1 1 0 0 0
0 0 0 0 0 0

F:
1 1 1 1 1 0
1 0 0 0 0 0
1 0 0 0 0 0
1 1 1 1 0 0
1 0 0 0 0 0
1 0 0 0 0 0
1 0 0 0 0 0
0 0 0 0 0 0

S:
0 1 1 1 1 0
1 0 0 0 0 0
1 0 0 0 0 0
0 1 1 1 0 0
0 0 0 0 1 0
0 0 0 0 1 0
1 1 1 1 0 0
0 0 0 0 0 0

o:
0 0 0 0 0 0
0 0 0 0 0 0
0 1 1 1 0 0
1 0 0 0 1 0
1 0 0 0 1 0
1 0 0 0 1 0
0 1 1 1 0 0
0 0 0 0 0 0

i:
0 0 1 0 0 0
0 0 0 0 0 0
0 1 1 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
0 1 1 1 0 0
0 0 0 0 0 0

r:
0 0 0 0 0 0
0 0 0 0 0 0
1 0 1 1 0 0
1 1 0 0 1 0
1 0 0 0 0 0
1 0 0 0 0 0
1 0 0 0 0 0
0 0 0 0 0 0

a:
0 0 0 0 0 0
0 0 0 0 0 0
0 1 1 1 0 0
0 0 0 0 1 0
0 1 1 1 1 0
1 0 0 0 1 0
0 1 1 1 1 0
0 0 0 0 0 0
  */
