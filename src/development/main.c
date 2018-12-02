//
// Created by Jan Uni on 02.12.18.
//

#include "main.h"
#include <stdio.h>
#include <inttypes.h>
#include "../util/dateExtractor.h"
#include "../internClock/avrDatetime.h"


int main(int argc, char** argv){
    DCF_init();
    AvrDatetime_init();

    return 0;
}