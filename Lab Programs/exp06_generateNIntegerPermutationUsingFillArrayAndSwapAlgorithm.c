/*
A set of 'n' integers need to be generated in a random permutation each time the code is run.
Examples of legal permutations are: {4,2,1,3,5} and {2,3,1,5,4} for n = 5.
Each number has to occur only once and all numbers less than or equal to n should occur.
rand() or srand() function may be used for random number generation.

Consider the following algorithm:
Fill the array such that a[i] = i+1. Then swap each number with another number picked from a random index.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BILLION 1000000000.0
#define PRINT_ARR for (int i = 0; i < n; i++) printf("%d ", intArr[i]); printf("\n");

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // Input
    int n;    // 'n' -> Number of integers & maximum value of an integer
    printf("*** 'n' Integers Permutation Generator *** \n");
    printf("\nEnter the value of 'n': ");
    scanf("%d", &n);

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);    // Start Clock

    printf("\nGenerating a random array with a legal permutation. \n");
    printf("[");

    int intArr[n];
    int i;

    for (i = 0; i < n; i++) {
        intArr[i] = i + 1;
    }

    // 'rand()' -> will generate same sequence of random numbers every time (It assumes 'srand(1)' (i.e.) seed = 1 )
    // 'srand()' -> will generate different sequence of random numbers (Seed for random number depends on current time)
    srand(time(0));

    int randInt;

    for (i = 0; i < n; i++) {
        randInt = (rand() % n) + 1;    // Random number in range '1' to 'n' (upper & lower bound inclusive).
        swap(&intArr[i], &intArr[randInt]);

        if (i % (n/10) == 0) {
            printf("|");
        }
    }

    printf("] - Completed. \n");

    clock_gettime(CLOCK_REALTIME, &end);    // End Clock

    // To view array, un-comment 'PRINT_ARR' below
    // PRINT_ARR

    // Calculating Runtime
    long double runTime;

    if (end.tv_nsec - start.tv_nsec >= 0) {
        runTime = (end.tv_sec - start.tv_sec) + ((float)(end.tv_nsec - start.tv_nsec)) / BILLION;
    }
    else {
        runTime = (end.tv_sec - start.tv_sec - 1) + ((float)(end.tv_nsec - start.tv_nsec)) / BILLION;
    }

    // Output
    printf("\nRuntime is %Lf s. \n", runTime);    // Note: '%Lf' -> Long double, '%lf' -> Double, '%d' -> Integer
    printf("(Fill array + swap algorithm) \n");

    /*
    // Cross-verification of time values
    printf("'start.tv_sec' = %ld s\n", start.tv_sec);
    printf("'start.tv_nsec' = %ld ns\n", start.tv_nsec);
    printf("'end.tv_sec' = %ld s\n", end.tv_sec);
    printf("'end.tv_nsec' = %ld ns\n", end.tv_nsec);
    */

    return 0;
}
