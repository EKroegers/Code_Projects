#!/bin/bash
cp TestHarness.cpp ../../src/
cd ../../src
g++ -o testharness.out TestHarness.cpp Market.cpp
./testharness.out
rm testharness.out
rm TestHarness.cpp
