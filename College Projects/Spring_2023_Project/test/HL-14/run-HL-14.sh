#!/bin/bash
cd ../../src
echo "1000" | ./run.sh &> /dev/null
cd ../test/HL-14
g++ HL-14-test.cpp
./a.out
rm a.out
