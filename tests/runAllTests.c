//
// Created by Jan Uni on 09.11.18.
//

#include "runAllTests.h"
#include "test_validDate.h"
#include "test_validTime.h"


int main(int argc, char** argv){
    validDateTest_runAll();
    validTimeTest_runAll();
    return 0;
}