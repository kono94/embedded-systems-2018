/*******************************************************************************
 * File avrDatetime.h
 *
 * Defines and initializes the intern time.
 * Also offers a function to let one second pass
 * and increment the time and date information correctly.
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 30.11.18
 *******************************************************************************/
#ifndef ES2018_REPO_AVRDATETIME_H
#define ES2018_REPO_AVRDATETIME_H

#include <inttypes.h>

typedef struct {
    uint8_t seconds;
    uint8_t minutes;
    uint8_t hours;
    uint8_t days;
    uint8_t months;
    uint8_t years_tens;
    uint8_t years_hundreds;
    uint8_t weekdayIndex;
    char* weekdayString;
}AvrDatetime;

volatile AvrDatetime avrDatetime;
volatile AvrDatetime* p_avrDatetime;
void AvrDatetime_init();
void incrementByOneSecond();

#endif //ES2018_REPO_AVRDATETIME_H