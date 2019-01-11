/*******************************************************************************
 * File fontConstants.h
 *
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#ifndef ES2018_REPO_FONTCONSTANSTS_H
#define ES2018_REPO_FONTCONSTANSTS_H
#include <inttypes.h>


uint_8 font_width = 6;

uint_8 CHAR_ZERO[6];
uint_8 CHAR_ONE[6];
uint_8 CHAR_TWO[6];
uint_8 CHAR_THREE[6];
uint_8 CHAR_FOUR[6];
uint_8 CHAR_FIVE[6];
uint_8 CHAR_SIX[6];
uint_8 CHAR_SEVEN[6];
uint_8 CHAR_EIGHT[6];
uint_8 CHAR_NINE[6];
uint_8 CHAR_M[6];
uint_8 CHAR_D[6];
uint_8 CHAR_F[6];
uint_8 CHAR_S[6];
uint_8 CHAR_i[6];
uint_8 CHAR_o[6];
uint_8 CHAR_r[6];
uint_8 CHAR_a[6];
uint_8 CHAR_DOUBLE_POINTS[6];
uint_8 CHAR_SINGLE_POINT[6];
uint_8 CHAR_EMPTY[6];


void init_fontConstants();
uint_8* getInstructionFromNumber(uint_t n);
uint_8* getInstructionFromWeekdayIndex(uint_t weekdayIndex);

#endif //ES2018_REPO_FONTCONSTANSTS_H
