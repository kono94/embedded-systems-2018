#!/bin/bash

avr-gcc -Wall -o -I /usr/local/Cellar/avr-gcc/8.2.0/avr/include/avr main src/main.c src/DCF/*.c src/validation/*.c src/util/*.c
./main

avr-gcc -Wall -o -I /usr/local/Cellar/avr-gcc/8.2.0/avr/include/avr runAllTests tests/*.c src/DCF/*.c src/validation/*.c src/util/*.c
#./runAllTests
