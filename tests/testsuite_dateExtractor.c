//
// Created by Johann on 15.11.2018.
//

#include <stdbool.h>
#include <inttypes.h>
#include <string.h>
#include "../src/util/dateExtractor.h"
#include "testsuite_bitConverter.h"
#include "testFramework.h"
#include "../src/util/bitConverter.h"
#include "../src/DCF/dcftype.h"

void set8Bits(uint8_t i0, uint8_t i1, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint8_t b5, uint8_t b6, uint8_t b7) {
    rawDCF[i0 + 0] = b0;
    rawDCF[i0 + 1] = b1;
    rawDCF[i0 + 2] = b2;
    rawDCF[i0 + 3] = b3;
    rawDCF[i0 + 4] = b4;
    rawDCF[i0 + 5] = b5;
    rawDCF[i0 + 6] = b6;
    rawDCF[i0 + 7] = b7;
}

void set7Bits(uint8_t i0, uint8_t i1, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint8_t b5, uint8_t b6) {
    rawDCF[i0 + 0] = b0;
    rawDCF[i0 + 1] = b1;
    rawDCF[i0 + 2] = b2;
    rawDCF[i0 + 3] = b3;
    rawDCF[i0 + 4] = b4;
    rawDCF[i0 + 5] = b5;
    rawDCF[i0 + 6] = b6;
}
void set6Bits(uint8_t i0, uint8_t i1, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4, uint8_t b5) {
    rawDCF[i0 + 0] = b0;
    rawDCF[i0 + 1] = b1;
    rawDCF[i0 + 2] = b2;
    rawDCF[i0 + 3] = b3;
    rawDCF[i0 + 4] = b4;
    rawDCF[i0 + 5] = b5;
}
void set5Bits(uint8_t i0, uint8_t i1, uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4) {
    rawDCF[i0 + 0] = b0;
    rawDCF[i0 + 1] = b1;
    rawDCF[i0 + 2] = b2;
    rawDCF[i0 + 3] = b3;
    rawDCF[i0 + 4] = b4;
}
void set3Bits(uint8_t i0, uint8_t i1, uint8_t b0, uint8_t b1, uint8_t b2) {
    rawDCF[i0 + 0] = b0;
    rawDCF[i0 + 1] = b1;
    rawDCF[i0 + 2] = b2;
}

void testGetMinute() {
    char *descr = "TEST- getMinute(): convert  bits 21-27 to responding decimal values";

    set7Bits(21, 28, 1, 0, 0, 0, 0, 0, 0);
    printTestResult(descr, getMinutes(rawDCF) == 1, "0000001 should be 1");

    set7Bits(21, 28, 0, 1, 0, 0, 0, 0, 0);
    printTestResult(descr, getMinutes(rawDCF) == 2, "0000010 should be 2");

    set7Bits(21, 28, 0, 0, 1, 0, 0, 0, 0);
    printTestResult(descr, getMinutes(rawDCF) == 4, "0000100 should be 4");

    set7Bits(21, 28,0,0,0,1,0,0,0);
    printTestResult(descr, getMinutes(rawDCF) == 8, "0001000 should be 8");

    set7Bits(21, 28, 0,0,0,0,1,0,0);
    printTestResult(descr, getMinutes(rawDCF) == 10, "0010000 should be 10");

    set7Bits(21, 28,0,0,0,0,0,1,0);
    printTestResult(descr, getMinutes(rawDCF) == 20, "0100000 should be 20");

    set7Bits(21, 28,0,0,0,0,0,0,1);
    printTestResult(descr, getMinutes(rawDCF) == 40, "1000000 should be 40");

    set7Bits(21, 28,1,1,0,1,1,0,0);
    printTestResult(descr, getMinutes(rawDCF) == 21, "0011011 should be 21");

    set7Bits(21, 28,0,1,0,1,0,1,1);
    printTestResult(descr, getMinutes(rawDCF) == 70, "1101010 should be 70");

    set7Bits(21, 28,1,1,1,1,1,0,1);
    printTestResult(descr, getMinutes(rawDCF) == 65, "1011111 should be 65");

    set7Bits(21, 28,1,1,1,1,1,1,0);
    printTestResult(descr, getMinutes(rawDCF) == 45, "0111111 should be 45");

    set7Bits(21, 28,1,1,1,1,1,1,1);
    printTestResult(descr, getMinutes(rawDCF) == 85, "1111111 should be 85");

    }

