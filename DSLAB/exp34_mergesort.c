/*
Program to sort a list of numbers using Merge sort algorithm.
You have to print the intermediate values in the above program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// For runtime calculation
#define BILLION 1000000000
// For random number upper limit
#define UPPER_LIMIT 10000
// For printing array
#define PRINT_ARR printf("Parse %d: ", parseCount); for (int p = 0; p < eltCount; p++) printf("%d ", *(ptrMainArr + p)); printf("\n"); parseCount++;

// Declare global parse counter
int parseCount = 0;
// Declare global pointer to array
int *ptrMainArr;
// Number of elements in array
int eltCount;

// Utility function to calculate execution time
long double calcRunTime(struct timespec start, struct timespec end) {
    long double runTime;
    
    runTime = (end.tv_sec - start.tv_sec + ((long double)(end.tv_nsec - start.tv_nsec) / BILLION));
    
    return runTime;
}

void merge(int *ptrArr, int numOfElts) {
    PRINT_ARR

    // Make a copy of elements
    int arr[numOfElts];
    
    for (int i = 0; i < numOfElts; i++) {
        arr[i] = ptrArr[i];
    }
    
    int halfIdx;
    
    if (numOfElts % 2 == 0) {
        halfIdx = numOfElts / 2;
    }
    else {
        halfIdx = (int)(numOfElts / 2) + 1;
    }
    
    int leftIdx = 0;
    int rightIdx = halfIdx;
    int mergeIdx = 0;
    
    // Until left half or right half becomes empty
    while (leftIdx < halfIdx && rightIdx < numOfElts) {
        // If first element on right half is smaller than first element on right half
        if (arr[rightIdx] < arr[leftIdx]) {
            // Append right element to merged list
            ptrArr[mergeIdx] = arr[rightIdx];
            mergeIdx++;
            rightIdx++;
        }
        // If first element on left half is smaller than or equal to first element on right half
        else {
            // Append left element to merged list
            ptrArr[mergeIdx] = arr[leftIdx];
            mergeIdx++;
            leftIdx++;
        }
    }
    
    // If left half elements are merged
    if (leftIdx == halfIdx) {
        // Append entire right half to the end of the merged array
        while (rightIdx < numOfElts) {
            ptrArr[mergeIdx] = arr[rightIdx];
            mergeIdx++;
            rightIdx++;
        }
    }
    // If right half elements are merged
    if (rightIdx == numOfElts) {
        // Append entire left half to the end of the merged array
        while (leftIdx < halfIdx) {
            ptrArr[mergeIdx] = arr[leftIdx];
            mergeIdx++;
            leftIdx++;
        }
    }
}

void mergeSort(int *ptrArr, int numOfElts) {
    // Array of size 1 cannot be split
    if (numOfElts <= 1) {
        return;
    }
    
    // Spilt array as evenly as possible
    if (numOfElts % 2 == 0) {
        // Sort left sub-array
        mergeSort(ptrArr, numOfElts / 2);
        // Sort right sub-array
        mergeSort(ptrArr + numOfElts / 2, numOfElts / 2);
    }
    else {
        // Sort left sub-array
        mergeSort(ptrArr, (int)(numOfElts / 2) + 1);
        // Sort right sub-array
        mergeSort(ptrArr + (int)(numOfElts / 2) + 1, (int)(numOfElts / 2));
    }
    
    // Merge left and right sub-arrays
    merge(ptrArr, numOfElts);
}

// Driver code
int main() {
    printf("*** Merge Sort *** \n");
    printf("Enter number of elements: ");
    scanf("%d", &eltCount);
    
    // Generate array with random numbers
    int arr[eltCount];
    for (int i = 0; i < eltCount; i++) {
        arr[i] = random() % UPPER_LIMIT + 1;
    }
    
    // Assign array to global pointer variable (to print array after each parse)
    ptrMainArr = arr;
    // Note: arr -> Pointer to array's first element
    
    // Start clock
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    // Sort array using Merge sort
    mergeSort(arr, eltCount);
    
    // End clock
    clock_gettime(CLOCK_REALTIME, &end);
    
    PRINT_ARR
    
    printf("\nMerge sort time taken is %Lf s.\n", calcRunTime(start, end));
    // Note: '%Lf' -> Long double
    printf("(Note: Time includes time taken to print array in each parse) \n");
    
    return 0;
}

