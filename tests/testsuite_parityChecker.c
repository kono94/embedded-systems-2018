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
    bool testDCF[] = {0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,0,0,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,1,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1};
    printTestResult(descr, checkParity(21,27,testDCF) == 1, "not all parities should be right");
    printTestResult(descr, checkParity(21,27,testDCF) == 1, "minute parity should be right");
    printTestResult(descr, checkParity(29,34,testDCF) == 1, "hour parity should be right");
    printTestResult(descr, checkParity(36,57,testDCF) == 0, "date parity should not be right");
}