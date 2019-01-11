//
// Created by Jan Uni on 09.01.19.
//

#include "displayInstructions.h"
#include "../internClock/avrDatetime.h"
#include "fontConstansts.h"

uint_8 display_dataLength;
uint_8 display_row;
uint_8[] display_data;
uint8_t display_toSend;

/*
 * 0:
 *  lower "enable" and set dataBits
 *
 *  1: higher "enable", so the display reads in dataBits
 */
uint8_t sending_phase = 0;

void init_sendToDisplay(){
    display_toSend_currentSession = 0;
    display_toSend = 0;
    display_dataLength = 0;
    display_row = 1;
    display_data = uint_8[128];
}

// This gets called when one second passed /changed
// (in while-loop in main-file)
void visualizeOnDisplay() {
    display_row = 1;
    setInstructionsForRow(1);
}

void setInstructionsForRow(uint8_t row){
    switch (row){
        case 1:
            // instruction for HH:mm:SS
            memcpy(display_data,    getInstructionFromNumber(p_avrDatetime->hours/10), font_width * sizeof(uint_8));
            memcpy(display_data + 6,    getInstructionFromNumber(p_avrDatetime->hours%10), font_width * sizeof(uint_8));
            memcpy(display_data + 12,    getInstructionFromNumber(11), font_width * sizeof(uint_8));
            memcpy(display_data + 18,    getInstructionFromNumber(p_avrDatetime->minutes/10), font_width * sizeof(uint_8));
            memcpy(display_data + 24,    getInstructionFromNumber(p_avrDatetime->minutes%10), font_width * sizeof(uint_8));
            memcpy(display_data + 30,    getInstructionFromNumber(11), font_width * sizeof(uint_8));
            memcpy(display_data + 36,    getInstructionFromNumber(p_avrDatetime->seconds/10), font_width * sizeof(uint_8));
            memcpy(display_data + 42,    getInstructionFromNumber(p_avrDatetime->seconds%10), font_width * sizeof(uint_8));


            display_toSend_currentSession = 48;
            display_toSend = 48;
            break;
        case 2:
            // instruction for DD.MM.YYYY
            memcpy(display_data,    getInstructionFromNumber(p_avrDatetime->days/10), font_width * sizeof(uint_8));
            memcpy(display_data + 6,    getInstructionFromNumber(p_avrDatetime->days%10), font_width * sizeof(uint_8));
            memcpy(display_data + 12,    getInstructionFromNumber(10), font_width * sizeof(uint_8));
            memcpy(display_data + 18,    getInstructionFromNumber(p_avrDatetime->months/10), font_width * sizeof(uint_8));
            memcpy(display_data + 24,    getInstructionFromNumber(p_avrDatetime->months%10), font_width * sizeof(uint_8));
            memcpy(display_data + 30,    getInstructionFromNumber(10), font_width * sizeof(uint_8));
            memcpy(display_data + 36,    getInstructionFromNumber(p_avrDatetime->years_hundreds/10), font_width * sizeof(uint_8));
            memcpy(display_data + 42,    getInstructionFromNumber(p_avrDatetime->years_hundreds%10), font_width * sizeof(uint_8));
            memcpy(display_data + 48,    getInstructionFromNumber(p_avrDatetime->years_tens/10), font_width * sizeof(uint_8));
            memcpy(display_data + 54,    getInstructionFromNumber(p_avrDatetime->years_tens%10), font_width * sizeof(uint_8));

            display_toSend_currentSession = 60;
            display_toSend = 60;
            break;
        case 3:
            memcpy(display_data,    getInstructionFromWeekdayIndex(p_avrDatetime->weekdayIndex), font_width * sizeof(uint_8));

            display_toSend_currentSession = 12;
            display_toSend = 12;
            break;
        default:
            break;
    }
}