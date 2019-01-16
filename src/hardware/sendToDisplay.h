/*******************************************************************************
 * File sendToDisplay.h
 *
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#ifndef ES2018_REPO_SENDTODISPLAY_H
#define ES2018_REPO_SENDTODISPLAY_H

#include <avr/io.h>
#include <inttypes.h>
#include <stdbool.h>

bool instructionNextClock;
uint8_t instructionData;
void init_sendToDisplay();

void setInstructionMode();
void setWriteMode();

void turnDisplayOn();
void turnDisplayOff();
void setEnableBit(uint8_t enableBit);
void setDataPins(uint8_t data);
void wasteTime(uint8_t c);
void setInstructionMode();
void setWriteMode();
void changeRowOnDisplayTo(uint8_t x);
#endif //ES2018_REPO_SENDTODISPLAY_H
