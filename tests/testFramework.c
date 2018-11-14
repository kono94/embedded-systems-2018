/*******************************************************************************
 * File testFramework.c
 *
 * Offers functions that allow a unified and well formatted output
 * of test results.
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
#include <inttypes.h>
#include "testFramework.h"

uint8_t ok = 0;
uint8_t fail = 0;

void printTestResult(char* testDescription, uint8_t didTestFail, char* msg){
    if(didTestFail){
        printf("\n%s \n %s \nResult:" GRN " success\n" RESET, testDescription, msg);
        ++ok;
    }else{
        ++fail;
        printf("\n%s \n %s\nResult:" RED " failed\n" RESET,  testDescription, msg);

    }
}

void printSuiteName(char* suiteName){
    printf("\n\n****************************************\n");
    printf("**                                    **\n");
    printf("**     %s      **\n", suiteName);
    printf("**                                    **\n");
    printf("****************************************\n\n");
}