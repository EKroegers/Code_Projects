#ifndef MARKET_H
#define MARKET_H

#define MAXSTOCKS 20 // Number of Stocks in the Market

using namespace std;

#include <string> // For string
#include <stdlib.h> // For random

class Market
{
    public:

        Market() {
            setStockCount(0);
        }
        virtual ~Market() {};

        // Stocks within the Market
        class Stock
        {
            public:
                ///HL-1. Stock object constructor
                Stock() {
                    setName("empty");
                    setBasePrice(0);
                    setCurrentPrice(0);
                }
                ///HL-1. Stock object constructor
                Stock(string _strName, double _dblBasePrice) {
                    setName(_strName);
                    setBasePrice(_dblBasePrice);
                    setCurrentPrice(_dblBasePrice); // No fluctuations at creation
                }

                virtual ~Stock() {};

                    // Fields
                string getName();
                void setName(string _strName);

                double getBasePrice();
                void setBasePrice(double _dblBasePrice);

                double getCurrentPrice();
                void setCurrentPrice(double _dblCurrentPrice);

                    // Functions
                // Increase or decrease the price/value of the stock by a historically realistic amount
                double FluctuateStock(float currentValue);
                // Write a stock's daily price increase or decrease to a log
                void PrintDailyFluctuationsToLogFile(double priceChange, string logFileName);
                // Advance time forward and decide new price based on previous factors
                void Tick();

            private:
                // Name of the stock
                string strName;
                // Price randomly determined at the start of the simulation
                double dblBasePrice;
                // Price constantly modified throughout simulation
                double dblCurrentPrice;
        };

            //Market class
        // Field-related methods
        Stock getOur500();
        void setOur500(Stock _Our500);
        int getStockCount();
        void setStockCount(int _intStockCount);
        // Update S&P500 Analogue
        void Update500Value(double netStockValue);

            // Other Functions
        // Advance time forward for all stocks in market
        void TickAllStocks();


            // Manipulation Functions
        // Function to insert a new stock
        void AddNewStock(string _strName, double _dblBasePrice);
        // Find first empty index in array
        int FindFirstEmptyIndex(Stock StockList[]);
        // All stocks contained within the Market
        Stock AllStocks[MAXSTOCKS];
            void setAllStocks(Stock _AllStocks[]);

    private:
            // Market Fields
        // S&P 500 Analogue
        Stock Our500;
        int intStockCount;
};

#endif // MARKET_H
