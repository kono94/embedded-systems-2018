#!/bin/bash

gcc -Wall -o runAllTests tests/runAllTests.c tests/testFramework.c tests/validDate.c tests/test_validDate.c tests/validTime.c tests/test_validTime.c


gcc -Wall -o main main.c DCF/DCF.c DCF/dateExtractor.c util/bitConverter.c
./main

