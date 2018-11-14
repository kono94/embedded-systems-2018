/*******************************************************************************
 * File testsuite_bitConverter.h
 *
 * Suite for all tests regarding all functions offered by the
 * bitConverter.c file
 *
 * Author: Jan Löwenstrom
 * Date: 14.11.18
 *******************************************************************************/


#include <stdbool.h>
#include <inttypes.h>
#include "testsuite_bitConverter.h"
#include "testFramework.h"
#include "../util/bitConverter.h"


void test_2bitConversion(){
    char *descr = "TEST- 2bitConversion(): convert all 2 bit numbers to responding decimal values";

    /*
     * IMPORTANT:
     * parameter 1 = bit1
     * parameter 2 = bit2
     *
     * So:
     *  helper(1,0)  equal 01 and therefore 1! (an not 2)
     */
    printTestResult(descr, helper_2bit(0,0) == 0, "00 should be 0");
    printTestResult(descr, helper_2bit(1,0) == 1, "10 should be 1");
    printTestResult(descr, helper_2bit(0,1) == 2, "01 should be 2");
    printTestResult(descr, helper_2bit(1,1) == 3, "11 should be 3");
}

void test_3bitConversion(){
    char *descr = "TEST- 3bitConversion(): convert all 3 bit numbers to responding decimal values";

    printTestResult(descr, helper_3bit(0,0,0) == 0, "000 should be 0");
    printTestResult(descr, helper_3bit(1,0,0) == 1, "001 should be 1");
    printTestResult(descr, helper_3bit(0,1,0) == 2, "010 should be 2");
    printTestResult(descr, helper_3bit(1,1,0) == 3, "011 should be 3");
    printTestResult(descr, helper_3bit(0,0,1) == 4, "100 should be 4");
    printTestResult(descr, helper_3bit(1,0,1) == 5, "101 should be 5");
    printTestResult(descr, helper_3bit(0,1,1) == 6, "110 should be 6");
    printTestResult(descr, helper_3bit(1,1,1) == 7, "111 should be 7");
}

void test_4bitConversion(){
    char *descr = "TEST- 4bitConversion(): convert all 4 bit numbers to responding decimal values";

    printTestResult(descr, helper_4bit(0,0,0,0) == 0, "0000 should be 0");
    printTestResult(descr, helper_4bit(1,0,0,0) == 1, "0001 should be 1");
    printTestResult(descr, helper_4bit(0,1,0,0) == 2, "0010 should be 2");
    printTestResult(descr, helper_4bit(1,1,0,0) == 3, "0011 should be 3");
    printTestResult(descr, helper_4bit(0,0,1,0) == 4, "0100 should be 4");
    printTestResult(descr, helper_4bit(1,0,1,0) == 5, "0101 should be 5");
    printTestResult(descr, helper_4bit(0,1,1,0) == 6, "0110 should be 6");
    printTestResult(descr, helper_4bit(1,1,1,0) == 7, "0111 should be 7");
    printTestResult(descr, helper_4bit(0,0,0,1) == 8, "1000 should be 8");
    printTestResult(descr, helper_4bit(1,0,0,1) == 9, "1001 should be 9");
    printTestResult(descr, helper_4bit(0,1,0,1) == 10, "1010 should be 10");
    printTestResult(descr, helper_4bit(1,1,0,1) == 11, "1011 should be 11");
    printTestResult(descr, helper_4bit(0,0,1,1) == 12, "1100 should be 12");
    printTestResult(descr, helper_4bit(1,0,1,1) == 13, "1101 should be 13");
    printTestResult(descr, helper_4bit(0,1,1,1) == 14, "1110 should be 14");
    printTestResult(descr, helper_4bit(1,1,1,1) == 15, "1111 should be 15");


}

uint8_t runTestsuite_bitConverter(){
    printSuiteName("TEST SUITE FOR BIT_CONVERTER");
    test_2bitConversion();
    test_3bitConversion();
    test_4bitConversion();
    return 0;
}
