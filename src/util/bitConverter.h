/*******************************************************************************
 * File bitConverter.h
 *
 * Offers function to convert binary to decimal.
 * Parameters represent single bits.
 *
 * e.q:
 * bit1 = 0
 * bit2 = 1
 * bit3 = 1
 * bit4 = 1
 *
 * binary-number: 1110
 *
 * converted to decimal by:
 *
 * 0*1 + 1*2 + 1*4 + 1*8 = 14
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 14.11.18
 *******************************************************************************/


#ifndef ES2018_REPO_BITCONVERTER_H
#define ES2018_REPO_BITCONVERTER_H

#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

uint8_t helper_2bit(bool bit1, bool bit2);
uint8_t helper_3bit(bool bit1, bool bit2, bool bit3);
uint8_t helper_4bit(bool bit1, bool bit2, bool bit3, bool bit4);

#endif //ES2018_REPO_BITCONVERTER_H
