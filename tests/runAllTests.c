/*******************************************************************************
 * File runAllTests.c
 *
 * Calls all test suites.
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.11.18
 *******************************************************************************/

/*
 * Defines constants for colored output:
 * SUCCESS -> green text
 * FAIL -> red text
 *
 * and the default color to switch back to the original color
 */
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

#include <stdio.h>
#include "runAllTests.h"
#include "testFramework.h"
#include "testsuite_validDate.h"
#include "testsuite_validTime.h"
#include "testsuite_bitConverter.h"
#include "testsuite_dateExtractor.h"
#include "testsuite_incrementInternClock.h"
#include "testsuite_displayInstructions.h"
#include "testsuite_parityChecker.h"

int main(int argc, char** argv){
    runTestsuite_parityChecker();
    //runTestsuite_validDate();
    //runTestsuite_validTime();
    //runTestsuite_bitConverter();
    //runTestsuite_incrementInternClock();
    //runTestsuite_dateExtractor();
    //runTestsuite_displayInstructions();
    printf(GRN "\n TEST OK: %d \n" RED " TEST FAILED: %d \n" RESET, ok, fail);
    return 0;
}