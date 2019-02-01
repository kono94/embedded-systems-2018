/*******************************************************************************
 * File sendToDisplay.h
 *
 * Defines and offers functions to interact with the display.
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
void resetDisplay();
void sendEmptyDI();
void clearDisplay();
#define F_CPU 16000000UL

void setDataPins(uint8_t data);
#endif //ES2018_REPO_SENDTODISPLAY_H
