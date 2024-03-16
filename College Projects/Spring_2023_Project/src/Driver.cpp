#include "headers/Market.h"
#include <stdlib.h> // For random
#include <string>   // For strings
#include <fstream> //for ofstream log file
#include <limits.h> //for INT_MAX

#include <time.h>

#include <iostream>

using namespace std;

int main() {
    time_t seed;
    seed = time(NULL);
	srand(seed);
    //HL-12 - write header to market log file
    //opening file and closing it in this manner will
    //clear prior simulation data from market-log.txt
    ofstream marketLogFile;
    marketLogFile.open ("market-log.txt");
	marketLogFile << "Start of log file." << " Seed: " << seed << "\n";
	marketLogFile.close();
    //HL-13 - write header to stock log file
    //opening file and closing it in this manner will
    //clear prior simulation data from stock-log.txt
    ofstream stockLogFile;
	stockLogFile.open ("stock-log.txt");
	stockLogFile << "Start of log file." << " Seed: " << seed << "\n";
	stockLogFile.close();

    //simulation
    //HL-9. Simulated stock market has ten
    //individual stocks in it
    Market sp500;
    //HL-1 simulation will include varoius companies
    //with their own stocks and prices
    sp500.AddNewStock("ExxonMobil",100);
    sp500.AddNewStock("Shermin-Williams",100);
    sp500.AddNewStock("Boeing",100);
    sp500.AddNewStock("Duke Energy",100);
    sp500.AddNewStock("UnitedHealth Group",100);
    sp500.AddNewStock("JPMorgan Chase",100);
    sp500.AddNewStock("McDonalds",100);
    sp500.AddNewStock("Coca-Cola",100);
    sp500.AddNewStock("Microsoft",100);
    sp500.AddNewStock("AT&T",100);

    //HL-14 - take user input for length of simulation
    //and check that it is appropriate input
    int daysSimulated;
    cout << "Enter the length of the simulation (number of days): " << endl;
    while ((!(cin >> daysSimulated)) || (daysSimulated < 1) || (daysSimulated >= 3653)) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please enter a positive integer/whole number for the length of the simulation (Max 3653/10 years)" << endl;
    }

    for (int i = 0; i < daysSimulated; i++) {
        //HL-12 - write simulation day number
        //to market log file
        marketLogFile.open ("market-log.txt", ios::app);
	    marketLogFile << "Day " << i + 1 <<": " << "\n";
        marketLogFile.close();
        //HL-13 - write simulation day number
        //to stock log file
	    stockLogFile.open ("stock-log.txt", ios::app);
	    stockLogFile << "Day " << i + 1 <<": " << "\n";
        stockLogFile.close();
        //HL-2 - simulate fluctuations for stock prices
        sp500.TickAllStocks();
    }

    return 0;
}
