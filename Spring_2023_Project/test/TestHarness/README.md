# HL-1: 
Three stock objects are added to the sample market object, and the name fields of the three are checked against the default values to determine if the data was properly passed. If the number of stocks with nondefault name fields is equivalent to the number of added stock objects, then the test is passed.
## Verbose Functions
Each field of the stock object is checked against its default values to determine existence. Each individual check is its own test, and is considered to be passing if the field is different from the default value.
# HL-2: 
The TickAll function is called 100 times, modulating the price the same number of times. The current price of the first stock entry is then checked against its initial price and if the values are different, then the test is passed.
## Verbose Functions
The modulation of the current price is checked every 10 calls of the TickAll function, and is considered to be passing if it is different from the initial price
# HL-3: 
A stock is added to the sample market object, and the TickAll function is called to advance time for all existing stocks. This updates the S&P500 aggregate analogue automatically. If the value of the aggregate is nonzero (meaning it was updated by TickAll) the test is passed.
## Verbose Functions
The automated math is checked against the manual calculation of the aggregate to determine if it is accurate. If the math is equivalent then the test is passed.
# HL-6: 
Two new identically valued stocks are added to the sample market object. The market is Ticked ten times, and the current prices of both are comparet to see if they are different. if they are then the test is passed and the requirement is fulfilled.
## Verbose Functions
The values are comared after every tick, and compared to see if they are identical, checking if their rate of change is the same over time.

# HL-9: 
Ten new stock objects are added to the sample market object. The code checks if both the first entry in AllStocks (which stocks added are automatically added to) is empty, as well as if the tenth entry is empty. If both are not empty, then the array has successfully recieved all then new stock objects and fulfills the requirement, passing the test.
## Verbose Functions
None
