//
// Created by Jan Uni on 09.11.18.
//


#ifndef ES2018_REPO_TESTFRAMEWORK_H
#define ES2018_REPO_TESTFRAMEWORK_H

#include <inttypes.h>

uint8_t ok;
uint8_t fail;
void printTestResult(char* testDescription, uint8_t ok, char* msg);
void printSuiteName(char* suiteName);

#endif //ES2018_REPO_TESTFRAMEWORK_H
