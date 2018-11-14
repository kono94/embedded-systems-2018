//
// Created by Jan Uni on 14.11.18.
//


#ifndef ES2018_REPO_DCF_H
#define ES2018_REPO_DCF_H
#include <stdbool.h>
#include <inttypes.h>


uint8_t DCF_LENGTH;
typedef bool DCF[59];
DCF rawDCF;
void DCF_init();
#endif //ES2018_REPO_DCF_H
