//
// Created by Jan Uni on 09.11.18.
//
#include "runAllTests.h"
#include "testsuite_validDate.h"
#include "testsuite_validTime.h"


int main(int argc, char** argv){
    runTestsuite_validDate();
    runTestsuite_validTime();
    return 0;
}