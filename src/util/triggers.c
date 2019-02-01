/*******************************************************************************
 * File triggers.c
 *
 * Exposes boolean flags to trigger routines
 * in the main while-loop
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#include "triggers.h"
#include <stdbool.h>

void init_triggers(){
    trigger_sentToDisplay = false;
    trigger_evaluateSignal = false;
    trigger_oneSecondPassed = false;
}

