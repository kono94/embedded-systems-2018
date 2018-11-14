#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "validDate.h"


bool isValidDate(uint8_t day, uint8_t month, uint8_t hundreds, uint8_t tens){
  uint8_t leapYear = isLeapYear(hundreds, tens);
  return isValidDay(day, month, leapYear);
}

bool isLeapYear(uint8_t hundreds, uint8_t tens){
  if(tens == 0){
    if(hundreds % 4 == 0)
      return true;
    else
      return false;
  }else if(tens % 4 == 0)
    return true;
  else
    return false;
}

bool isValidDay(uint8_t day, uint8_t month, uint8_t leapYear){
  if(month != 2 && month < 8){
    if(month % 2 == 0 && day < 31)
      return true;
    else if(month % 2 == 1 && day < 32)
      return true;
    else
      return false;
  }else if(month != 2 && month > 7 && month < 13){
    if(month % 2 == 1 && day < 31)
      return true;
    else if(month % 2 == 0 && day < 32)
      return true;
    else
      return false;
  }else if(month == 2){
    if(leapYear && day < 30)
      return true;
    else if(!leapYear && day < 29)
      return true;
    else
      return false;
  }else
    return false;
}
