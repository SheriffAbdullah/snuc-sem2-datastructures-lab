/*
C program to calculate the time complexity of the algorithm to calculate f(x) = ∑ [i = 0 to 'n'] (ai)*(x^i).
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define BILLION 1000000000
#define UPPER_LIMIT 10

float power(float num, int pow) {
    float prod = 1;
    int i;

    for (i = 0; i < pow; i++) {
        prod *= num;
    }

    return prod;
}

int main() {
    // Input
    int n;    // 'n' -> Order of polynomial
    printf("*** f(x) = ∑ [i = 0 to 'n'] (ai)*(x^i) Calculator *** \n");
    printf("\nEnter the value of 'n' (Degree of polynomial): ");
    scanf("%d", &n);

    int i;
    float x, sum = 0;
    float constant[n];

    printf("Enter (1) to generate random constants and (2) to enter values: ");

    int choice;
    scanf("%d", &choice);

    while (1) {
        if (choice == 1) {
            for (i = 0; i <= n ; i++) {
                constant[i] = ((rand() % UPPER_LIMIT) + 1);
            }
            break;
        }
        else if (choice == 2) {
            for (i = 0; i <= n ; i++) {
                printf("Enter co-efficient of x^%d: ", i);
                scanf("%f", &constant[i]);
            }
            break;
        }
        else {
            printf("\nPlease enter a valid option. \n");
            printf("Enter (1) to generate random constants and (2) to enter values: ");
            scanf("%d", &choice);
        }
    }

    printf("\nEnter value of 'x': ");
    scanf("%f", &x);

    struct timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);    // Start Clock

    for (i = 0; i <= n ; i++) {
        sum = sum + (constant[i] * power(x, i));
    }

    printf("f(%.1f) = %f \n", x, sum);

    clock_gettime(CLOCK_REALTIME, &end);    // End Clock

    // To view array, un-comment 'PRINT_ARR' below
    // PRINT_ARR

    // Calculating Runtime
    long double runTime;

    if (end.tv_nsec - start.tv_nsec >= 0) {
        runTime = (end.tv_sec - start.tv_sec) + ((float)(end.tv_nsec - start.tv_nsec) / BILLION);
    }
    else {
        runTime = (end.tv_sec - start.tv_sec - 1) + ((float)(end.tv_nsec - start.tv_nsec) / BILLION);
    }

    // Output
    printf("\nRuntime is %Lf s. \n", runTime);    // Note: '%Lf' -> Long double, '%lf' -> Double, '%d' -> Integer
    printf("(With user-defined function to calculate power) \n");

    /*
    // Cross-verification of time values
    printf("'start.tv_sec' = %ld s\n", start.tv_sec);
    printf("'start.tv_nsec' = %ld ns\n", start.tv_nsec);
    printf("'end.tv_sec' = %ld s\n", end.tv_sec);
    printf("'end.tv_nsec' = %ld ns\n", end.tv_nsec);
    */

    return 0;
}
