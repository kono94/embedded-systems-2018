//
// Created by Jan Uni on 14.12.18.
//

#include "signalToDCF.h"
#include <inttypes.h>
#include <stdbool.h>

#include "dcftype.h"
#include "../util/triggers.h"


int MISSING_THRESHOLD = 5;
int ZERO_BORDER_ALL = 70;
int ONE_BORDER_ALL = 150;
int NEW_MINUTE_BORDER = 1700;
int MISSING_SIGNAL_BORDER = 3000;

// states: 0 = nicht erregt, 1 = erregt
int currentState = 0;

int state_0_all = 0;

int state_1_all = 0;
int state_1_missed = 0;
bool errorState = false;

void evaluateSignal(uint8_t pinC_value){
    if(pinC_value >= 1){
        if(errorState){
            errorState = false;
            // tell "main" that the signal is present once again
            trigger_noSignalError = true;
        }
        // switch to active state
        if(currentState == 0){
            // not active and 1 => active state but keep all-counter
            currentState = 1;
            if(state_0_all >= NEW_MINUTE_BORDER){
                // new minute found
                state_0_all = 0;
                g_position = 0;
            }
        }else if(currentState == 1){
            // active and 1 => reset missing count and increment all-counter
            state_1_all += 1;
            state_1_missed = 0;
        }
    }else{
        if(currentState == 0){
            // not active and 0 => just increment all-counter of inactive state
            state_0_all += 1;
            if(state_0_all >= MISSING_SIGNAL_BORDER && !errorState){
                // 3 seconds no ones or zeros found
                errorState = true;
                trigger_signalError = true;

            }
        }else if(currentState == 1){
            // active and 0 => increment all count and missed count,
            //                 MISSING_THRESHOLD number of "abtaster" missed, switch to
            // inactive state and check how many "abtaster" in total were made
            // while being in this active state
            state_1_all += 1;
            state_1_missed += 1;
            if(state_1_missed >= MISSING_THRESHOLD){
                if(state_1_all >= ONE_BORDER_ALL){
                    rawDCF[g_position++%60] = 1;
                    state_0_all = 0;
                }else if(state_1_all >= ZERO_BORDER_ALL){
                    rawDCF[g_position++%60] = 0;
                    state_0_all = 0;
                }else{
                    // do not reset inactive counter!
                    // was just a small edge from the signal
                }
                state_1_all = 0;
                state_1_missed = 0;
                currentState = 0;
            }
        }
    }
}