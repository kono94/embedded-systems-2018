#!/bin/bash



gcc -Wall -o main main.c DCF/*.c validation/*.c util/*.c
./main

gcc -Wall -o runAllTests tests/*.c DCF/*.c validation/*.c util/*.c
#./runAllTests
