#include <stdio.h>
#include "validDate.h"
#include <inttypes.h>
uint8_t isValidDate(uint8_t day, uint8_t month, uint8_t hundreds, uint8_t tens){
  int leapYear = testLeapYear(hundreds, tens);
  int validDay = isValidDay(day, month, leapYear);
  return validDay;
}

int testLeapYear(int hundreds, int tens){
  if(tens == 0){
    if(hundreds % 4 == 0)
      return 1;
    else
      return 0;
  }else if(tens % 4 == 0)
    return 1;
  else
    return 0;
}

int isValidDay(int day, int month, int leapYear){
  if(month != 2 && month < 8){
    if(month % 2 == 0 && day < 31)
      return 1;
    else if(month % 2 == 1 && day < 32)
      return 1;
    else
      return 0;
  }else if(month != 2 && month > 7 && month < 13){
    if(month % 2 == 1 && day < 31)
      return 1;
    else if(month % 2 == 0 && day < 32)
      return 1;
    else
      return 0;
  }else if(month == 2){
    if(leapYear && day < 30)
      return 1;
    else if(!leapYear && day < 29)
      return 1;
    else
      return 0;
  }else
    return 0;
}
