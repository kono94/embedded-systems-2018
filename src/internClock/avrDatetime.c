//
// Created by Jan Uni on 30.11.18.
//
#include "avrDatetime.h"
#include <inttypes.h>


void AvrDatetime_init(){
    p_avrDatetime = &avrDatetime;
    p_avrDatetime->minutes = 0;
    p_avrDatetime->hours = 0;
    p_avrDatetime->days = 1;
    p_avrDatetime->months = 1;
    p_avrDatetime->years_hundreds = 20;
    p_avrDatetime->years_tens = 18;
}