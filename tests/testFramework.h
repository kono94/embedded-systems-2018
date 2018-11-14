/*******************************************************************************
 * File testFramework.h
 *
 * Offers functions that allow a unified and well formatted output
 * of test results.
 *
 * Author: Jan Löwenstrom
 * Date: 09.11.18
 *******************************************************************************/

#ifndef ES2018_REPO_TESTFRAMEWORK_H
#define ES2018_REPO_TESTFRAMEWORK_H

#include <inttypes.h>

/*
 * total amount of tests that succeeded
 */
uint8_t ok;

/*
 * total amount of tests that failed
 */
uint8_t fail;

/*
 * prints test description, a short description of the expected result
 * and the outcome of the test itself
 */
void printTestResult(char* testDescription, uint8_t ok, char* msg);

/*
 * prints a fancy "*"-based rectangle with the name of test suite inside
 */
void printSuiteName(char* suiteName);

#endif //ES2018_REPO_TESTFRAMEWORK_H
