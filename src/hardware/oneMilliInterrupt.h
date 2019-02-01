/*******************************************************************************
 * File oneMilliInterrupt.c
 *
 * Sets up the one ms timer/ interrupt.
 * Also handles the corresponding interrupt vector
 * which will eventually trigger the evaluation routine
 * and the routine to send data or instructions to the display
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#ifndef ES2018_REPO_ONEMILLIINTERRUPT_H
#define ES2018_REPO_ONEMILLIINTERRUPT_H

#include <avr/io.h>
#include <avr/interrupt.h>

void enableOneMilliInterrupt();

#endif //ES2018_REPO_ONEMILLIINTERRUPT_H
