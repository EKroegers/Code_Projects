#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.141

int main()
{
    // Part 1
    printf("I, Ethan Kroeger, enjoy C\n");

    // Part 2
    int intInputRadius;
    printf("Enter the radius of your circle: ");
    scanf("%d\n", &intInputRadius);

    float dblArea = pi * (intInputRadius * intInputRadius);
    printf("A circle with a RADIUS of %d has an AREA of %f\n", intInputRadius, dblArea);

    return 0;
}
