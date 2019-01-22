//
// Created by Jan Uni on 09.01.19.
//

#include "displayInstructions.h"
#include "../internClock/avrDatetime.h"
#include "fontConstansts.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void init_displayInstructions(){
    display_toSend_currentSession = 0;
    display_toSend = 0;
    display_dataLength = 0;
    display_row = 1;

    /*
     * 0:
     *  lower "enable" and set dataBits
     *
     *  1: higher "enable", so the display reads in dataBits
     */
    sending_phase = 0;
}

bool setInstructionsForRow(uint8_t row){
    switch (row){
        case 1:
            // instruction for HH:mm:SS
            memcpy(display_data,    getInstructionFromNumber(p_avrDatetime->hours/10), font_width * 8);
            memcpy(display_data + 6,    getInstructionFromNumber(p_avrDatetime->hours%10), font_width * 8);
            memcpy(display_data + 12,    getInstructionFromNumber(11), font_width * 8);
            memcpy(display_data + 18,    getInstructionFromNumber(p_avrDatetime->minutes/10), font_width * 8);
            memcpy(display_data + 24,    getInstructionFromNumber(p_avrDatetime->minutes%10), font_width * 8);
            memcpy(display_data + 30,    getInstructionFromNumber(11), font_width * 8);
            memcpy(display_data + 36,    getInstructionFromNumber(p_avrDatetime->seconds/10), font_width * 8);
            memcpy(display_data + 42,    getInstructionFromNumber(p_avrDatetime->seconds%10), font_width * 8);

            display_toSend_currentSession = 48;
            display_toSend = 48;
            return true;
        case 2:
            // instruction for DD.MM.YYYY
            memcpy(display_data,    getInstructionFromNumber(p_avrDatetime->days/10), font_width * 8);
            memcpy(display_data + 6,    getInstructionFromNumber(p_avrDatetime->days%10), font_width * 8);
            memcpy(display_data + 12,    getInstructionFromNumber(10), font_width * 8);
            memcpy(display_data + 18,    getInstructionFromNumber(p_avrDatetime->months/10), font_width * 8);
            memcpy(display_data + 24,    getInstructionFromNumber(p_avrDatetime->months%10), font_width * 8);
            memcpy(display_data + 30,    getInstructionFromNumber(10), font_width * 8);
            memcpy(display_data + 36,    getInstructionFromNumber(p_avrDatetime->years_hundreds/10), font_width * 8);
            memcpy(display_data + 42,    getInstructionFromNumber(p_avrDatetime->years_hundreds%10), font_width * 8);
            memcpy(display_data + 48,    getInstructionFromNumber(p_avrDatetime->years_tens/10), font_width * 8);
            memcpy(display_data + 54,    getInstructionFromNumber(p_avrDatetime->years_tens%10), font_width * 8);

            display_toSend_currentSession = 60;
            display_toSend = 60;
            return true;
        case 3:
            memcpy(display_data,    getInstructionFromWeekdayIndex(p_avrDatetime->weekdayIndex), font_width * 8);

            display_toSend_currentSession = 12;
            display_toSend = 12;
            return true;
        case 4:
            memcpy(display_data,    getInstructionFromCurrentDCFPos(), font_width * 8);
            display_toSend_currentSession = 24;
            display_toSend = 24;
            return true;
        case 5:
            memcpy(display_data,    getInstructionForCurrentDCFStatus(), font_width * 8);
            display_toSend_currentSession = 42;
            display_toSend = 42;
            return true;
        default:
            return false;
    }
}
