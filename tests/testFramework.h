//
// Created by Jan Uni on 09.11.18.
//
#include <inttypes.h>

#ifndef ES2018_REPO_TESTFRAMEWORK_H
#define ES2018_REPO_TESTFRAMEWORK_H

uint8_t ok;
uint8_t fail;
void printTestResult(char* testDescription, uint8_t ok, char* msg);

#endif //ES2018_REPO_TESTFRAMEWORK_H
