/*
Implementation of Linear Search Algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// For runtime calculation
#define BILLION 1000000000
// For random number upper limit
#define UPPER_LIMIT 10000

int linearSearch(int num, int *ptrArr, int arrSize) {
    int i;

    for (i = 0; i < arrSize; i++) {
        // Element found
        if (*(ptrArr + i) == num) {
            return 1;
        }
    }
    
    // Element not found
    return 0;
}

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

float calcRunTime(struct timespec start, struct timespec end) {
    long double runTime;
    
    if (end.tv_nsec - start.tv_nsec >= 0) {
        runTime = (end.tv_sec - start.tv_sec) + ((float)(end.tv_nsec - start.tv_nsec) / BILLION);
    }
    else {
        runTime = (end.tv_sec - start.tv_sec - 1 + ((float)(end.tv_nsec - start.tv_nsec) / BILLION));
    }
    
    return runTime;
}

int main() {
    int num, arrSize;
    int i;
    
    // Input
    printf("Enter number array size: ");
    scanf("%d", &arrSize);
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Generate a random array with elements from 1 - 10000
    int arr[arrSize];
    int *ptrArr = arr;
    
    printf("\n* Generating random array with %d elements * ", arrSize);
    
    for (i = 0; i < arrSize; i++) {
        arr[i] = random() % 10000 + 1;    // '%' > '+' - Precedence
    }

    printf("- Done. \n");
    
    // Record clock time (start)
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    // Search for number in array + Output
    linearSearch(num, ptrArr, arrSize) == 0 ? printf("\nNumber not found in array. \n") : printf("\n\'%d\' found in array. \n", num);
    
    // Record clock time (end)
    clock_gettime(CLOCK_REALTIME, &end);
    
    // Execution time = Start - End time
    float runTime = calcRunTime(start, end);
    
    // Output
    printf("\nLinear search time taken is %f s. \n", runTime);
    
    return 0;
}

