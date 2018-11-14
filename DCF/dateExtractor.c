//
// Created by Jan Uni on 14.11.18.
//
#include <inttypes.h>
#include "dateExtractor.h"
#include "DCF.h"
#include "../util/bitConverter.h"

//TODO: const DCF* dcf?
uint8_t getMinutes(DCF* dcf){
    uint8_t ones = helper_4bit(*dcf[21], *dcf[22], *dcf[23], *dcf[24]);
    uint8_t tens = 10 * helper_3bit(*dcf[25], *dcf[26], *dcf[27]);

    return tens + ones;
}

uint8_t getHours(DCF* dcf){
    uint8_t ones = helper_4bit(*dcf[29], *dcf[30], *dcf[31], *dcf[32]);
    uint8_t tens = 10 * helper_2bit(*dcf[33], *dcf[34]);

    return tens + ones;
}

uint8_t getCalendarDay(DCF* dcf){
    uint8_t ones = helper_4bit(*dcf[36], *dcf[37], *dcf[38], *dcf[39]);
    uint8_t tens = 10 * helper_2bit(*dcf[40], *dcf[41]);

    return tens + ones;
}

uint8_t getCalendarMonth(DCF* dcf){
    uint8_t ones = helper_4bit(*dcf[45], *dcf[46], *dcf[47], *dcf[48]);
    uint8_t tens = 10 * *dcf[49];

    return tens + ones;
}

uint8_t getCalendarYears(DCF* dcf){
    uint8_t ones = helper_4bit(*dcf[50], *dcf[51], *dcf[52], *dcf[53]);
    uint8_t tens = 10 * helper_4bit(*dcf[54], *dcf[55], *dcf[56], *dcf[57]);

    return tens + ones;
}

char* getWeekdayString(DCF* dcf){
    uint8_t weekday = helper_3bit(*dcf[42], *dcf[43], *dcf[44]);

    switch(weekday) {
        case 1: return "Mon";
        case 2: return "Tue";
        case 3: return "Wed";
        case 4: return "Thu";
        case 5: return "Fri";
        case 6: return "Sat";
        case 7: return "Sun";
        default: return "ERROR 34";
    }
}