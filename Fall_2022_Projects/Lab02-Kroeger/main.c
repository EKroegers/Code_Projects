#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize Variables
    char strUserLoopToggle = 'y';

    int intUserInput;

    printf("%s", "Welcome to the Grade Estimator\n");

    // Begin Loop
    while (strUserLoopToggle == 'y')
    {
        int intGradeTotal = 0;

        // Capture Input
        for (int i = 0; i < 4; i++)
        {
            printf("Please enter grade value %d: ", (i + 1));
            scanf("%d", &intUserInput);

            intGradeTotal += intUserInput;
        }

        // Calculate Average
        float dblAverageGrade = (intGradeTotal/4);

        printf("Your average grade is: %.2lf\n", dblAverageGrade);

        // Determine Text Output
        if(dblAverageGrade >= 90)
        {
            printf("a letter grade of A is expected");
        }
        else if (dblAverageGrade >= 80)
        {
            printf("a letter grade of B is expected");
        }
        else if (dblAverageGrade >= 70)
        {
            printf("a letter grade of C is expected");
        }
        else if (dblAverageGrade >= 60)
        {
            printf("a letter grade of D is expected");
        }
        else
        {
            printf("a letter grade of F is expected");
        }

        // Prompt for Another Loop
        printf("\nWould you like to run the grade estimator again? (y/n): ");
        scanf(" %c", &strUserLoopToggle);
    }

    printf("Goodbye!");

    return 0;
}
