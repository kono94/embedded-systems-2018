//
// Created by Jan Uni on 30.11.18.
//
#include "avrDatetime.h"
#include <stdio.h>
#include <inttypes.h>
#include "../validation/validDateTime.h"
#include "../DCF/signalToDCF.h"

void AvrDatetime_init(){
    p_avrDatetime = &avrDatetime;
    p_avrDatetime->seconds = 0;
    p_avrDatetime->minutes = 0;
    p_avrDatetime->hours = 0;
    p_avrDatetime->days = 1;
    p_avrDatetime->months = 1;
    p_avrDatetime->years_hundreds = 20;
    p_avrDatetime->years_tens = 18;
}

void incrementByOneSecond(){
    p_avrDatetime->seconds++;

    if(!isValidInternClock(p_avrDatetime)){
        p_avrDatetime->seconds = 0;
        p_avrDatetime->minutes++;
        if(minutesNotSynced++ > 60){
            isSynced = false;
        }
        if(!isValidInternClock(p_avrDatetime)){
            p_avrDatetime->minutes = 0;
            p_avrDatetime->hours++;

            if(!isValidInternClock(p_avrDatetime)){
                p_avrDatetime->hours = 0;
                p_avrDatetime->days++;
                p_avrDatetime->weekdayIndex = (p_avrDatetime->weekdayIndex % 7) + 1;

                if(!isValidInternClock(p_avrDatetime)){
                    p_avrDatetime->days = 1;
                    p_avrDatetime->months++;

                    if(!isValidInternClock(p_avrDatetime)){
                        p_avrDatetime->months = 1;
                        p_avrDatetime->years_tens++;

                        if(!isValidInternClock(p_avrDatetime)){
                            p_avrDatetime->years_tens = 0;
                            p_avrDatetime->years_hundreds++;
                        }
                    }
                }
            }
        }
    }
}