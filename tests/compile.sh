#!/bin/bash

gcc -Wall -o runAllTests runAllTests.c testFramework.c validDate.c test_validDate.c validTime.c test_validTime.c
./runAllTests