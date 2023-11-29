#include <stdio.h>
#include <stdlib.h>

//Function declaration
double miles_to_km(double miles);

int main()
{
    double dblUserInput;

    // Get user input of miles
    printf("Enter how many miles: ");
    scanf("%lf", &dblUserInput);

    printf("%.1lf miles is equivalent to %.1lf kilometers", dblUserInput, miles_to_km(dblUserInput));
    return 0;
}

double miles_to_km(double miles)
{
    return (miles * 1.60934);
}
