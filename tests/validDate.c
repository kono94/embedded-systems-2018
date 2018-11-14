#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "validDate.h"



uint8_t isValidDate(uint8_t day, uint8_t month, uint8_t hundreds, uint8_t tens){
  uint8_t leapYear = testLeapYear(hundreds, tens);
  uint8_t validDay = isValidDay(day, month, leapYear);
  return validDay;
}

uint8_t testLeapYear(uint8_t hundreds, uint8_t tens){
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

uint8_t isValidDay(uint8_t day, uint8_t month, uint8_t leapYear){
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
