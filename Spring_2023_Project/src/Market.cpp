#include "headers/Market.h"
#include <stdlib.h> // For random
#include <string>   // For strings
#include <fstream> // For writing to text files with ofstream
#include <iostream> //invalid_argument() in fluctuateStock will only compile when this is included

using namespace std;
// Market class
///Creates a new stock and adds it to the market object.
void Market::AddNewStock(string _strName, double _dblBasePrice)
{
    Stock NewStock = Stock(_strName, _dblBasePrice);
    AllStocks[FindFirstEmptyIndex(AllStocks)] = NewStock;
    setStockCount(getStockCount() + 1);

    double netStockValue = 0;

    for (int i = 0; i < MAXSTOCKS; i++)
    {
        if (AllStocks[i].getName() != "empty")
        {
            netStockValue += AllStocks[i].getCurrentPrice();
        }
    }
	///Function calls setOur500() it derives value of
	///the market from the individual stocks to fulfill
	///HL-3
    setOur500(Stock("S&P500", netStockValue / intStockCount));
}
///Function advances all stocks in simulation by one day
///using Stock::Tick(): function
void Market::TickAllStocks()
{
    double netStockValue = 0;

    for (int i = 0; i < MAXSTOCKS; i++)
    {
        if (AllStocks[i].getName() != "empty")
        {
			///Code calls Stock::Tick() on each stock and fulfills
			///HL-6 as each stock's price fluctuates independently
            AllStocks[i].Tick();
            netStockValue += AllStocks[i].getCurrentPrice();
        }
    }

    Update500Value(netStockValue);
}
int Market::FindFirstEmptyIndex(Stock StockList[])
{
    for (int i = 0; i < MAXSTOCKS; i++)
    {
        if (StockList[i].getName() == "empty")
        {
            return i;
        }
    }
    return MAXSTOCKS;
}
int Market::getStockCount()
{
    return intStockCount;
}
void Market::setStockCount(int _intStockCount)
{
    intStockCount = _intStockCount;
}
Market::Stock Market::getOur500()
{
    return Our500;
}
void Market::setOur500(Stock _Our500)
{
    Our500 = _Our500;
}
//Saves the Market's value in a stock named Our500.
///Update500Value() helps fullfill HL-3 and HL-18 by
///fluctuating market value based on fluctuations of individual stock prices
void Market::Update500Value(double netStockValue)
{
    double oldValue = Our500.getCurrentPrice();
    setOur500(Stock("S&P500", netStockValue / intStockCount));
    double priceChange = (Our500.getCurrentPrice() - oldValue)/oldValue;
    Our500.PrintDailyFluctuationsToLogFile(priceChange, "market-log.txt");
}
// Stock
///FluctuateStock(): HL-18 and HL7 are fulfilled by
///realistic stock price fluctuations created by the
///function which in turn create realistic market
///fluctuations
double Market::Stock::FluctuateStock(float currentValue)
{
	//value to % rand by found at the last line of daily-returns.txt multiplied by 1000
	int randomNumber = rand() % 9990;
	double baselineReturn = 0.0;
	if (randomNumber >= 0 && randomNumber <= 9989){
        if (randomNumber <= 15) {
            baselineReturn = .09;
        } else if (randomNumber <= 35) {
            baselineReturn = .08;
        } else if (randomNumber <= 75) {
            baselineReturn = .07;
        } else if (randomNumber <= 154) {
            baselineReturn = .06;
        } else if (randomNumber <= 305) {
            baselineReturn = .05;
        } else if (randomNumber <= 599) {
            baselineReturn = .04;
        } else if (randomNumber <= 1171) {
            baselineReturn = .03;
        } else if (randomNumber <= 2279) {
            baselineReturn = .02;
        } else if (randomNumber <= 4323) {
            baselineReturn = .01;
        } else if (randomNumber <= 7368) {
            baselineReturn = .00;
        } else if (randomNumber <= 9341) {
            baselineReturn = -.01;
        } else if (randomNumber <= 9770) {
            baselineReturn = -.02;
        } else if (randomNumber <= 9909) {
            baselineReturn = -.03;
        } else if (randomNumber <= 9957) {
            baselineReturn = -.04;
        } else if (randomNumber <= 9973) {
            baselineReturn = -.05;
        } else if (randomNumber <= 9977) {
            baselineReturn = -.06;
        // No returns between -6% and -7% in data
        } else if (randomNumber <= 9981) {
            baselineReturn = -.08;
        // No returns between -8% and -9% in data
        } else if (randomNumber <= 9985) {
            baselineReturn = -.10;
        // No returns between -10% and -11% in data
        } else if (randomNumber <= 9989) {
            baselineReturn = -.12;
        } else {
            throw invalid_argument("values created should be between 1 and 9989");
        }
    } else {
        throw invalid_argument("values created should be between 1 and 9989");
    }
	currentValue = currentValue * ((1.0 + baselineReturn) + ((rand() % 100) / 10000.0));
	return currentValue;
}
///PrintDailyFluctuationsToLogFile(): HL-12 & HL-13
///Save the values of individual stocks on each
///day of the simulation to a log file. It is also
///used to save the market value to a separate log file
void Market::Stock::PrintDailyFluctuationsToLogFile(double priceChange, string logFileName) {
	ofstream logFile;
  	logFile.open (logFileName, ios::app);
  	logFile << strName << " - Price: " + to_string(dblCurrentPrice) + "     Price change: " + to_string(priceChange * 100) + "% \n";
 	logFile.close();
}
///Tick() fulfills HL-2
///code allowing stock price to fluctuate.
///Advances a stock in simulation by one day
void Market::Stock::Tick()
{
    double lastPrice = getCurrentPrice();
	///Tick() calls the FluctuateStock() function
	///on the stock's current price and sets the
	///new price as the function's output.
    setCurrentPrice(FluctuateStock(getCurrentPrice()));
    double priceChange = (getCurrentPrice() - lastPrice)/lastPrice;
    ///Function calls PrintDailyFluctuationsToLogFile()
	///to fulfill HL-13
    PrintDailyFluctuationsToLogFile(priceChange, "stock-log.txt");
}
string Market::Stock::getName()
{
    return strName;
}
void Market::Stock::setName(string _strName)
{
    strName = _strName;
}
double Market::Stock::getBasePrice()
{
    return dblBasePrice;
}
void Market::Stock::setBasePrice(double _dblBasePrice)
{
    dblBasePrice = _dblBasePrice;
}
///getCurrentPrice(): HL-1
double Market::Stock::getCurrentPrice()
{
    return dblCurrentPrice;
}
///setCurrentPrice(): HL-1
///each stock object has own price
void Market::Stock::setCurrentPrice(double _dblCurrentPrice)
{
    dblCurrentPrice = _dblCurrentPrice;
}
