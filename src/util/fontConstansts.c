//
// Created by Jan Uni on 09.01.19.
//

#include "fontConstansts.h"


void init_fontConstants{
         CHAR_ZERO = {0b01111100, 0b10001010, 0b10010010, 0b10100010, 0b01111100, 0b00000000};
         CHAR_ONE =  {0b00100010, 0b01000010, 0b11111110, 0b00000010, 0b00000010, 0b00000000};
         CHAR_TWO = {};
         CHAR_THREE = {};
         CHAR_FOUR = {};
         CHAR_FIVE = ;
         CHAR_SIX = ;
         CHAR_SEVEN =    ;
         CHAR_EIGHT = ;
         CHAR_NINE = ;
         CHAR_M = ;
         CHAR_D = ;
         CHAR_F = ;
         CHAR_S = ;
         CHAR_i = ;
         CHAR_o = ;
         CHAR_r = ;
         CHAR_a = ;
         CHAR_DOUBLE_POINTS = ;
         CHAR_SINGLE_POINT = ;
         CHAR_EMPTY = ;
};

// return array with size 6
// 0 = 0
// 1 = 1
// ....
/*
 * 9 = 9
 * 10 = "."
 * 11 = ":"
 */
uint_8* getInstructionFromNumber(uint_t n){
    switch(n){
        case 0:
            return CHAR_ZERO;
        case 1:
            return CHAR_ONE;
        case 10:
            return CHAR_SINGLE_POINT;
        case 11:
            return CHAR_DOUBLE_POINTS;
    }
}



// return array with size 12 as it combines
// two characters to represent weekday (Mo, Di, Mi, Do, Fr,...)
uint_8* getInstructionFromWeekdayIndex(uint_t weekdayIndex){

    // array to hold the result
    uint_8* combined = malloc(2 * font_width * sizeof(uint_8));

    uint_8* firstLetter;
    uint_8* secondLetter;

    switch(weekdayIndex) {
        switch(weekday) {
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
            break;;
    }

    memcpy(combined,     firstLetter, font_width * sizeof(uint_8));
    memcpy(combined + font_width, secondLetter, font_width * sizeof(uint_8));

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
1 1 1 1 1 1
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