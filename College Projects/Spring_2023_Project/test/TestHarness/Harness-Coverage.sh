#!/bin/bash
cp TestHarness.cpp ../../src/
cd ../../src
rm TestHarness.gcno
rm TestHarness.gcda
g++ -fprofile-arcs -ftest-coverage -g TestHarness.cpp -o TestHarnessCoverage 
./TestHarnessCoverage
gcov TestHarnessCoverage
gcov TestHarness.gcno
rm TestHarnessCoverage
rm TestHarness.cpp
rm *gcov
