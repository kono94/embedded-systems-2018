//
// Created by Jan Uni on 09.11.18.
//

#include <stdio.h>
#include <inttypes.h>
#include "testFramework.h"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

uint8_t ok = 0;
uint8_t fail = 0;

void printTestResult(char* testDescription, uint8_t ok, char* msg){
    if(ok){
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