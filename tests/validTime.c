#include <stdio.h>
#include "validTime.h"
#include <inttypes.h>


uint8_t isValidTime(uint8_t hours, uint8_t minutes){
  if(hours < 24 && minutes < 60)
    return 1;
  else
    return 0;
}
