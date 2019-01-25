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
        case 0:
            // instruction for HH:mm:SS
            copyTimeIntoDisplayData();

            display_toSend_currentSession = 48;
            display_toSend = 48;
            return true;
        case 1:
            // instructions for DD.MM.YYYY
            copyDateIntoDisplayData();

            display_toSend_currentSession = 60;
            display_toSend = 60;
            return true;
        case 2:
            copyWeekDayIntoDisplayData();

            display_toSend_currentSession = 12;
            display_toSend = 12;
            return true;
        case 3:
            copyCurrentDCFPosIntoDisplayData();

            display_toSend_currentSession = 48;
            display_toSend = 48;
            return true;
        case 4:
            copyCurrentDCFStatusIntoDisplayData();

            display_toSend_currentSession = 18;
            display_toSend = 18;
            return true;
        case 5:
            copyMinutesNotSyncedIntoDisplayData();
            display_toSend_currentSession = 48;
            display_toSend = 48;
            return true;
        case 6:
            copySyncStatusIntoDisplayData();

            display_toSend_currentSession = 60;
            display_toSend = 60;
            return true;
        case 7:
            copyErrorStateLastMinuteIntoDisplayData();

            display_toSend_currentSession = 30;
            display_toSend = 30;
            return true;
        default:
            display_toSend_currentSession = 0;
            display_toSend = 0;
            return false;
    }
}
