/*******************************************************************************
 * File testsuite_displayInstructions.c
 *
 * Suite for all tests regarding the instruction management for the display
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 11.01.19
 *******************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include "testFramework.h"
#include "testsuite_displayInstructions.h"
#include "../src/display/displayInstructions.h"
#include "../src/internClock/avrDatetime.h"

#include <stdlib.h>
#include <string.h>

void printOutDisplayData() {
    printf("\n");
    for (int i = 8; i > 0; i--) {
        for (int k = display_toSend; k > 0 ; k--) {
            if ((display_data[display_toSend_currentSession - k] & (1 << i)) > 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void testInstructionInit() {
    init_displayInstructions();

    char *descr = "TEST- testInstructionInit(): Test regarding the initialization of global variables";

    printTestResult(descr, (display_dataLength == 0), "display_dataLength should default 0");
    printTestResult(descr, (display_row == 1), "display_row should ne default 1");
    printTestResult(descr, (display_toSend == 0), "display_toSend should ne default 0");
    printTestResult(descr, (sending_phase == 0), "sending_phase should ne default 0");

}

void testInstructionForRow1() {
    init_displayInstructions();
    AvrDatetime_init();
    char *descr = "TEST- testInstructionForRow1(): First row display test";

    p_avrDatetime->hours = 12;
    p_avrDatetime->minutes = 45;
    p_avrDatetime->seconds = 06;

    setInstructionsForRow(1);
    printTestResult(descr, (display_toSend == 48), "display_toSend should be 48 in first row");
    printTestResult(descr, (display_toSend_currentSession == 48), "display_toSend_currentSession should be 48 in first row");

    printOutDisplayData();
}


void testInstructionForRow2() {
    init_displayInstructions();
    AvrDatetime_init();


    char *descr = "TEST- testInstructionForRow2(): Second row display test";

    p_avrDatetime->days = 07;
    p_avrDatetime->months = 1;
    p_avrDatetime->years_hundreds = 20;
    p_avrDatetime->years_tens = 19;

    setInstructionsForRow(2);
    printTestResult(descr, (display_toSend == 60), "display_toSend should be 60 in second row");
    printTestResult(descr, (display_toSend_currentSession == 60),
                    "display_toSend_currentSession should be 60 in second row");

    printOutDisplayData();
}



void testInstructionForRow3(){
    init_displayInstructions();

    AvrDatetime_init();


    char *descr = "TEST- testInstructionForRow3(): Third row display test";


    p_avrDatetime->weekdayIndex = 1;

    setInstructionsForRow(3);
    printTestResult(descr, (display_toSend == 12), "display_toSend should be 12 in third row");
    printTestResult(descr, (display_toSend_currentSession == 12), "display_toSend_currentSession should be 12 in third row");

    printOutDisplayData();
}

void testStoppingOfSendingRows(){
    init_displayInstructions();

    char *descr = "TEST- testStoppingOfSendingRows(): Stop setting instructions if all is done";

    printTestResult(descr, (display_toSend == 0), "fresh init of display_toSend should be 0");
    setInstructionsForRow(4);
    printTestResult(descr, (display_toSend == 0), "should not set 'display_toSend' if instructionRow equals 4");
}




uint8_t runTestsuite_displayInstructions(){
    printSuiteName("TEST SUITE FOR DISPLAY INSTRUCTIONS");
    testInstructionInit();
    testInstructionForRow1();
    testInstructionForRow2();
    testInstructionForRow3();
    testStoppingOfSendingRows();
    return 0;
}
