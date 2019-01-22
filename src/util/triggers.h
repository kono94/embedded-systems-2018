/*******************************************************************************
 * File triggers.h
 *
 *
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 09.01.19
 *******************************************************************************/

#ifndef ES2018_REPO_TRIGGERS_H
#define ES2018_REPO_TRIGGERS_H

#include <stdbool.h>

void init_triggers();

volatile bool trigger_sentToDisplay;
volatile bool trigger_evaluateSignal;
volatile bool trigger_oneSecondPassed;

#endif //ES2018_REPO_TRIGGERS_H
