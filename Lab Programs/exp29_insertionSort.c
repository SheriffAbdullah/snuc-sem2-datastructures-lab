/*
Implementation of Insertion Sort Algorithm
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

void insertionSort(int *ptrArr, int arrSize) {
    int i, j, num;
    
    for (i = 1; i < arrSize; i++) {
        j = i;
        num = *(ptrArr + j);
        
        /*
        For ascending order sorting:
         - Insert 'num' if element to the left (in sorted array) is smaller
           or if it has reached the left end of sorted list (i.e.) it is the smallest number.
        */
        
        while (num < *(ptrArr + j - 1) && j != -1) {
            *(ptrArr + j) = *(ptrArr + j - 1);
            j--;
        }
        
        *(ptrArr + j) = num;
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
    
    // Insertion sort
    insertionSort(ptrArr, arrSize);
    
    // Record clock time (end)
    clock_gettime(CLOCK_REALTIME, &end);
    
    printf("- Done. \n");
    
    // Execution time = Start - End time
    float runTime = calcRunTime(start, end);
    
    // Output
    printf("\nInsertion sort time taken is %f s. \n", runTime);
    
    return 0;
}

/*
Note:
- Insertion sort is a natural sorting algorithm used by humans.
 Procedure:
 i)   Pick up a number from unsorted array,
 ii)  Insert it into the right place in your sorted array,
 iii) Repeat.
*/
