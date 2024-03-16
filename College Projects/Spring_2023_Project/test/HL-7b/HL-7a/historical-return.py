#!/bin/python3
# HL-7a is for parsing historical S&P500 returns to find a return distribution
# that can be implented in the stock market simulation's logic

import csv
# data is from the St. Louis Fed at https://fred.stlouisfed.org/series/SP500,
# accessed with most recent data from 1/27/23. The last ten years of S&P500
# daily closes are used to identify a baseline behavior for the market and our stock market simulation.

# read the contents of the csv file holding 10 years of market returns and put them in memory
with open('SP500.csv') as sp500:
    csvreader = csv.DictReader(sp500)
    daily_values = []
    last_sp_value = 0.0
    for row in csvreader:
        # Some days, presumably holidays, have "." as their closing
        # S&P500 value in the Fed's data. Skip these rows.
        if row['SP500'] == ".":
            continue
        elif last_sp_value == 0.0:
            current_sp_value = float(row['SP500'])
            daily_values.append(0.0)
            last_sp_value = current_sp_value
        else:
            current_sp_value = float(row['SP500'])
            daily_values.append(((current_sp_value - last_sp_value) * 100)/last_sp_value)
            last_sp_value = current_sp_value
sp500.close()

# sort daily_values, a necessary step for the recursive implementation of the function count_days
sorted_daily_values = sorted(daily_values, key = float)

# function counts the number of days in the last ten years where the daily
# return has been in a percentage point range of total_days_of_data.
# total_days_of_data begins as the length of sorted_daily_values but it must be
# entered as a separate and independent parameter from sorted_daily_values.
# python's "pass by assignment" approach and the shrinking size of
# sorted_daily_values list make the separation of the two mandatory
def count_days(sorted_daily_values, total_days_of_data, upper_bound, file_name):
    number_of_days = 0
    # Code written so the range_of_category can be changed to a smaller or larger range and still run
    range_of_category = 1
    for daily_value in sorted_daily_values:
        if daily_value < upper_bound:
            number_of_days = number_of_days + 1
            # removing the values from the list prevents them from being used in the
            # recursive call.
            # Since the code is only checking if a value is lower than the
            # "upper_bound" value this is necessary for accuracy of numbers.
            # Also drastically reduces number of steps for this to run
            sorted_daily_values.pop(0)
        else:
            # break and make recursive call once all values in range have been used
            count_days(sorted_daily_values, total_days_of_data, upper_bound + range_of_category, file_name)
            break
    daily_return_data_file = open(file_name, "a")
    daily_return_data_file.write(str(upper_bound - range_of_category) + " " + str(upper_bound) + " " + str(round(number_of_days/total_days_of_data, 4)) + "\n")
    daily_return_data_file.close()
    print(str(upper_bound - range_of_category) + " to " + str(upper_bound) + " percent: " + str(round(number_of_days/total_days_of_data, 4)))

print("Number of days in the last ten years where the S&P500 has had returns between the following percentages...")
daily_return_data_file = open("daily-returns.txt", "w")
# write first line of text file to serve as a key
daily_return_data_file.write("Key: Lower bound - Upper bound - Percentage of daily returns in this range\n")
daily_return_data_file.close()

count_days(sorted_daily_values, len(sorted_daily_values), -12, "daily-returns.txt")

#code to read the data that has been writen and add up the recorded probabilities of return
# This tests that the write was correct. If the total probability is close to 1.000 then
# every number was wriiten correctly and the rounding did not drop too much of the result
daily_return_data_file = open("daily-returns.txt", "r")
lines = daily_return_data_file.readlines()
total_probability = 0.0
for line in lines:
    contents = line.split()
    if len(contents) > 3:
        continue
    #probability/occurrence of a return is the third element on each line
    total_probability = total_probability + float(contents[2])
daily_return_data_file.close()
daily_return_data_file = open("daily-returns.txt", "a")
daily_return_data_file.write(str(total_probability))
print("Total probability after rounding: " + str(total_probability))


print("Minimum: " + str(min(daily_values)))
print("Maximum: " + str(max(daily_values)))

