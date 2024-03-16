#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Function declaration
void add_nums(double num1, double num2);
void subtract_nums(double num1, double num2);
void mult_nums(double num1, double num2);
void div_nums(double num1, double num2);
void mod_nums(double num1, double num2);

int main()
{
    // Variable declaration
    double num1;
    double num2;
    char chUserInput;

    bool arr[2] = {true, false};
    bool blnValidInput = arr[1];

    printf("Welcome to my calculator!\na - addition\ns - subraction\nm - multiplication\nd - division\no - modulo");

    // Get valid operation input
    while (!blnValidInput)
    {
        // Get user input of operation
        printf("Enter the mathemical operation [a, s, m, d, o]: ");
        scanf(" %c", &chUserInput);

        // Check for valid input
        if (chUserInput == 'a' || chUserInput == 's' || chUserInput == 'm' || chUserInput == 'd' || chUserInput == 'o')
        {
            blnValidInput = true;
        }
        else
        {
            printf("Invalid input!\n");
        }
    }

    // Collect input for two numbers
    printf("Enter two numbers (put a space between the numbers) and hit Enter: ");
    scanf("%d %d", &num1, &num2);

    // Switch statement to run the proper function
    switch (chUserInput)
    {
        case 'a':
            add_nums(num1, num2);
            break;

        case 's':
            subtract_nums(num1, num2);
            break;

        case 'm':
            mult_nums(num1, num2);
            break;

        case 'd':
            div_nums(num1, num2);
            break;

        case 'o':
            mod_nums(num1, num2);
            break;
    }

    return 0;
}

void add_nums(double num1, double num2)
{
    printf("%d and %d added together is %d", num1, num2, num1 + num2);
}

void subtract_nums(double num1, double num2)
{
    printf("%d minus %d is %d", num1, num2, num1 - num2);
}

void mult_nums(double num1, double num2)
{
    printf("%d and %d multiplied together is %d", num1, num2, num1 * num2);
}

void div_nums(double num1, double num2)
{
    printf("%d divided by %d added together is %d", num1, num2, num1 / num2);
}

void mod_nums(double num1, double num2)
{
    printf("%d modulo %d is %d", num1, num2, (int) num1 % (int) num2);
}
