/*
A set of 'n' integers need to be generated in a random permutation each time the code is run.
Examples of legal permutations are: {4,2,1,3,5} and {2,3,1,5,4} for n=5.
Each number has to occur only once and all numbers less than or equal to n should occur.
You may use the rand() or srand() function for random number generation.

Consider the following algorithm:
Fill the array a from a[0] to a[n-1] as follows: To fill a[i], generate random
numbers in the range until you get one that is not already in a[0], a[1], .. ,a[i-1].
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BILLION 1000000000.0
#define PRINT_ARR for (int i = 0; i < n; i++) printf("%d ", intArr[i]); printf("\n");

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
    int i, j;

    intArr[0] = (rand() % n) + 1;    // Generate random numbers from '1' to 'n' (upper & lower bound inclusive).

    for (i = 1; i < n; i++) {
        intArr[i] = (rand() % n) + 1;
        for (j = 0; j < i; j++) {
            if (intArr[j] == intArr[i]) {
                intArr[i] = rand()%(n+1);
                j = 0;
            }
        }
        if (i % (n/10) == 0) {
            printf("|");
        }
    }

    printf("] - Completed. \n");

    clock_gettime(CLOCK_REALTIME, &end);    // End Clock

    // Calculating Runtime
    long double runTime;

    if (end.tv_nsec - start.tv_nsec >= 0) {
        runTime = (end.tv_sec - start.tv_sec) + ((float)(end.tv_nsec - start.tv_nsec)) / BILLION;
    }
    else {
        runTime = (end.tv_sec - start.tv_sec - 1) + ((float)(end.tv_nsec - start.tv_nsec)) / BILLION;
    }

    // Output
    printf("\nRuntime is %Lf s. \n", runTime);    // Note: 'Lf' -> Long double, 'lf' -> Double
    printf("(Search array + insert algorithm) \n");

    /*
    // Cross-verification of time values
    printf("'start.tv_sec' = %ld s\n", start.tv_sec);
    printf("'start.tv_nsec' = %ld ns\n", start.tv_nsec);
    printf("'end.tv_sec' = %ld s\n", end.tv_sec);
    printf("'end.tv_nsec' = %ld ns\n", end.tv_nsec);
    */

    return 0;
}
