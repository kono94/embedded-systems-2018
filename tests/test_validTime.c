#include <stdio.h>
#include "validTime.h"
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

void testEdgeCases(){
  char *descr = "TEST- testEdgeCase(): special cases";

  printTestResult(descr, isValidTime(0,0), " - should accept the time 00:00");
  printTestResult(descr, isValidTime(23,59), " - should accept the time 23:59");
  printTestResult(descr, !isValidTime(24, 0), " - should not accept the time 24:00");
}

void testMinutes(){
  char *descr = "TEST- testMinutes(): should accept minutes from 0 to 59, reject > 59";

  for(uint8_t i = 0; i < 60; ++i){
    if(!isValidTime(1, i))
    {
      printTestResult(descr, 0, " - should accept minutes < 60");
      return;
    } 
  }

  for(uint8_t i = 60; i < 255; ++i){
    if(isValidTime(1, i))
    {
      printTestResult(descr, 0, " - should not accept minutes > 59");
      return;
    } 
  }
}

void testHours(){
  char* descr = "TEST - testHours(): should accept hours from 0 to 23, reject > 23";

  for(uint8_t i = 0; i < 24; ++i){
    if(!isValidTime(i, 0))
    {
      printTestResult(descr, 0, " - should accept hours < 24");
      return;
    } 
  }

  for(uint8_t i = 24; i < 255; ++i){
    if(isValidTime(i, 0))
    {
      printTestResult(descr, 0, " - should not accept hours > 23");
      return;
    } 
  }
}

void positiveSamples(){
  char* descr = "TEST - positiveSamples(): should accept all examples";

  printTestResult(descr, isValidTime(0,23), " - should accept 0:23");
  printTestResult(descr, isValidTime(14,24), " - should accept 14:24");
  printTestResult(descr, isValidTime(12,58), " - should accept 12:58");
  printTestResult(descr, isValidTime(20,15), " - should accept 20:15");
  printTestResult(descr, isValidTime(7,7), " - should accept 7:07");
}

void negativeSamples(){
  char* descr = "TEST - negativeSamples(): should decline all examples";

  printTestResult(descr, !isValidTime(24,52), " - should not accept 24:52");
  printTestResult(descr, !isValidTime(233,0), " - should not accept 233:00");
  printTestResult(descr, !isValidTime(4,60), " - should not accept 4:60");
  printTestResult(descr, !isValidTime(23,200), " - should not accept 23:200");
  printTestResult(descr, !isValidTime(88,33), " - should not accept 88:33");
}

uint8_t main(uint8_t argc, char** argv){
  testEdgeCases();
  testMinutes();
  testHours();
  positiveSamples();
  negativeSamples();
  printf("\n");
  return 0;
}
