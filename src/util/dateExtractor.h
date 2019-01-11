/*******************************************************************************
 * File dateExtractor.h
 *
 * Offers functions that use the full DCF-77 message
 * to return certain date or time information.
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 14.11.18
 *******************************************************************************/


#ifndef ES2018_REPO_DATEEXTRACTOR_H
#define ES2018_REPO_DATEEXTRACTOR_H

#include "../DCF/dcftype.h"

uint8_t getMinutes(const DCF dcf);
uint8_t getHours(const DCF dcf);
uint8_t getCalendarDay(const DCF dcf);
uint8_t getCalendarMonth(const DCF dcf);
uint8_t getCalendarYears(const DCF dcf);

/*
 * returns a string that represents the weekday
 * e.q.:
 * "Mon"
 * "Tue"
 *  ...
 * "Sun"
 */
char* getWeekdayString(const DCF dcf);

#endif //ES2018_REPO_DATEEXTRACTOR_H
