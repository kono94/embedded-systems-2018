#!/bin/bash

gcc -Wall -o test_validDate validDate.c test_validDate.c
./test_validDate

gcc -Wall -o test_validTime validTime.c test_validTime.c
./test_validTime