void testGetHour(){
    char* descr = "TEST- getHour(): convert  bits 29-34 to responding decimal values";
    set6Bits(29, 35,1,0,0,0,0,0);
    printTestResult(descr, getHours(rawDCF) == 1, "000001 should be 1");
    set6Bits(29, 35,0,1,0,0,0,0);
    printTestResult(descr, getHours(rawDCF) == 2, "000010 should be 2");
    set6Bits(29, 35,0,0,1,0,0,0);
    printTestResult(descr, getHours(rawDCF) == 4, "000100 should be 4");
    set6Bits(29, 35,0,0,0,1,0,0);
    printTestResult(descr, getHours(rawDCF) == 8, "001000 should be 8");
    set6Bits(29, 35,0,0,0,0,1,0);
    printTestResult(descr, getHours(rawDCF) == 10, "010000 should be 10");
    set6Bits(29, 35,0,0,0,0,0,1);
    printTestResult(descr, getHours(rawDCF) == 20, "100000 should be 20");
    set6Bits(29, 35,1,0,1,0,1,1);
    printTestResult(descr, getHours(rawDCF) == 35, "110101 should be 35");
    set6Bits(29, 35,1,1,1,1,0,1);
    printTestResult(descr, getHours(rawDCF) == 35, "101111 should be 35");
    set6Bits(29, 35,1,1,1,1,1,0);
    printTestResult(descr, getHours(rawDCF) == 25, "011111 should be 25");
}

void testGetCalendarDay(){
    char* descr = "TEST- getCalendarDay(): convert  bits 36-41 to responding decimal values";
    set6Bits(36, 42,1,0,0,0,0,0);
    printTestResult(descr, getCalendarDay(rawDCF) == 1, "000001 should be 1");
    set6Bits(36, 42,0,1,0,0,0,0);
    printTestResult(descr, getCalendarDay(rawDCF) == 2, "000010 should be 2");
    set6Bits(36, 42,0,0,1,0,0,0);
    printTestResult(descr, getCalendarDay(rawDCF) == 4, "000100 should be 4");
    set6Bits(36, 42,0,0,0,1,0,0);
    printTestResult(descr, getCalendarDay(rawDCF) == 8, "001000 should be 8");
    set6Bits(36, 42,0,0,0,0,1,0);
    printTestResult(descr, getCalendarDay(rawDCF) == 10, "010000 should be 10");
    set6Bits(36, 42,0,0,0,0,0,1);
    printTestResult(descr, getCalendarDay(rawDCF) == 20, "100000 should be 20");
    set6Bits(36, 42,1,0,1,0,1,1);
    printTestResult(descr, getCalendarDay(rawDCF) == 35, "110101 should be 35");
    set6Bits(36, 42,1,1,1,1,0,1);
    printTestResult(descr, getCalendarDay(rawDCF) == 35, "101111 should be 35");
    set6Bits(36, 42,1,1,1,1,1,0);
    printTestResult(descr, getCalendarDay(rawDCF) == 25, "011111 should be 25");
}

