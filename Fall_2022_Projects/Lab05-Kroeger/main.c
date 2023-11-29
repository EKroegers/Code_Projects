#include <stdio.h>
#include <stdlib.h>

//Function declaration
void add_nums(double num1, double num2, FILE* outputFile);
void subtract_nums(double num1, double num2, FILE* outputFile);
void mult_nums(double num1, double num2, FILE* outputFile);
void div_nums(double num1, double num2, FILE* outputFile);
void mod_nums(double num1, double num2, FILE* outputFile);

int main()
{
    // Variable declaration
    double num1;
    double num2;
    char chUserInput;

    FILE *inputFile = fopen("lab5-input.txt", "r"); // Read in values
    FILE *outputFile = fopen("lab5-output.txt", "w"); // Write out values

    // Read in initial line
    fscanf(inputFile, "%c %lf %lf", &chUserInput, &num1, &num2);

    // Get valid operation inputs
    while ( chUserInput != ' ')
    {
        // Switch statement to run the proper function
        switch (chUserInput)
        {
            case 'a':
                add_nums(num1, num2, outputFile);
                break;

            case 's':
                subtract_nums(num1, num2, outputFile);
                break;

            case 'm':
                mult_nums(num1, num2, outputFile);
                break;

            case 'd':
                div_nums(num1, num2, outputFile);
                break;

            case 'o':
                mod_nums(num1, num2, outputFile);
                break;
        }

        fscanf(inputFile, "%c %lf %lf", &chUserInput, &num1, &num2);
    }

    // Clean Up
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

void add_nums(double num1, double num2, FILE* outputFile)
{
    printf("%.0lf and %.0lf added together is %.0lf\n", num1, num2, num1 + num2);
    fprintf(outputFile, "%.0lf and %.0lf added together is %.0lf\n", num1, num2, num1 + num2);
}

void subtract_nums(double num1, double num2, FILE* outputFile)
{
    printf("%.0lf minus %.0lf is %.0lf\n", num1, num2, num1 - num2);
    fprintf(outputFile, "%.0lf minus %.0lf is %.0lf\n", num1, num2, num1 - num2);
}

void mult_nums(double num1, double num2, FILE* outputFile)
{
    printf("%.0lf and %.0lf multiplied together is %.0lf\n", num1, num2,  num1 * num2);
    fprintf(outputFile, "%.0lf and %.0lf multiplied together is %.0lf\n", num1, num2, num1 * num2);
}

void div_nums(double num1, double num2, FILE* outputFile)
{
    printf("%.0lf divided by %.0lf is %.0f\n", num1, num2, num1 / num2);
    fprintf(outputFile, "%.0lf divided by %.0lf is %.0lf\n", num1, num2, num1 / num2);
}

void mod_nums(double num1, double num2, FILE* outputFile)
{
    printf("%.0lf modulo %.0lf is %d\n", num1, num2, (int) num1 % (int) num2);
    fprintf(outputFile, "%.0lf modulo %.0lf is %d\n", num1, num2, (int) num1 % (int) num2);
}
