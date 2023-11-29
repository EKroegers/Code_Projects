#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed random numbers
    srand(time(0));

    int intDieRollCount;

    // Get user input
    printf("How many rolls? ");
    scanf("%d\n", &intDieRollCount);

    // Initialize array
    int DieRolls[intDieRollCount];

    // Roll dice
    printf("Simulating %d rolls... \n", intDieRollCount);
    for(int i = 0; i <= intDieRollCount; i++)
    {
        int Roll1 = (rand() % 6) + 1;
        int Roll2 = (rand() % 6) + 1;

        // Add to result array
        DieRolls[i] = Roll1 + Roll2;
    }

    // Display results
    printf("Results: \n");
    for(int i = 2; i <= 12; i++)
    {
        int tempNumTally = 0;

        // Count the result for each number i
        for(int j = 0; j <= intDieRollCount; j++)
        {
            // For each index that matches i, increment the tally count
            if(DieRolls[j] == i)
            {
                tempNumTally++;
            }
        }

        // Display result for the roll i
        printf("%d was rolled %d times \n", i, tempNumTally);
    }

    return 0;
}
