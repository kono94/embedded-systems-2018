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

void sendWriteData(uint8_t data);
void sendInstructionData(uint8_t instructionData);
void turnDisplayOn();
void turnDisplayOff();
void wasteTime(uint8_t c);
void changeRowOnDisplayTo(uint8_t x);


void setDataPins(uint8_t data);
#endif //ES2018_REPO_SENDTODISPLAY_H
