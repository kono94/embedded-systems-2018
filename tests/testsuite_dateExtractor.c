//
// Created by Johann on 15.11.2018.
//

#include <stdbool.h>
#include <inttypes.h>
#include "../src/util/dateExtractor.h"
#include "testsuite_bitConverter.h"
#include "testFramework.h"
#include "../src/util/bitConverter.h"
#include "../src/DCF/dcftype.h"
/*
void setBits(bool bits[], uint8_t i0, uint8_t i1) {
    for (int i = i0; i < i1; ++i)
        rawDCF[i] = bits[i-i0];
}

void testGetMinute(){
    char* descr = "TEST- getMinute(): convert  bits 21-27 to responding decimal values";
    bool array[7] = {1,0,0,0,0,0,0};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 1, "0000001 should be 1");

    array = {0,1,0,0,0,0,0};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 2, "0000010 should be 2");
/*
    array = {0,0,1,0,0,0,0};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 4, "0000100 should be 4");

    array = {0,0,0,1,0,0,0};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 8, "0001000 should be 8");

    array = {0,0,0,0,1,0,0};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 10, "0010000 should be 10");

    array = {0,0,0,0,0,1,0};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 20, "0100000 should be 20");

    array = {0,0,0,0,0,0,1};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 40, "1000000 should be 40");

    array = {1,1,0,1,1,0,0};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 21, "0011011 should be 21");

    array = {0,1,0,1,0,1,1};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 70, "1101010 should be 70");

    array = {1,1,1,1,1,0,1};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 65, "1011111 should be 65");

    array = {1,1,1,1,1,1,0};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 45, "0111111 should be 45");

    array = {1,1,1,1,1,1,1};
    setBits(&array, 21, 28);
    printTestResult(descr, getMinutes(&rawDCF) == 85, "1111111 should be 85");

    }
    */

