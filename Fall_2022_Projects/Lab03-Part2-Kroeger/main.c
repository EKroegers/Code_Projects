#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize Variables
    int intUserInput; // Current Weight
    int intWeightLost; // Weight lost

    // Capture Input
    printf("Please enter your current weight: ");
    scanf("%d", &intUserInput);

    // Formatting Output
    printf("At your current weight of %d lbs, let's look at your numbers over the next 6 months:\n", intUserInput);
    printf("Month\tWeight\n");
    printf("-----------------\n");

    // Begin Loop
    for(int i = 0; i < 6; i++)
    {
        intWeightLost += 4;
        printf("%d\t%d\n", i+1, intUserInput - intWeightLost);
    }

    // Encouraging Statement
    printf("Wow, you could lose %d lbs over the next 6 months!", intWeightLost);

    return 0;
}
