/*******************************************************************************
 * File validTime.c
 *
 * Checks whether the time (HH:mm:SS) is valid or not
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.11.18
 *******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "validTime.h"

bool isValidTime(uint8_t hours, uint8_t minutes, uint8_t seconds){
  return (hours < 24 && minutes < 60 && seconds < 60);
}

