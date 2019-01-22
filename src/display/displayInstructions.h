//
// Created by Jan Uni on 09.01.19.
//

#ifndef ES2018_REPO_DISPLAYINSTR_H
#define ES2018_REPO_DISPLAYINSTR_H
#include <inttypes.h>
#include <stdbool.h>

uint8_t display_dataLength;
uint8_t display_row;
uint8_t display_data[128];
uint8_t display_toSend;
uint8_t display_toSend_currentSession;
uint8_t sending_phase;

void init_displayInstructions();
void sendToDisplay();
bool setInstructionsForRow(uint8_t);

#endif //ES2018_REPO_DISPLAYINSTR_H
