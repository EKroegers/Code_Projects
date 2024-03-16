#!/bin/bash

#HL-12 test
cd HL-12/Integrated-Test
./run-HL-12-test.sh
cd ../../

#HL-13 test
cd HL-13/Integrated-Test
./run-HL-13-test.sh
cd ../../

#HL-7b and HL-18 tests
cd HL-7b/Integrated-Test
./run-HL-7b-and-HL-18-tests.sh
cd ../../

#HL 1,2,3,6 & 9
cd TestHarness
./run-TestHarness.sh
cd ../

#HL-14 test
cd HL-14
./run-HL-14.sh
cd ../
