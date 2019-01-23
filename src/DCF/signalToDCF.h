//
// Created by Jan Uni on 14.12.18.
//

#ifndef ES2018_REPO_SIGNALTODCF_H
#define ES2018_REPO_SIGNALTODCF_H
#include <inttypes.h>
#include <stdbool.h>

void evaluateSignal(uint8_t);
bool dcfErrorState;
uint8_t g_position;
uint16_t minutesNotSynced;
bool isSynced;
#endif //ES2018_REPO_SIGNALTODCF_H
