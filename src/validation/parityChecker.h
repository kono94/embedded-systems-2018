//
// Created by Johann on 23.01.2019.
//

#ifndef ES2018_REPO_PARITYCHECKER_H
#define ES2018_REPO_PARITYCHECKER_H
#include <stdbool.h>
#include <inttypes.h>
#include "../DCF/dcftype.h"

bool checkParitiesInDCF(DCF testDCF);
bool checkParity(uint8_t startIndex, uint8_t endIndex, DCF testDCF);

#endif //ES2018_REPO_PARITYCHECKER_H