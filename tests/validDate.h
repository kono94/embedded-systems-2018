
#ifndef ES2018_REPO_VALIDDATE_H
#define ES2018_REPO_VALIDDATE_H

#include <stdbool.h>
#include <inttypes.h>

uint8_t isValidDate(uint8_t day, uint8_t month, uint8_t hundreds, uint8_t tens);
uint8_t isValidDay(uint8_t day, uint8_t month, uint8_t leapYear);
uint8_t testLeapYear(uint8_t hundreds, uint8_t tens);


#endif //ES2018_REPO_VALIDDATE_H
