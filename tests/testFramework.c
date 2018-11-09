//
// Created by Jan Uni on 09.11.18.
//

#include "testFramework.h"
#include <stdio.h>
#include <inttypes.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define RESET "\x1B[0m"

uint8_t ok = 0;
uint8_t fail = 0;
void printTestResult(char* testDescription, uint8_t ok, char* msg){
    if(ok){
        printf("\n\n\n%s \n %s \nResult:" GRN " success" RESET, testDescription, msg);
        ++ok;
    }else{
        ++fail;
        printf("\n\n\n%s \n %s\nResult:" RED " failed" RESET,  testDescription, msg);

    }
}