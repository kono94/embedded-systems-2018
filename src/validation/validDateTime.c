/*******************************************************************************
 * File validDateTime.h
 *
 * Offers wrapper functions to validate the intern time or the
 * time information received from the DCF-signal
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 02.12.18
 *******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "validDateTime.h"
#include "validDate.h"
#include "validTime.h"
#include "validDateTime.h"
#include "../internClock/avrDatetime.h"

bool isValidInternClock(volatile AvrDatetime* p_internClock){
    return isValidDateTime(p_internClock->days, p_internClock->months, p_internClock->years_hundreds, p_internClock->years_tens,
            p_internClock->hours, p_internClock->minutes, p_internClock->seconds);
}

bool isValidDateTime(uint8_t day, uint8_t month, uint8_t hundreds, uint8_t tens, uint8_t hours, uint8_t minutes, uint8_t seconds){
    return (isValidDate(day, month, hundreds, tens) && isValidTime(hours, minutes, seconds));
}
