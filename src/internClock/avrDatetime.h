//
// Created by Jan Uni on 30.11.18.
//

#ifndef ES2018_REPO_AVRDATETIME_H
#define ES2018_REPO_AVRDATETIME_H

#include <inttypes.h>

typedef struct {
    uint8_t minutes;
    uint8_t hours;
    uint8_t days;
    uint8_t months;
    uint8_t years_tens;
    uint8_t years_hundreds;
    char* weekdayString;
}AvrDatetime;

volatile AvrDatetime avrDatetime;
volatile AvrDatetime* p_avrDatetime;
void AvrDatetime_init();
#endif //ES2018_REPO_AVRDATETIME_H