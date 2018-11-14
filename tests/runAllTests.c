/*******************************************************************************
 * File runAllTests.c
 *
 * Calls all test suites.
 *
 * Author: Jan Löwenstrom
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

int main(int argc, char** argv){
    runTestsuite_validDate();
    runTestsuite_validTime();
    runTestsuite_bitConverter();
    printf(GRN "\n TEST OK: %d \n" RED " TEST FAILED: %d \n" RESET, ok, fail);
    return 0;
}