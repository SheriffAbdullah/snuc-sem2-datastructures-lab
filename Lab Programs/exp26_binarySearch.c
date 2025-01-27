/*
Implementation of Binary Search Algorithm
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// For runtime calculation
#define BILLION 1000000000
// For random number upper limit
#define UPPER_LIMIT 10000

int binarySearch(int elt, int *ptrArr, int low, int up) {
    int mid;
    
    // Find middle element
    if ((low + up) % 2 == 0) {
        mid = (low + up) / 2;
    }
    else {
        mid = (low + up + 1) / 2;
    }
    
    /*
    // Print Values
    printf("Low = %d, Mid = %d, Up = %d: ", low, mid, up);

    for (int i = low; i < up + 1; i++) {
    printf("%d ", *(ptrArr + i));
    }

    printf("\n");
     
    // Note: If values are printed, runtime may be more than actual runtime.
    */
    
    // Array completely searched. Element not found.
    if (low > up) {
        return 0;
    }
    // Element found at middle
    if (*(ptrArr + mid) == elt) {
        return 1;
    }
    else {
        // Element is smaller than mid element, find element in left half of array
        if (elt < *(ptrArr + mid)) {
            up = mid - 1;
            return binarySearch(elt, ptrArr,  low, up);
        }
        // Element is larger than mid element, find element in right half of array
        else {
            low = mid + 1;
            return binarySearch(elt, ptrArr,  low, up);
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
    int i, j;
    
    // Input
    printf("Enter number array size: ");
    scanf("%d", &arrSize);
    
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Generate a random array with elements from 1 - 10000
    int arr[arrSize];
    int *ptrArr = arr;    // Pointer to array
    
    printf("\n* Generating random array with %d elements * ", arrSize);
    
    for (i = 0; i < arrSize; i++) {
        arr[i] = random() % 10000 + 1;    // '%' > '+' - Precedence
    }
    
    printf("- Done. \n");
    
    // Lower & Upper bounds of Array
    int low = 0, up = arrSize - 1;
    
    // Sort array
    printf("* Sorting array * ");
    
    for (i = 0; i < arrSize; i++) {
        
        for (j = 0; j < arrSize - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    
    printf("- Done. \n");
    
    // Record clock time (start)
    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    
    // Search for number in array + Output
    binarySearch(num, ptrArr, low, up) == 0 ? printf("\nNumber not found in array. \n") : printf("\n\'%d\' found in array. \n", num);
    
    // Record clock time (end)
    clock_gettime(CLOCK_REALTIME, &end);
    
    // Execution time = Start - End time
    float runTime = calcRunTime(start, end);
    
    // Output
    printf("\nBinary search time taken is %f s. \n", runTime);
    
    return 0;
}

/*
 In Bubble Sort,
 
 Every iteration, it will sort 1 element to the right end of the array.
 So, do not check
 last element after 1st iteration,
 last 2 elements after 2nd iteration,
 and so on...
 
 'j < arrSize - 1' -> Will check sorted part of array too = More time complexity.
 'j < arrSize - i - 1' -> Will avoid checking last 'i' elements in array = Better.
 
Note:
- Bubble sort is not considered in Binary Search.
- Time Complexity of Binary Search is 'O(log N)'.
*/

