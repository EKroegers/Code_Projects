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

///Find first percentage value in inputFile to prove it can be read
//Needs to be passed with & for inputFile
bool findReturnPercentageInLog(ifstream &inputFile) {
    string input;
    bool testPassed = false;
    while(inputFile) {
        getline(inputFile, input);
        if (inputFile) {
            istringstream ss(input);
            string word;
            //for each word in each line of log, check if line contains
            //% character (Only percentage values should)
            //Identifies return percentages for comparison
            while (ss >> word) {
                if (word.find('%') != string::npos) {
                    testPassed = true;
                }
            }
        }
        if (testPassed == true) {
            break;
        }
    }
    return testPassed;
}

int main() {
    //HL-12 test
    string path;
    if (windows == 1) {
        path = "..\\..\\..\\src\\market-log.txt";
    } else {
        path = "../../../src/market-log.txt";
    }
    ifstream inputFile(path);

    if (!inputFile) {
        cout << "HL-12 Test failed. Could not open market-log.txt" << endl;
    	return 1;
    }

    bool testPassed = findReturnPercentageInLog(inputFile);
    if (testPassed == false) {
        cout << "HL-12 Test failed. Could not read a percentage return value from market-log.txt" << endl;
        return 1;
    }
    cout << "HL-12 Test passed. Market values can be extracted from market-log.txt." << endl;
    return 0;
}
