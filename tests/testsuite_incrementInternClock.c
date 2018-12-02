/*******************************************************************************
 * File testsuite_validDate.c
 *
 * Suite for all tests regarding the incrementation of the intern Clock
 *
 * Authors: Jan Löwenstrom & Johann Hoffer
 * Date: 02.12.18
 *******************************************************************************/

#include <stdio.h>
#include <inttypes.h>
#include "testFramework.h"
#include "testsuite_incrementInternClock.h"
#include "../src/internClock/avrDatetime.h"

void testSecondsChange(){
    char *descr = "TEST- testSecondsChange(): Test regarding counting up the seconds";

    AvrDatetime_init(); // Fresh time 1.1.2018 0:00

    printTestResult(descr, (p_avrDatetime->seconds == 0), "default value for seconds when initialized should be 0");

    incrementByOneSecond();
    printTestResult(descr, (p_avrDatetime->seconds == 1), "incrementing by 1 should set the seconds to 1");

    p_avrDatetime->seconds = 30;
    // incrementing by 6 seconds
    incrementByOneSecond();
    incrementByOneSecond();
    incrementByOneSecond();
    incrementByOneSecond();
    incrementByOneSecond();
    incrementByOneSecond();

    printTestResult(descr, (p_avrDatetime->seconds == 36), "incrementing second 30,  6 times should result in 36");

    p_avrDatetime->seconds = 59;
    incrementByOneSecond();
    printTestResult(descr, (p_avrDatetime->seconds == 0), "incrementing when clock is set to 59 "
                                                          "seconds should reset seconds to 0 because "
                                                          "a new minute started");


    p_avrDatetime->seconds = 0;
    p_avrDatetime->minutes = 0;
    for(uint8_t i = 0; i < 60; ++i){
        incrementByOneSecond();
    }
    printTestResult(descr, (p_avrDatetime->seconds == 0), "seconds should reset to 0 after 60 seconds passed");
    printTestResult(descr, (p_avrDatetime->minutes == 1), "minutes should increment after 1 minute passed");

}


void testMinutesChange() {
    char *descr = "TEST- testMinutesChange(): Test regarding counting up the minutes";

    AvrDatetime_init(); // Fresh time 1.1.2018 0:00

    printTestResult(descr, (p_avrDatetime->minutes == 0), "default value for minutes when initialized should be 0");


    printTestResult(descr, (p_avrDatetime->hours == 0), "hours should be set to 0 as default");

    // letting 20 minutes pass
    for(uint8_t m = 0; m < 20; ++m) {
        for (uint8_t s = 0; s < 60 ; ++s) {
            incrementByOneSecond();
        }
    }
    printTestResult(descr, (p_avrDatetime->minutes == 20), "minutes should be 20 if 60*20 seconds passed");



    AvrDatetime_init(); // Fresh time 1.1.2018 0:00
    // letting one hour pass
    for(uint8_t m = 0; m < 60; ++m) {
        for (uint8_t s = 0; s < 60 ; ++s) {
            incrementByOneSecond();
        }
    }

    printTestResult(descr, (p_avrDatetime->seconds == 0), "seconds should be exactly 0 if one hour passed");
    printTestResult(descr, (p_avrDatetime->minutes == 0), "minutes should reset to 0 if one hour passed");
    printTestResult(descr, (p_avrDatetime->hours == 1), "hours should be incremented if one hour passed");
}



void testHoursChange() {
    char *descr = "TEST- testHoursChange(): Test regarding counting up the hours";

    AvrDatetime_init(); // Fresh time 1.1.2018 0:00

    printTestResult(descr, (p_avrDatetime->hours == 0), "default value for hours when initialized should be 0");
    printTestResult(descr, (p_avrDatetime->days == 1), "default value for days when initialized should be 1");

    // letting 15 hour pass
    for(uint8_t h = 0; h < 15; ++h) {
        for (uint8_t m = 0; m < 60; ++m) {
            for (uint8_t s = 0; s < 60; ++s) {
                incrementByOneSecond();
            }
        }
    }
    printTestResult(descr, (p_avrDatetime->hours == 15), "hours should be 15 after 15 hours passed");
    printTestResult(descr, (p_avrDatetime->minutes == 0), "minutes should be 0 if exactly 15 hours passed");
    printTestResult(descr, (p_avrDatetime->seconds == 0), "seconds should be 0 if exactly 15 hours passed");



    AvrDatetime_init(); // Fresh time 1.1.2018 0:00
    // letting 24 hour pass
    for(uint8_t h = 0; h < 24; ++h) {
        for (uint8_t m = 0; m < 60; ++m) {
            for (uint8_t s = 0; s < 60; ++s) {
                incrementByOneSecond();
            }
        }
    }
    printTestResult(descr, (p_avrDatetime->hours == 0), "hours reset if one day passed");
    printTestResult(descr, (p_avrDatetime->minutes == 0), "minutes should be 0 if exactly 24 hours passed");
    printTestResult(descr, (p_avrDatetime->seconds == 0), "seconds should be 0 if exactly 24 hours passed");



    // same as above but different approach adding one second to 23:59:59
    p_avrDatetime->seconds = 59;
    p_avrDatetime->minutes = 59;
    p_avrDatetime->hours = 23;
    p_avrDatetime->days = 1;
    incrementByOneSecond();
    printTestResult(descr, (p_avrDatetime->hours == 0), "hours reset if one day passed");
    printTestResult(descr, (p_avrDatetime->minutes == 0), "minutes should be 0 if exactly 24 hours passed");
    printTestResult(descr, (p_avrDatetime->seconds == 0), "seconds should be 0 if exactly 24 hours passed");
    printTestResult(descr, (p_avrDatetime->days == 2), "days should incremented by 1 if hours change from 23 back to 0");

}



