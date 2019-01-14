/*******************************************************************************
 * File fontants.h
 *
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#ifndef ES2018_REPO_FONTANSTS_H
#define ES2018_REPO_FONTANSTS_H
#include <inttypes.h>

#define font_width 6

extern uint8_t CHAR_ZERO[];
extern uint8_t CHAR_ONE[];
extern uint8_t CHAR_TWO[];
extern uint8_t CHAR_THREE[];
extern uint8_t CHAR_FOUR[];
extern uint8_t CHAR_FIVE[];
extern uint8_t CHAR_SIX[];
extern uint8_t CHAR_SEVEN[];
extern uint8_t CHAR_EIGHT[];
extern uint8_t CHAR_NINE[];
extern uint8_t CHAR_M[];
extern uint8_t CHAR_D[];
extern uint8_t CHAR_F[];
extern uint8_t CHAR_S[];
extern uint8_t CHAR_i[];
extern uint8_t CHAR_o[];
extern uint8_t CHAR_r[];
extern uint8_t CHAR_a[];
extern uint8_t CHAR_DOUBLE_POINTS[];
extern uint8_t CHAR_SINGLE_POINT[];
extern uint8_t CHAR_EMPTY[];
extern uint8_t CHAR_INVALID[];

uint8_t* getInstructionFromNumber(uint8_t n);
uint8_t* getInstructionFromWeekdayIndex(uint8_t weekdayIndex);

#endif //ES2018_REPO_FONTANSTS_H
