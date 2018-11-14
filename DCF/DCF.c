//
// Created by Jan Uni on 14.11.18.
//

#include "DCF.h"
#include "../util/bitConverter.h"
void DCF_init(){
    DCF_LENGTH = 59;

    // initialize dcf-Array
    for(uint8_t i=0; i < DCF_LENGTH; ++i){
        rawDCF[i] = 0;
    }
}

