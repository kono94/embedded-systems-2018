/*******************************************************************************
 * File dcftype.c
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
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 14.11.18
 *******************************************************************************/

#include "dcftype.h"
#include "../util/bitConverter.h"


void DCF_init(){
    DCF_LENGTH = 59;

    /*
     * necessary initialisation to make sure
     * every entry is set to 0.
     */
    for(uint8_t i=0; i < DCF_LENGTH; ++i){
        rawDCF[i] = 0;
    }
}

