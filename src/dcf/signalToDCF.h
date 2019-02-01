/*******************************************************************************
 * File signalToDCF.h
 *
 * Includes the algorithm to analyse incoming DCF Signal
 * and fill the rawDCF with 1's and 0's.
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 14.12.18
 *******************************************************************************/

#ifndef ES2018_REPO_SIGNALTODCF_H
#define ES2018_REPO_SIGNALTODCF_H
#include <inttypes.h>
#include <stdbool.h>

void evaluateSignal(uint8_t);
bool dcfSignalLost;
bool leapSecondNextHour;
bool leapSecondSkip;
uint8_t leapSecondSignalCount;
uint8_t g_position;
uint16_t minutesNotSynced;
bool isSynced;
uint8_t secondsPassed;
uint8_t errorStateLastMinute;
#endif //ES2018_REPO_SIGNALTODCF_H
