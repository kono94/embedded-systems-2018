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
void printTestResult(char* testDescription, uint8_t ok, char* msg){
  if(ok){
    printf("\n\n\n%s \n %s \nResult: success", testDescription, msg);
    ++ok;
  }else{
    ++fail;
    printf("\n\n\n%s \n %s\nResult: failed",  testDescription, msg);

  }
}

void testDay(){
  char *descr = "TEST- testDay(): value for 'day' above 31 should not be accepted.";


  for(uint8_t i = 32; i < 255; ++i){
      if(!isValidDate(i, 1, year2018High, year2018Low)){
        printTestResult(descr, 1, " - should not accept 'day' value above 31");
        return;
      }
  }
  printTestResult(descr, 0, 0); 
}

void tesstLeapYear(){
  char *descr = "TEST- testLeapYear(): 29.02 should be accepted if leap year and declined if not a leap year";
  
  printTestResult(descr, isValidDate(29,2,20,0), "should accept 29.02.2000"); 

  for(uint8_t i = 1; i < 100; ++i){
    if(i%4 == 0 && !isValidDate(29,2,20,i))
     {
       printTestResult(descr, 0, " - should accept 29.02 in leap year");
       return;
     }
    
    if(i%4 != 0 && isValidDate(29,2,20,i)){
      printTestResult(descr, 1, " - should not accept 29.02 in none leap year");
      return;
    }  
  }
}

uint8_t main(uint8_t argc, char** argv){
  testDay();
  tesstLeapYear();
  return 0;
}