/*
void testGetHour(){
    char* descr = "TEST- getHour(): convert  bits 29-34 to responding decimal values";
    bool array[6] = {1,0,0,0,0,0};
    setBits(&array, 29, 35);
    printTestResult(descr, getHours(&rawDCF) == 1, "000001 should be 1");
    array = {0,1,0,0,0,0};
    setBits(&array, 29, 35);
    printTestResult(descr, getHours(&rawDCF) == 2, "000010 should be 2");
    array = {0,0,1,0,0,0};
    setBits(&array, 29, 35);
    printTestResult(descr, getHours(&rawDCF) == 4, "000100 should be 4");
    array = {0,0,0,1,0,0};
    setBits(&array, 29, 35);
    printTestResult(descr, getHours(&rawDCF) == 8, "001000 should be 8");
    array = {0,0,0,0,1,0};
    setBits(&array, 29, 35);
    printTestResult(descr, getHours(&rawDCF) == 10, "010000 should be 10");
    array = {0,0,0,0,0,1};
    setBits(&array, 29, 35);
    printTestResult(descr, getHours(&rawDCF) == 20, "100000 should be 20");
    array = {1,0,1,0,1,1};
    setBits(&array, 29, 35);
    printTestResult(descr, getHours(&rawDCF) == 35, "110101 should be 35");
    array = {1,1,1,1,0,1};
    setBits(&array, 29, 35);
    printTestResult(descr, getHours(&rawDCF) == 35, "101111 should be 35");
    array = {1,1,1,1,1,0};
    setBits(&array, 29, 35);
    printTestResult(descr, getHours(&rawDCF) == 25, "011111 should be 25");
}

void testGetCalendarDay(){
    char* descr = "TEST- getCalendarDay(): convert  bits 36-41 to responding decimal values";
    bool array[6] = {1,0,0,0,0,0};
    setBits(&array, 36, 42);
    printTestResult(descr, getCalendarDay(&rawDCF) == 1, "000001 should be 1");
    array = {0,1,0,0,0,0};
    setBits(&array, 36, 42);
    printTestResult(descr, getCalendarDay(&rawDCF) == 2, "000010 should be 2");
    array = {0,0,1,0,0,0};
    setBits(&array, 36, 42);
    printTestResult(descr, getCalendarDay(&rawDCF) == 4, "000100 should be 4");
    array = {0,0,0,1,0,0};
    setBits(&array, 36, 42);
    printTestResult(descr, getCalendarDay(&rawDCF) == 8, "001000 should be 8");
    array = {0,0,0,0,1,0};
    setBits(&array, 36, 42);
    printTestResult(descr, getCalendarDay(&rawDCF) == 10, "010000 should be 10");
    array = {0,0,0,0,0,1};
    setBits(&array, 36, 42);
    printTestResult(descr, getCalendarDay(&rawDCF) == 20, "100000 should be 20");
    array = {1,0,1,0,1,1};
    setBits(&array, 36, 42);
    printTestResult(descr, getCalendarDay(&rawDCF) == 35, "110101 should be 35");
    array = {1,0,1,1,1,1};
    setBits(&array, 36, 42);
    printTestResult(descr, getCalendarDay(&rawDCF) == 35, "101111 should be 35");
    array = {1,1,1,1,1,0};
    setBits(&array, 36, 42);
    printTestResult(descr, getCalendarDay(&rawDCF) == 25, "011111 should be 25");
}

void testGetCalendarMonth(){
    char* descr = "TEST- getCalendarMonth(): convert  bits 45-49 to responding decimal values";
    bool array[5] = {1,0,0,0,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 1, "00001 should be 1");
    array = {0,1,0,0,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 2, "00010 should be 2");
    array = {1,1,0,0,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 3, "00011 should be 3");
    array = {0,0,1,0,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 4, "00100 should be 4");
    array = {1,0,1,0,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 5, "00101 should be 5");
    array = {0,1,1,0,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 6, "00110 should be 6");
    array = {1,1,1,0,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 7, "00111 should be 7");
    array = {0,0,0,1,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 8, "01000 should be 8");
    array = {1,0,0,1,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 9, "01001 should be 9");
    array = {0,1,0,1,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 10, "01010 should be 10");
    array = {1,0,0,0,1};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 11, "10001 should be 11");
    array = {0,1,0,0,1};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 12, "10010 should be 12");
    array = {0,1,1,0,0};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 12, "00110 should be 12");
    array = {1,1,1,1,1};
    setBits(&array, 45, 50);
    printTestResult(descr, getCalendarMonth(&rawDCF) == 25, "11111 should be 25");
}

void testGetCalendarYears(){
    char* descr = "TEST- getCalendarYears(): convert  bits 50-57 to responding decimal values";
    bool array[7] = {1,0,0,0,0,0,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 1, "00000001 should be 1");
    array = {0,1,0,0,0,0,0,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 2, "00000010 should be 2");
    array = {0,0,1,0,0,0,0,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 4, "00000100 should be 4");
    array = {0,0,0,1,0,0,0,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 8, "00001000 should be 8");
    array = {0,0,0,0,1,0,0,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 10, "00010000 should be 10");
    array = {0,0,0,0,0,1,0,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 20, "00100000 should be 20");
    array = {0,0,0,0,0,0,1,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 40, "01000000 should be 40");
    array = {0,0,0,0,0,0,0,1};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 80, "10000000 should be 80");
    array = {1,0,0,0,0,1,0,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 21, "00100001 should be 21");
    array = {0,0,0,0,1,1,1,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 70, "01110000 should be 70");
    array = {1,0,1,0,0,1,1,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 65, "01100101 should be 65");
    array = {1,1,1,1,0,0,1,0};
    setBits(&array, 50, 58);
    printTestResult(descr, getCalendarYears(&rawDCF) == 45, "01001111 should be 45");
}

void testGetWeekdayString(){
    char* descr = "TEST- getWeekdayString(): convert  bits 42-44 to responding decimal values";
    bool array[3] = {1,0,0};
    setBits(&array, 42, 45);
    printTestResult(descr, getWeekdayString(&rawDCF) == "ERROR34", "000 should be Error");
    bool array[] = {1,0,0};
    setBits(&array, 42, 45);
    printTestResult(descr, getWeekdayString(&rawDCF) == "Mon", "001 should be Mon");
    bool array[] = {0,1,0};
    setBits(&array, 42, 45);
    printTestResult(descr, getWeekdayString(&rawDCF) == "Tue", "010 should be Tue");
    bool array[] = {1,1,0};
    setBits(&array, 42, 45);
    printTestResult(descr, getWeekdayString(&rawDCF) == "Wed", "011 should be Wed");
    bool array[] = {0,0,1};
    setBits(&array, 42, 45);
    printTestResult(descr, getWeekdayString(&rawDCF) == "Thu", "100 should be Thu");
    bool array[] = {1,0,1};
    setBits(&array, 42, 45);
    printTestResult(descr, getWeekdayString(&rawDCF) == "Fri", "101 should be Fri");
    bool array[] = {0,1,1};
    setBits(&array, 42, 45);
    printTestResult(descr, getWeekdayString(&rawDCF) == "Sat", "110 should be Sat");
    bool array[] = {1,1,1};
    setBits(&array, 42, 45);
    printTestResult(descr, getWeekdayString(&rawDCF) == "Sun", "111 should be Sun");
}
*/
void runTestsuite_dateExtractor(){
    /*testGetCalendarDay();
    testGetCalendarMonth();
    testGetCalendarYears();
    testGetHour();
         testGetWeekdayString();
testGetMinute();
     */


}



