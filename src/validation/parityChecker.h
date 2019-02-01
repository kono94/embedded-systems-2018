/*******************************************************************************
 * File parityChecker.h
 *
 * Makes sure that the received DCF signal has valid
 * parity bits and the message is valid.
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 23.01.19
 *******************************************************************************/
#ifndef ES2018_REPO_PARITYCHECKER_H
#define ES2018_REPO_PARITYCHECKER_H
#include <stdbool.h>
#include <inttypes.h>
#include "../dcf/dcftype.h"

bool checkParitiesInDCF(const DCF testDCF);
bool checkParity(uint8_t startIndex, uint8_t endIndex, const DCF testDCF);

#endif //ES2018_REPO_PARITYCHECKER_H
