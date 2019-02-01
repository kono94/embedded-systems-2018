/*******************************************************************************
 * File oneSecondInterrupt.h
 *
 * Sets up the one sec timer/ interrupt.
 * Also handles the corresponding interrupt vector
 * which will eventually trigger the routine of
 * incrementing the intern time.
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#ifndef ES2018_REPO_ONESECONDINTERRUPT_H
#define ES2018_REPO_ONESECONDINTERRUPT_H
#include <avr/io.h>
#include <avr/interrupt.h>

void enableOneSecInterrupt();

#endif //ES2018_REPO_ONESECONDINTERRUPT_H
