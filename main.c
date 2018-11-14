//
// Created by Jan Uni on 14.11.18.
//
#include <stdio.h>
#include "DCF/dcftype.h"
#include "util/dateExtractor.h"

int main(int argc, char** argv){
    DCF_init();
    printf("%d" , getCalendarDay(&rawDCF));
    return 0;
}