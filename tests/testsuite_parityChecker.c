//
// Created by Johann on 24.01.2019.
//

#include <stdio.h>
#include <inttypes.h>
#include "testFramework.h"
#include "../src/validation/parityChecker.h"
#include "../src/DCF/dcftype.h"
#include <stdlib.h>
#include <string.h>

void runTestsuite_parityChecker(){
    char* descr = "TEST- checkParitiesInDCF(): checking parities";
    const DCF testDCF = {0,0,1,0,0,0,0,1,1,0,
                         1,0,0,0,0,0,0,1,0,0,1,
                         1,0,1,0,1,0,0,  1,
                         0,1,1,0,1,0, 1,
                         1,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,0,0, 0};
    printTestResult(descr, checkParity(21,27,testDCF), "minute parity should correct (0)");
    printTestResult(descr, checkParity(29,34,testDCF), "hour parity should be correct (0)");
    printTestResult(descr, checkParity(36,57,testDCF), "date parity should be correct(1)");
}