void testGetCalendarMonth(){
    char* descr = "TEST- getCalendarMonth(): convert  bits 45-49 to responding decimal values";
    set5Bits(45, 50,1,0,0,0,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 1, "00001 should be 1");
    set5Bits(45, 50,0,1,0,0,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 2, "00010 should be 2");
    set5Bits(45, 50,1,1,0,0,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 3, "00011 should be 3");
    set5Bits(45, 50,0,0,1,0,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 4, "00100 should be 4");
    set5Bits(45, 50,1,0,1,0,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 5, "00101 should be 5");
    set5Bits(45, 50,0,1,1,0,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 6, "00110 should be 6");
    set5Bits(45, 50,1,1,1,0,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 7, "00111 should be 7");
    set5Bits(45, 50,0,0,0,1,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 8, "01000 should be 8");
    set5Bits(45, 50,1,0,0,1,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 9, "01001 should be 9");
    set5Bits(45, 50,0,1,0,1,0);
    printTestResult(descr, getCalendarMonth(rawDCF) == 10, "01010 should be 10");
    set5Bits(45, 50,1,0,0,0,1);
    printTestResult(descr, getCalendarMonth(rawDCF) == 11, "10001 should be 11");
    set5Bits(45, 50,0,1,0,0,1);
    printTestResult(descr, getCalendarMonth(rawDCF) == 12, "10010 should be 12");
    set5Bits(45, 50,0,1,0,0,1);
    printTestResult(descr, getCalendarMonth(rawDCF) == 12, "00110 should be 12");
    set5Bits(45, 50,1,1,1,1,1);
    printTestResult(descr, getCalendarMonth(rawDCF) == 25, "11111 should be 25");
}

void testGetCalendarYears(){
    char* descr = "TEST- getCalendarYears(): convert  bits 50-57 to responding decimal values";
    set8Bits(50, 58,1,0,0,0,0,0,0,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 1, "00000001 should be 1");
    set8Bits(50, 58,0,1,0,0,0,0,0,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 2, "00000010 should be 2");
    set8Bits(50, 58,0,0,1,0,0,0,0,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 4, "00000100 should be 4");
    set8Bits(50, 58,0,0,0,1,0,0,0,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 8, "00001000 should be 8");
    set8Bits(50, 58,0,0,0,0,1,0,0,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 10, "00010000 should be 10");
    set8Bits(50, 58,0,0,0,0,0,1,0,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 20, "00100000 should be 20");
    set8Bits(50, 58,0,0,0,0,0,0,1,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 40, "01000000 should be 40");
    set8Bits(50, 58,0,0,0,0,0,0,0,1);
    printTestResult(descr, getCalendarYears(rawDCF) == 80, "10000000 should be 80");
    set8Bits(50, 58,1,0,0,0,0,1,0,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 21, "00100001 should be 21");
    set8Bits(50, 58,0,0,0,0,1,1,1,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 70, "01110000 should be 70");
    set8Bits(50, 58,1,0,1,0,0,1,1,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 65, "01100101 should be 65");
    set8Bits(50, 58,1,1,1,1,0,0,1,0);
    printTestResult(descr, getCalendarYears(rawDCF) == 55, "01001111 should be 45");
}

void testGetWeekdayString(){
    char* descr = "TEST- getWeekdayString(): convert  bits 42-44 to responding decimal values";
    set3Bits(42, 45,0,0,0);
    printTestResult(descr, strcmp(getWeekdayString(rawDCF), "ERROR 34") == 0, "000 should be Error");
    set3Bits(42, 45,1,0,0);
    printTestResult(descr, strcmp(getWeekdayString(rawDCF), "Mon") == 0, "001 should be Mon");
    set3Bits(42, 45,0,1,0);
    printTestResult(descr, strcmp(getWeekdayString(rawDCF), "Tue") == 0, "010 should be Tue");
    set3Bits(42, 45,1,1,0);
    printTestResult(descr, strcmp(getWeekdayString(rawDCF), "Wed") == 0, "011 should be Wed");
    set3Bits(42, 45,0,0,1);
    printTestResult(descr, strcmp(getWeekdayString(rawDCF), "Thu") == 0, "100 should be Thu");
    set3Bits(42, 45,1,0,1);
    printTestResult(descr, strcmp(getWeekdayString(rawDCF), "Fri") == 0, "101 should be Fri");
    set3Bits(42, 45,0,1,1);
    printTestResult(descr, strcmp(getWeekdayString(rawDCF), "Sat") == 0, "110 should be Sat");
    set3Bits(42, 45,1,1,1);
    printTestResult(descr, strcmp(getWeekdayString(rawDCF), "Sun") == 0, "111 should be Sun");
}
void runTestsuite_dateExtractor(){
    DCF_init();
    testGetMinute();
    testGetCalendarDay();
    testGetCalendarYears();
    testGetHour();
    testGetWeekdayString();
    testGetCalendarMonth();
}
