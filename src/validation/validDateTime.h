//
// Created by Jan Uni on 02.12.18.
//

#ifndef ES2018_REPO_VALIDDATETIME_H
#define ES2018_REPO_VALIDDATETIME_H
#include <stdbool.h>
#include "../internClock/avrDatetime.h"

bool isValidInternClock(volatile AvrDatetime* p_internClock);
bool isValidDateTime(uint8_t day, uint8_t month, uint8_t hundreds, uint8_t tens, uint8_t hours, uint8_t minutes, uint8_t seconds);

#endif //ES2018_REPO_VALIDDATETIME_H