void testDaysChange() {
    char *descr = "TEST- testDaysChange(): Test regarding counting up the days";

    AvrDatetime_init(); // Fresh time 1.1.2018 0:00

    printTestResult(descr, (p_avrDatetime->days == 1), "default value for days when initialized should be 1");
    printTestResult(descr, (p_avrDatetime->months == 1), "default value for months when initialized should be 1");

    // letting 14 days pass
    for(uint8_t d = 0; d < 14; ++d) {
        for (uint8_t h = 0; h < 24; ++h) {
            for (uint8_t m = 0; m < 60; ++m) {
                for (uint8_t s = 0; s < 60; ++s) {
                    incrementByOneSecond();
                }
            }
        }
    }

    printTestResult(descr, (p_avrDatetime->days == 15), "days should be set to 15 if 14 days pass after 1st of January");


    //Setting datetime to 28. January 10:20:30
    p_avrDatetime->days = 28;
    p_avrDatetime->months = 1;
    p_avrDatetime->seconds = 30;
    p_avrDatetime->minutes = 20;
    p_avrDatetime->hours = 10;


    //... and letting 6 days, 2 hours, 26 minutes and 4 seconds pass
    // letting 6 days pass
    for(uint8_t d = 0; d < 6; ++d) {
        for (uint8_t h = 0; h < 24; ++h) {
            for (uint8_t m = 0; m < 60; ++m) {
                for (uint8_t s = 0; s < 60; ++s) {
                    incrementByOneSecond();
                }
            }
        }
    }

    // 2 hours
    for (uint8_t h = 0; h < 2; ++h) {
        for (uint8_t m = 0; m < 60; ++m) {
            for (uint8_t s = 0; s < 60; ++s) {
                incrementByOneSecond();
            }
        }
    }
    // 26 minutes
    for (uint8_t m = 0; m < 26; ++m) {
        for (uint8_t s = 0; s < 60; ++s) {
            incrementByOneSecond();
        }
    }

    // 4 seconds
    for (uint8_t s = 0; s < 4; ++s) {
        incrementByOneSecond();
    }

    // expected is 3. February 12:46:34

    printTestResult(descr, (p_avrDatetime->days == 3), "days should be 3");
    printTestResult(descr, (p_avrDatetime->months == 2), "days should be 2");
    printTestResult(descr, (p_avrDatetime->hours == 12), "hours should be 12");
    printTestResult(descr, (p_avrDatetime->minutes == 46), "minutes should be 46");
    printTestResult(descr, (p_avrDatetime->seconds == 34), "seconds should be 34");

    // Unfassbar, das funktioniert wie am Schnürchen XD
}




void testMonthsChange() {
    char *descr = "TEST- testMonthsChange(): Test regarding counting up the months";

    AvrDatetime_init(); // Fresh time 1.1.2018 0:00

    printTestResult(descr, (p_avrDatetime->months == 1), "default value for days when initialized should be 1");
    printTestResult(descr, (p_avrDatetime->years_tens == 18), "default value for months when initialized should be 18");

    // letting 5 months pass
    for(uint8_t M = 0; M < 5; ++M) {
        for (uint8_t d = 0; d < 31; ++d) {
            for (uint8_t h = 0; h < 24; ++h) {
                for (uint8_t m = 0; m < 60; ++m) {
                    for (uint8_t s = 0; s < 60; ++s) {
                        incrementByOneSecond();
                    }
                }
            }
        }
    }
    printTestResult(descr, (p_avrDatetime->months == 6), "months should be 6 if 31*5 days (5 months) passed");


    // not checking edge cases just yet, just the change of years
    // 20.12.18
    p_avrDatetime->years_tens = 18;
    p_avrDatetime->months = 12;
    p_avrDatetime->days = 20;

    // letting 3 months pass
    for(uint8_t M = 0; M < 3; ++M) {
        for (uint8_t d = 0; d < 31; ++d) {
            for (uint8_t h = 0; h < 24; ++h) {
                for (uint8_t m = 0; m < 60; ++m) {
                    for (uint8_t s = 0; s < 60; ++s) {
                        incrementByOneSecond();
                    }
                }
            }
        }
    }

    printTestResult(descr, (p_avrDatetime->months == 3), "months should be 3 if 31*3 days (3 months) passed after 20th December");
    printTestResult(descr, (p_avrDatetime->years_tens == 19), "years_ten should increment if months reset from 12 to 1");
}


void testLeapYearTimeChange(){
    char *descr = "TEST- testLeapYearTimeChange(): Test if time increments correctly if leap year";

    AvrDatetime_init(); // Fresh time 1.1.2018 0:00

    // test for leap year changes in february
    p_avrDatetime->years_tens = 20;
    p_avrDatetime->months = 2;
    p_avrDatetime->days = 28;
    p_avrDatetime->hours = 23;
    p_avrDatetime->minutes = 59;
    p_avrDatetime->seconds = 59;
    p_avrDatetime->years_tens = 20;

    incrementByOneSecond();

    printTestResult(descr, (p_avrDatetime->months == 2), "months should still be 2 if leap year and 29th February");
    printTestResult(descr, (p_avrDatetime->days == 29), "days should be 29 if leap year and 29th February");
}


uint8_t runTestsuite_incrementInternClock(){
    printSuiteName("TEST SUITE FOR INCREMENT_INTERN_CLOCK");
    testSecondsChange();
    testMinutesChange();
    testHoursChange();
    testDaysChange();
    testMonthsChange();
    testLeapYearTimeChange();
    return 0;
}