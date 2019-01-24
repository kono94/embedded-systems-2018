//
// Created by Johann on 23.01.2019.
//

#include "parityChecker.h"
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "../DCF/dcftype.h"
bool areOneBitsOdd(uint8_t startIndex, uint8_t endIndex, bool testDCF[]){
    uint8_t ones = 0;
    for(uint8_t x = startIndex; x < endIndex+1; ++x){
        if(testDCF[x])
            ++ones;
    }
    return !(ones%2);
}

bool checkParity(uint8_t startIndex, uint8_t endIndex, bool testDCF[]){
    if(areOneBitsOdd(startIndex, endIndex, testDCF) == rawDCF[endIndex+1])
        return true;
    else
        return false;
}


bool checkParitiesInDCF(bool testDCF[]){
    //minute parity, hour parity and date parity
    return checkParity(21, 27,testDCF) && checkParity(29, 34,testDCF) && checkParity(36, 57,testDCF);
}



