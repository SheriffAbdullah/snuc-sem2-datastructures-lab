/*
Consider the problem of finding 'k'th largest element from a group of 'N' numbers.
Place the first k elements in an array and sort it in descending order.
Read the remaining elements one by one and compare with kth element in the array.
If the element is smaller, ignore. Otherwise, place the element in the correct spot replacing the existing element.
When the comparisons end, the kth element in the array will be the kth largest element.
Add the logic to calculate running time to your code. Calculate the actual running times
for various values of 'N' and compare results obtained.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BILLION 1000000000.0
#define UPPER_BOUND 1000
#define PRINT_NUMARR for (i = 0; i < numOfInputs; i++) {printf("%d\n", numArr[i]); printf("\n");


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
        numArr[i] = (rand()%(UPPER_BOUND+1));    // (100 + 1) = 'U' (Inclusive Upper Bound) + 1 -> Range: '0' to 'U'

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

     // Placing first 'k' elements in 'arr'
     int arr[k];

     for (i = 0; i < k; i++) {
         arr[i] = numArr[i];
     }

    // Selection sort (Array with first 'k' elements) - in descending order
    int max, maxIndex;

    for (i = 0; i < k; i++) {
        max = arr[i];
        maxIndex = i;
        for (j = i; j < k; j++) {
            if (arr[j] > max) {
                max = arr[j];
                maxIndex = j;
            }
        }
        swap(&arr[i], &arr[maxIndex]);
    }

    int key;

    for (i = k; i < numOfInputs; i++) {
        if (numArr[i] < arr[k-1]) {
            continue;
        }
        else {
            key = numArr[i];
            j = k - 1;
            arr[j] = numArr[i];
            while (j >= 0 && key > arr[j-1]) {
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = key;
        }
    }

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
    printf("'k'th largest element is %d. \n", arr[k-1]);
    printf("\nRuntime is %Lf s. \n", runTime);    // Note: 'Lf' -> Long double, 'lf' -> Double
    printf("(Place & sort first 'k' elements in an array + insertion sort algorithm) \n");

    /*
    // Cross-verification of time values
    printf("'start.tv_sec' = %ld s\n", start.tv_sec);
    printf("'start.tv_nsec' = %ld ns\n", start.tv_nsec);
    printf("'end.tv_sec' = %ld s\n", end.tv_sec);
    printf("'end.tv_nsec' = %ld ns\n", end.tv_nsec);
    */

    return 0;
}

