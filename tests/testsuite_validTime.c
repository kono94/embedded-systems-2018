/*******************************************************************************
 * File testsuite_validTime.c
 *
 * Suite for all tests regarding the validation of a given time in minutes and hours
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.11.18
 *******************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include "testFramework.h"
#include "../src/validation/validTime.h"

void testEdgeCases(){
  char *descr = "TEST- testEdgeCase(): special cases";

  printTestResult(descr, isValidTime(0,0,0), " - should accept the time 00:00:00");
  printTestResult(descr, isValidTime(23,59,59), " - should accept the time 23:59:59");
  printTestResult(descr, !isValidTime(24,0 ,0), " - should not accept the time 24:00:00");
}

void testMinutes(){
  char *descr = "TEST- testMinutes(): should accept minutes from 0 to 59, reject > 59";

  for(uint8_t i = 0; i < 60; ++i){
    if(!isValidTime(1, i, 0))
    {
      printTestResult(descr, 0, " - should accept minutes < 60");
      return;
    } 
  }

  for(uint8_t i = 60; i < 255; ++i){
    if(isValidTime(1, i, 0))
    {
      printTestResult(descr, 0, " - should not accept minutes > 59");
      return;
    } 
  }
}

void testHours(){
  char* descr = "TEST - testHours(): should accept hours from 0 to 23, reject > 23";

  for(uint8_t i = 0; i < 24; ++i){
    if(!isValidTime(i, 0, 0))
    {
      printTestResult(descr, 0, " - should accept hours < 24");
      return;
    } 
  }

  for(uint8_t i = 24; i < 255; ++i){
    if(isValidTime(i, 0, 0))
    {
      printTestResult(descr, 0, " - should not accept hours > 23");
      return;
    } 
  }
}

void positiveTimeSamples(){
  char* descr = "TEST - positiveSamples(): should accept all examples";

  printTestResult(descr, isValidTime(0,23,22), " - should accept 0:23:22");
  printTestResult(descr, isValidTime(14,24,59), " - should accept 14:24:59");
  printTestResult(descr, isValidTime(12,58,12), " - should accept 12:58:12");
  printTestResult(descr, isValidTime(20,15,7), " - should accept 20:15:07");
  printTestResult(descr, isValidTime(7,7,9), " - should accept 7:07:09");
}

void negativeTimeSamples(){
  char* descr = "TEST - negativeSamples(): should decline all examples";

  printTestResult(descr, !isValidTime(24,52,22), " - should not accept 24:52:22");
  printTestResult(descr, !isValidTime(233,0,99), " - should not accept 233:00:99");
  printTestResult(descr, !isValidTime(4,60,10), " - should not accept 4:60:10");
  printTestResult(descr, !isValidTime(23,200,27), " - should not accept 23:200:27");
  printTestResult(descr, !isValidTime(88,33,57), " - should not accept 88:33:57");
  printTestResult(descr, !isValidTime(4,33,61), " - should not accept 4:33:61");

}

uint8_t runTestsuite_validTime(){
    printSuiteName("TEST SUITE FOR VALID_TIME");
    testEdgeCases();
    testMinutes();
    testHours();
    positiveTimeSamples();
    negativeTimeSamples();
    return 0;
}
