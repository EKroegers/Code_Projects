#include "iostream"

#include "headers/Market.h" // Project

#include "string.h" // For string
#include "stdlib.h" // For random
#include "time.h"   // For random seeding

// Unit Tests

#define VerboseTesting // if this is enabled do one requirement at a time

#define HL1
#define HL2
#define HL3
#define HL6
#define HL9

using namespace std;

int main()
{
    srand(time(NULL));

    Market SampleMarket;

    string Entry1StockName = "Sample Company";
    double Entry1StockPrice = 100;

    SampleMarket.AddNewStock(Entry1StockName, Entry1StockPrice);

    int TestCount = 0, PassedTestCount = 0, FailedTestCount = 0;

    // Test for HL-1: AllStocks Collecting AddNewStock Inputs
    #ifdef HL1

    TestCount++;

    #ifdef VerboseTesting
    TestCount++;
    if (SampleMarket.AllStocks[0].getName() != "empty")
    {
        cout << "\033[1;32m\n\tEntry 1 Exists\033[0m" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tEntry 1 Does Not Exist\033[0m\n" << endl;
        FailedTestCount++;
    }

    TestCount++;
    if (SampleMarket.AllStocks[0].getName() == Entry1StockName)
    {
        cout << "\033[1;32m\n\tName is Passed\033[0m" << " (" << SampleMarket.AllStocks[0].getName() << ")" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tName is not Passed\033[0m\n" << " (" << SampleMarket.AllStocks[0].getName() << ")" << endl;
        FailedTestCount++;
    }

    TestCount++;
    if (SampleMarket.AllStocks[0].getBasePrice() == Entry1StockPrice)
    {
        cout << "\033[1;32m\tBase Price is Passed\033[0m" << " ($" << SampleMarket.AllStocks[0].getBasePrice() << ")" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tBase Price is not Passed\033[0m\n" << " ($" << SampleMarket.AllStocks[0].getBasePrice() << ")" << endl;
        FailedTestCount++;
    }

    #endif

    string Entry2StockName = "Another Sample Company";
    double Entry2StockPrice = 256;

    SampleMarket.AddNewStock(Entry2StockName, Entry2StockPrice);

    #ifdef VerboseTesting
    TestCount++;
    if (SampleMarket.AllStocks[1].getName() != "empty")
    {
        cout << "\033[1;32m\n\tEntry 2 Exists\033[0m" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tEntry 2 Does Not Exist\033[0m\n" << endl;
        FailedTestCount++;
    }

    TestCount++;
    if (SampleMarket.AllStocks[1].getName() == Entry2StockName)
    {
        cout << "\033[1;32m\n\tName is Passed\033[0m" << " (" << SampleMarket.AllStocks[1].getName() << ")" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tName is not Passed\033[0m\n" << " (" << SampleMarket.AllStocks[1].getName() << ")" << endl;
        FailedTestCount++;
    }

    TestCount++;
    if (SampleMarket.AllStocks[1].getBasePrice() == Entry2StockPrice)
    {
        cout << "\033[1;32m\tBase Price is Passed\033[0m" << " ($" << SampleMarket.AllStocks[1].getBasePrice() << ")" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tBase Price is not Passed\033[0m\n" << " ($" << SampleMarket.AllStocks[1].getBasePrice() << ")" << endl;
        FailedTestCount++;
    }
    #endif

    string Entry3StockName = "A Third Sample Company";
    double Entry3StockPrice = 10;

    SampleMarket.AddNewStock(Entry3StockName, Entry3StockPrice);

    #ifdef VerboseTesting
    TestCount++;
    if (SampleMarket.AllStocks[2].getName() != "empty")
    {
        cout << "\033[1;32m\n\tEntry 3 Exists\033[0m" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tEntry 3 Does Not Exist\033[0m\n" << endl;
        FailedTestCount++;
    }

    TestCount++;
    if (SampleMarket.AllStocks[2].getName() == Entry3StockName)
    {
        cout << "\033[1;32m\n\tName is Passed\033[0m" << " (" << SampleMarket.AllStocks[2].getName() << ")" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tName is not Passed\033[0m\n" << " (" << SampleMarket.AllStocks[2].getName() << ")" << endl;
        FailedTestCount++;
    }

    TestCount++;
    if (SampleMarket.AllStocks[2].getBasePrice() == Entry3StockPrice)
    {
        cout << "\033[1;32m\tBase Price is Passed\033[0m" << " ($" << SampleMarket.AllStocks[2].getBasePrice() << ")" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tBase Price is not Passed\033[0m\n" << " ($" << SampleMarket.AllStocks[2].getBasePrice() << ")" << endl;
        FailedTestCount++;
    }
    #endif

    int LoadedStockCount = 0;
    int InputStockCount = 0;
    InputStockCount += 3;

    for (int i = 0; i < MAXSTOCKS; i++)
    {
        if (SampleMarket.AllStocks[i].getName() != "empty") // "empty" is default on construction
        {
            LoadedStockCount++;
        }
    }

    if (InputStockCount == LoadedStockCount)
    {
        cout << "\033[1;32m\nHL1 is all good\033[0m\n" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\nWe got a problamo with HL1\033[0m\n" << endl;
        FailedTestCount++;
    }

    #endif

    // Test for HL-2; Tick Logic Price Modulation Check
    #ifdef HL2
    TestCount++;

    #ifdef VerboseTesting
    TestCount++;
    double previousPrice = SampleMarket.AllStocks[0].getCurrentPrice();
    bool didChange = false;
    #endif

    for (int i = 0; i < 100; i++) // One-Hundred "Days"
    {
        SampleMarket.TickAllStocks();

        #ifdef VerboseTesting
        if (i % 10 == 0)
        {
            if (previousPrice != SampleMarket.AllStocks[0].getCurrentPrice())
            {
                cout << "\033[1;32m\tChange\033[0m" << endl;
                didChange = true;
            }
            else
                cout << "\033[33m\tNo Change\033[0m" << endl;

            previousPrice = SampleMarket.AllStocks[0].getCurrentPrice();
        }
        #endif
    }

    #ifdef VerboseTesting
    if (didChange ? PassedTestCount++ : FailedTestCount++);
    #endif

    if (SampleMarket.AllStocks[0].getCurrentPrice() != Entry1StockPrice)
    {
        cout << "\033[1;32m\nHL2 is working properly\033[0m\n" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\nThings are going bad with HL2\033[0m\n" << endl;
        FailedTestCount++;
    }

    #endif

    // Test for HL-3: S&P500 Existence Check
    #ifdef HL3
    TestCount++;
    SampleMarket.TickAllStocks();

    #ifdef VerboseTesting
    TestCount++;
    double NetStockPrice = 0;
    int StockCount = 0;

    for (int i = 0; i < MAXSTOCKS; i++)
    {
        NetStockPrice += SampleMarket.AllStocks[i].getCurrentPrice();
        if (SampleMarket.AllStocks[i].getName() != "empty")
            StockCount++;
    }

    if ((NetStockPrice/StockCount) == SampleMarket.getOur500().getCurrentPrice())
    {
        cout << "\033[1;32m\tThe Math Checks Out\033[0m" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\tThe Math is Off\033[0m" << endl;
        FailedTestCount++;
    }
    #endif

    if (SampleMarket.getOur500().getCurrentPrice() != 0)
    {
        cout << "\033[1;32m\nHL3 is up and running\033[0m\n" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\nHL3 isn't even real\033[0m\n" << endl;
        FailedTestCount++;
    }
    #endif

    // Test for HL-6: Two-Stock Value Differentiation Check
    #ifdef HL6
    TestCount++;

    string Entry6_1StockName = "Example Company";
    double Entry6_1StockPrice = 100;

    SampleMarket.AddNewStock(Entry6_1StockName, Entry6_1StockPrice);

    string Entry6_2StockName = "Another Example Company";
    double Entry6_2StockPrice = 100;

    SampleMarket.AddNewStock(Entry6_2StockName, Entry6_2StockPrice);

    #ifdef VerboseTesting
    TestCount++;
    bool didDifferentiate = false;
    #endif

    for (int i = 0; i < 10; i ++)
    {
        SampleMarket.TickAllStocks();

        #ifdef VerboseTesting
        if (SampleMarket.AllStocks[0].getCurrentPrice() != SampleMarket.AllStocks[1].getCurrentPrice())
        {
            cout << "\033[1;32m\tDifferent\033[0m" << endl;
            didDifferentiate = true;
        }
        else
            cout << "\033[33m\tSame\033[0m" << endl;
        #endif
    }

    #ifdef VerboseTesting
    if (didDifferentiate ? PassedTestCount++ : FailedTestCount++);
    #endif

    if (SampleMarket.AllStocks[0].getCurrentPrice() != SampleMarket.AllStocks[1].getCurrentPrice())
    {
        cout << "\033[1;32m\nHL6 is totally cool\033[0m\n" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\nHL6 is broken beyond repair\033[0m\n" << endl;
        FailedTestCount++;
    }

    #endif

    // Test for HL-9: Ten-Stock Existence Check
    #ifdef HL9
    TestCount++;

    string Entry9_2StockName = "2";
    double Entry9_2StockPrice = 100;
    SampleMarket.AddNewStock(Entry9_2StockName, Entry9_2StockPrice);

    string Entry9_3StockName = "3";
    double Entry9_3StockPrice = 100;
    SampleMarket.AddNewStock(Entry9_3StockName, Entry9_3StockPrice);

    string Entry9_4StockName = "4";
    double Entry9_4StockPrice = 100;
    SampleMarket.AddNewStock(Entry9_4StockName, Entry9_4StockPrice);

    string Entry9_5StockName = "5";
    double Entry9_5StockPrice = 100;
    SampleMarket.AddNewStock(Entry9_5StockName, Entry9_5StockPrice);

    string Entry9_6StockName = "6";
    double Entry9_6StockPrice = 100;
    SampleMarket.AddNewStock(Entry9_6StockName, Entry9_6StockPrice);

    string Entry9_7StockName = "7";
    double Entry9_7StockPrice = 100;
    SampleMarket.AddNewStock(Entry9_7StockName, Entry9_7StockPrice);

    string Entry9_8StockName = "8";
    double Entry9_8StockPrice = 100;
    SampleMarket.AddNewStock(Entry9_8StockName, Entry9_8StockPrice);

    string Entry9_9StockName = "9";
    double Entry9_9StockPrice = 100;
    SampleMarket.AddNewStock(Entry9_9StockName, Entry9_9StockPrice);

    string Entry9_10StockName = "10";
    double Entry9_10StockPrice = 100;
    SampleMarket.AddNewStock(Entry9_10StockName, Entry9_10StockPrice);

    if (SampleMarket.AllStocks[0].getName() != "empty" && SampleMarket.AllStocks[9].getName() != "empty")
    {
        cout << "\033[1;32m\nHL9 is working harder than I am\033[0m\n" << endl;
        PassedTestCount++;
    }
    else
    {
        cout << "\033[31m\nHL9 is a lost cause\033[0m\n" << endl;
        FailedTestCount++;
    }

    #endif
    if (TestCount == 1)
    {
        cout << TestCount << "\033[33m Total Test\033[0m " << "|| ";
    }
    else
    {
        cout << TestCount << "\033[33m Total Tests\033[0m " << "|| ";
    }

    if (PassedTestCount == 1)
    {
        cout << PassedTestCount << "\033[1;32m Test Passed\033[0m " << "|| ";
    }
    else
    {
        cout << PassedTestCount << "\033[1;32m Tests Passed\033[0m " << "|| ";
    }

    if (FailedTestCount == 1)
    {
        cout << FailedTestCount << "\033[31m Test Failed\033[0m " << endl;
    }
    else
    {
        cout << FailedTestCount << "\033[31m Tests Failed\033[0m " << endl;
    }

    return 0;
}
