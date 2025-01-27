/*
Consider the problem of finding 'k'th largest element from a group of 'N' numbers.
Sort the numbers in descending order and retrieve the kth element.
Add the logic to calculate running time to your code. Calculate the actual running times
for various values of 'N' and compare results obtained.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1000000000.0
#define UPPER_BOUND 1000
#define PRINT_ARR for (i = 0; i < numOfInputs; i++) {printf("%d\n", numArr[i]);}

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    // Variable to store runtime.
    struct timespec start, end;

    // Input
    printf("*** Program to Find 'k'th Largest Element *** \n");

    int numOfInputs;
    printf("\nEnter number of inputs: ");
    scanf("%d", &numOfInputs);

    int numArr[numOfInputs];
    int i, j;

    // Generate number array (+ Progress Bar)
    printf("Generating random number array with %d elements. \n", numOfInputs);
    printf("[");    // Progress Bar Start
    for (i = 0; i < numOfInputs; i++) {
        numArr[i] = (rand()%(UPPER_BOUND + 1));    // (100 + 1) = 'U' (Inclusive Upper Bound) + 1 -> Range: '0' to 'U'

        // When 'i' increments by '1/30'th of input size -> Print 1 bar
        if (i % (numOfInputs / 30) == 0) {
            printf("|");
        }
    }
    printf("] - Completed. \n");

    int k;    // 'k'th largest element to search
    printf("\nEnter 'k' value: ");
    scanf("%d", &k);

    clock_gettime(CLOCK_REALTIME, &start);    // Start Clock

    // Selection Sort
    int max, maxIndex;

    for (i = 0; i < numOfInputs; i++) {
        max = numArr[i];
        maxIndex = i;
        for (j = i; j < numOfInputs; j++) {
            if (numArr[j] > max) {
                max = numArr[j];
                maxIndex = j;
            }
        }
        swap(&numArr[i], &numArr[maxIndex]);

    }

    clock_gettime(CLOCK_REALTIME, &end);    // End Clock

    // Calculating Runtime
    long double runTime;

    if (end.tv_nsec - start.tv_nsec >= 0) {
        runTime = (end.tv_sec - start.tv_sec) + ((float)(end.tv_nsec - start.tv_nsec)) / BILLION;
    }
    else {
        runTime = (end.tv_sec - start.tv_sec - 1) + (end.tv_nsec - start.tv_nsec) / BILLION;
    }

    // Note: ((float)(end.tv_nsec - start.tv_nsec)) / BILLION -> 'float' type conversion not required if 'BILLION' is 'float' type

    // Output
    printf("'k'th largest element is %d. \n", numArr[k-1]);
    printf("\nRuntime is %Lf s. \n", runTime);    // Note: 'Lf' -> Long double, 'lf' -> Double
    printf("(Sort + search algorithm) \n");

    /*
    // Cross-verification of time values
    printf("'start.tv_sec' = %ld s\n", start.tv_sec);
    printf("'start.tv_nsec' = %ld ns\n", start.tv_nsec);
    printf("'end.tv_sec' = %ld s\n", end.tv_sec);
    printf("'end.tv_nsec' = %ld ns\n", end.tv_nsec);
    */

    return 0;
}

/*

start.tv_sec -> Timestamp at Start [Using system clock] (in s)
start.tv_nsec -> Timestamp of nanoseconds within the current second (in ns)
end.tv_sec -> Timestamp at End [Using system clock] (in s)
end.tv_nsec -> Timestamp of nanoseconds within the current second (in ns).

E.g. If Start -> 167876541.78770000 s & End- > 167876542.12200000 s
Then,
    start.tv_sec = 167876541 s
    start.tv_nsec = 78770000 ns
    end.tv_sec = 167876542 s
    end.tv_nsec = 12200000 ns

Note: 'end.tv_nsec - start.tv_nsec' < 0

Result,
= ((end.tv_sec - start.tv_sec) - 1) + ((end.tv_nsec - start.tv_nsec) / BILLION)
= ((2) - 1) + ((-66570000) / BILLION)
= (1) + (-0.66570000)
= 0.33430000 s

[
Note: If 'end.tv_nsec - start.tv_nsec' >= 0,

Result,
= ((end.tv_sec - start.tv_sec) + ((end.tv_nsec - start.tv_nsec) / BILLION)
]

Therefore,
    if 'end.tv_nsec - start.tv_nsec < 0', subtract '1' from 'end.tv_sec - start.tv_sec'.

Types of time representation:
i) Floating-Point: 0.02 s (Above representation)
ii) Integer: 20000000 ns

For Integer Representation:

if (end.tv_nsec - start.tv_nsec > 0) {
    runTime = (end.tv_sec - start.tv_sec) * BILLION + (end.tv_nsec - start.tv_nsec);
}
else {
    runTime = (end.tv_sec - start.tv_sec - 1) * BILLION + (end.tv_nsec - start.tv_nsec);
}

Note: Change 's' to 'ns' in output. ('ns' -> 'nanosecond')

*/
