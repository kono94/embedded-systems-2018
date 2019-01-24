/*******************************************************************************
 * File dateExtractor.c
 *
 * Offers functions that use the full DCF-77 message
 * to return certain date or time information.
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 14.11.18
 *******************************************************************************/

#include <inttypes.h>
#include "dateExtractor.h"
#include "../DCF/dcftype.h"
#include "bitConverter.h"
#include "../internClock/avrDatetime.h"
#include "../validation/validDateTime.h"
#include "../DCF/signalToDCF.h"
#include "../validation/parityChecker.h"

/**
 *  bit range for a specific part of the date is split
 *  into tens and unit values.
 *
 *  e.q.:
 *  minute:
 *      units ("Einer"): 1001 = 9
 *          bit21: 1
 *          bit22: 0
 *          bit23: 0
 *          bit24: 1
 *      tens ("Zehner"): 101 = 5 * 10 = 50
 *          bit25: 1
 *          bit26: 0
 *          bit27: 1
 *
 * result = 59
 */


/*
 * labeling the parameter as const pointer makes sure
 * it does not get changed because it is ready-only
 * and not assignable.
 */

/*
 * bits for minutes: 21-27
 */
uint8_t getMinutes(const DCF dcf){
    uint8_t units = helper_4bit(dcf[21], dcf[22], dcf[23], dcf[24]);
    uint8_t tens = 10 * helper_3bit(dcf[25], dcf[26], dcf[27]);

    return tens + units;
}

/*
 * bits for hours: 29-34
 */
uint8_t getHours(const DCF dcf){
    uint8_t units = helper_4bit(dcf[29], dcf[30], dcf[31], dcf[32]);
    uint8_t tens = 10 * helper_2bit(dcf[33], dcf[34]);

    return tens + units;
}

/*
 * bits for day: 36-41
 */
uint8_t getCalendarDay(const DCF dcf){
    uint8_t units = helper_4bit(dcf[36], dcf[37], dcf[38], dcf[39]);
    uint8_t tens = 10 * helper_2bit(dcf[40], dcf[41]);

    return tens + units;
}

/*
 * bits for month: 45-49
 */
uint8_t getCalendarMonth(const DCF dcf){
    uint8_t units = helper_4bit(dcf[45], dcf[46], dcf[47], dcf[48]);
    uint8_t tens = 10 * dcf[49];

    return tens + units;
}

/*
 * bits for year: 50-57
 */
uint8_t getCalendarYears(const DCF dcf){
    uint8_t units = helper_4bit(dcf[50], dcf[51], dcf[52], dcf[53]);
    uint8_t tens = 10 * helper_4bit(dcf[54], dcf[55], dcf[56], dcf[57]);

    return tens + units;
}

/*
 * bits for weekday: 42-44
 */
char* getWeekdayString(const DCF dcf){
    uint8_t weekday = helper_3bit(dcf[42], dcf[43], dcf[44]);

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

/*
 * bits for weekday: 42-44
 */
uint8_t getWeekdayIndex(const DCF dcf){
    return helper_3bit(dcf[42], dcf[43], dcf[44]);
}


void syncAVRTimeWithDCF(){
    if(!checkParitiesInDCF(rawDCF)){
        errorStateLastMinute = 3;
        return;
    }
    if(isValidDateTime(getCalendarDay(rawDCF), getCalendarMonth(rawDCF), 20, getCalendarYears(rawDCF), getHours(rawDCF), getMinutes(rawDCF), 0)){
        p_avrDatetime->hours = getHours(rawDCF);
        p_avrDatetime->minutes = getMinutes(rawDCF);
        p_avrDatetime->seconds = 0;

        p_avrDatetime->days = getCalendarDay(rawDCF);
        p_avrDatetime->months = getCalendarMonth(rawDCF);
        p_avrDatetime->years_tens = getCalendarYears(rawDCF);

        p_avrDatetime->weekdayIndex = getWeekdayIndex(rawDCF);

        minutesNotSynced = 0;
        isSynced = true;
        errorStateLastMinute = 0;
    }else{
        errorStateLastMinute = 4;
    }
}