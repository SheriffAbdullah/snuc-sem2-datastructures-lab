/*
Implementation of Selection Sort Algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// For runtime calculation
#define BILLION 1000000000
// For random number upper limit
#define UPPER_LIMIT 10000

void swap(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void selectionSort(int *ptrArr, int arrSize) {
    int i, j;
    int smallest, indSmallest;
    
    for (i = 0; i < arrSize; i++) {
        indSmallest = i;
        smallest = *(ptrArr + i);
        
        // Find smallest element and its index
        for (j = i; j < arrSize; j++) {
            if (*(ptrArr + j) < smallest) {
                indSmallest = j;
                smallest = *(ptrArr + j);
            }
        }
        
        swap(ptrArr + i, ptrArr + indSmallest);
    }
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
    int arrSize;
    int i;
    
    // Input
    printf("Enter number array size: ");
    scanf("%d", &arrSize);
    
    // Generate a random array with elements from 1 - 10000
    int arr[arrSize];
    int *ptrArr = arr;    // Pointer to array
    
    printf("\n* Generating random array with %d elements * ", arrSize);
    
    for (i = 0; i < arrSize; i++) {
        arr[i] = random() % 10000 + 1;    // '%' > '+' - Precedence
    }
    
    printf("- Done. \n");
    
    printf("* Sorting array * ");
    
    // Record clock time (start)
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    // Selection sort
    selectionSort(ptrArr, arrSize);
    
    // Record clock time (end)
    clock_gettime(CLOCK_REALTIME, &end);
    
    printf("- Done. \n");
    
    // Execution time = Start - End time
    float runTime = calcRunTime(start, end);
    
    // Output
    printf("\nSelection sort time taken is %f s. \n", runTime);
    
    return 0;
}

