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

void turnDisplayOn();
void setEnableBit(uint8_t enableBit);
void setDataPins(uint8_t data);

#endif //ES2018_REPO_SENDTODISPLAY_H
