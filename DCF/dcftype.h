/*******************************************************************************
 * File dcftype.h
 *
 * Defines a type that represents the raw message of
 * a DCF-77 signal.
 * The signal consists of 59 bits, therefore a bool array of size
 * 59 is declared as main data structure to save those bits.
 * To get the e.q. bitX of the signal, simply access the
 * array with index x;
 *
 * DCF bit 0 => DCF[0]
 * DCF bit 21 => DCF[21]
 *
 * Autor: Jan Löwenstrom
 * Date: 14.11.18
 *******************************************************************************/

#ifndef ES2018_REPO_DCF_H
#define ES2018_REPO_DCF_H

#include <stdbool.h>
#include <inttypes.h>

/*
 * defining the type "DCF" as bool array[59]
 */
typedef bool DCF[59];

/*
 * saving the length of DCF array because C lang does not
 * support array.length out of the box.
 * Somewhat redundant because the length with always be 59
 * and the length of an array has to be given at declaration time.
 */
uint8_t DCF_LENGTH;

/*
 * global dcf message.
 * "raw" because it is just there to be filled and no date validation or
 * parity check has been made.
 */
DCF rawDCF;

/*
 * initialize variables and "rawDCF" array
 */
void DCF_init();

#endif //ES2018_REPO_DCF_H
