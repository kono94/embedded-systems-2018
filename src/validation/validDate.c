/*******************************************************************************
 * File validDate.c
 *
 * //TODO: description
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.11.18
 *******************************************************************************/

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
      return (hundreds % 4 == 0);
  }else
     return (tens % 4 == 0);
}

bool isValidDay(uint8_t day, uint8_t month, uint8_t leapYear){
  if(month != 2 && month < 8){

    return ((month % 2 == 0 && day < 31) || (month % 2 == 1 && day < 32));

  }else if(month != 2 && month > 7 && month < 13){

    return ((month % 2 == 1 && day < 31) || (month % 2 == 0 && day < 32));

  }else if(month == 2){
      return ((leapYear && day < 30) || (!leapYear && day < 29));
  }else
    return false;
}
