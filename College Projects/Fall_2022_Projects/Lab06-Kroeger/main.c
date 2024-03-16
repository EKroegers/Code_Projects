#include <stdio.h>
#include <stdlib.h>

// Function Prototypes
double get_mean(const int [], int);
void search_array(const int [], int);
void sort_array(const int [], int);

int main()
{
    // Part 1
    int inputArray[5];
    printf("Part 1 - Enter 5 integers, each separated by a space: \n");
    scanf("%d %d %d %d %d", &inputArray[0], &inputArray[1], &inputArray[2], &inputArray[3], &inputArray[4]);

    // Part 2
    double mean;
    printf("Part 2 - Mean of Array: \n");
    mean = get_mean(inputArray, sizeof(inputArray) / sizeof(inputArray[0]));
    printf("%.1lf", mean);

    // Part 3
    printf("\nPart 3 - Search for 42: ");
    search_array(inputArray, sizeof(inputArray) / sizeof(inputArray[0]));

    // Part 4
    printf("\nPart 4 - Sorted Array: ");
    sort_array(inputArray, sizeof(inputArray) / sizeof(inputArray[0]));

    return 0;
}

double get_mean(const int inputArray[], int size)
{
    int arraySum = 0;

    for (int i = 0; i < size; i++)
    {
        arraySum += inputArray[i];
    }

    return ((double) arraySum / (double) size);
}

void search_array(const int inputArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (inputArray[i] == 42)
        {
            printf("\nYou wrote The Answer to the Great Question!");
            return;
        }
    }

    printf("\nYou might not know the answer to Life, the Universe, and Everything");
}

void sort_array(const int inputArray[], int size)
{
    int copyArray[5];

    for (int s = 0; s < size; s++)
    {
        copyArray[s] = inputArray[s];
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (copyArray[i] < copyArray[j])
            {
                int a = copyArray[i];
                copyArray[i] = copyArray[j];
                copyArray[j] = a;
            }
        }
    }

    printf("\n%d %d %d %d %d", copyArray[0], copyArray[1], copyArray[2], copyArray[3], copyArray[4]);
}
