#include <stdio.h>
#include "validDate.h"


// dec: 2018 
// bin: 11111100010
// split in 2Byte:
uint8_t year2018High = 0b00000111;
uint8_t year2018Low = 0b11100010;

// Split in century and decimal year:
uint8_t hundreds = 20;
uint8_t tens = 18;

uint8_t ok = 0;
uint8_t fail = 0;
void printTestResult(char* testDescription, uint8_t testResult, uint8_t expectedResult){
  if(testResult == expectedResult){
    printf("\n%s\nResult: success", testDescription);
    ++ok;
  }else{
    ++fail;
    printf("\n%s\nResult: failed", testDescription);
  }
}

void testDay(){
  char *descr = "TEST- testDay(): value for 'day' above 31 should not be accepted.";


  for(uint8_t i = 32; i < 255; ++i){
      if(!isValidDate(i, 1, year2018High, year2018Low)){
        printf("\n should not accept 'day' value of: %d", i);
        printTestResult(descr, 1, 0 );
        return;
      }
  }
  printTestResult(descr, 0, 0); 
}

void testLeapYear(){
  char *descr = "";
  
  for(uint8_t i = 0; i < 100; ++i){
    if(!isValidDate(29, 2, 20, i)){
      
    }
  }  
}


uint8_t main(uint8_t argc, char** argv){
  testDay();
  return 0;
}
