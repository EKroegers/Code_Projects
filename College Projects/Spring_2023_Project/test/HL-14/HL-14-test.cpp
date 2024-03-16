///HL-14 test needs to be run with a larger test harness that can call Driver.cpp
///give the simulation a certain number of days to run. That number should match
///the number in the daysSimulated variable.
#include <iostream>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>

#ifdef _WIN32
        int windows = 1;
#else
        int windows = 0;
#endif

using namespace std;

///HL-14 test
///check if the number of daily returns in the market-log.txt file
/// (which is equivalent to the number of days simulated) is equal to
/// the number of days inputted into simulation
int main() {
    ///This variable must match the input of length for the simulation it is testing (see comprehensive-test.sh)
    int daysSimulated = 1000;

    string path;
    if (windows == 1) {
        path = "..\\..\\src\\market-log.txt";
    } else {
        path = "../../src/market-log.txt";
    }
    ifstream inputFile(path);

    if (!inputFile) {
        cout << "HL-14 Test failed. Could not open market-log.txt" << endl;
    	return 1;
    }

    int simulatedDaysCount = 0;

    string input;
    while(inputFile) {
        getline(inputFile, input);
        if (inputFile) {
            istringstream ss(input);
            string word;
            ///for each word in each line of log, check if word contains
            ///% character (Only percentage values should)
            ///Identifies return percentages. Percent signs only occur where there
            ///is a record of a daily market return. We want to count the number
            ///of daily market returns for the test. Only one should be permitted
            /// per line. Loop is broken when one is found to prevent any problems
            /// from potential changes to how data is saved to log file
            while (ss >> word) {
                if (word.find('%') != string::npos) {
                    simulatedDaysCount++;
                    break;
                }
            }
        }
    }

    if (simulatedDaysCount == daysSimulated) {
        cout << "HL-14 test passed. The input for number of days to simulate matches the number of days simulated by the program." << endl;
        return 0;
    } else {
        cout << "HL-14 test failed. The number of days simulated did not match the number used as input: " << daysSimulated << endl;
    }
}