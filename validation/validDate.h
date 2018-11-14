/*******************************************************************************
 * File validDate.h
 *
 * //TODO: description
 *
 * Autor: Johann Hoffer
 * Date: 09.11.18
 *******************************************************************************/

#ifndef ES2018_REPO_VALIDDATE_H
#define ES2018_REPO_VALIDDATE_H

#include <stdbool.h>
#include <inttypes.h>

bool isValidDate(uint8_t day, uint8_t month, uint8_t hundreds, uint8_t tens);
bool isValidDay(uint8_t day, uint8_t month, uint8_t leapYear);
bool isLeapYear(uint8_t hundreds, uint8_t tens);

#endif //ES2018_REPO_VALIDDATE_H
