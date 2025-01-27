/*
There are n stairs (minimum 5), a person standing at the bottom wants to reach the top.
The person can climb either 1 stair, 3 stairs or 5 stairs at a time.
Write a C program using recursion to count the number of ways, the person can reach the top.
*/
/*
#include <stdio.h>

// Recursive function
int numOfWays(int n) {
    if (n == 0) {
        return 1;
    }
    else if (n < 0) {
        return 0;
    }
    else {
        return numOfWays(n - 5) + numOfWays(n - 3) + numOfWays(n - 1);
    }

}

int main() {
    // Input from user
    int numOfStairs;

    while (1) {    // '1' -> 'true' & '0' -> 'false'
        printf("Enter number of stairs (minimum = 5): ");
        scanf("%d", &numOfStairs);

        if (numOfStairs < 5) {
            printf("Invalid input. Please enter a value equal to or above 5. \n");
            continue;
        }
        else {
            break;
        }
    }

    // Output
    int totalWays = numOfWays(numOfStairs);
    printf("There are %d ways a person can reach the top. \n", totalWays);

    return 0;
}
*/
/*
#include <stdio.h>

int main() {
    int numOfPairs;
    float x, y;

    printf("Enter number of ordered pairs: ");
    scanf("%d", &numOfPairs);

    float xArray[numOfPairs][2];
    float yArray[numOfPairs];
    float xStarArray[2][numOfPairs];
    float xStarxArray[2][2] = {0};
    float xStarxInverseArray[2][2] = {0};
    float xStaryArray[2][1] = {0};
    float adjxStarxArray[2][2] = {0};
    float successArray[2] = {0};
    float xSuccessArray[numOfPairs];
    float errorArray[numOfPairs];

    for (int i = 0; i < numOfPairs; i++) {
        printf("Enter 'x' value: ");
        scanf("%f", &xArray[i][0]);
        printf("Enter 'y' value: ");
        scanf("%f", &yArray[i]);

        xArray[i][1] = 1;
        xStarArray[0][i] = xArray[i][0];
        xStarArray[1][i] = 1;
    }

    float sum;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum = 0;
            for (int k = 0; k < numOfPairs; k++) {
                sum += xStarArray[i][k] * xArray[k][j];
            }
            xStarxArray[i][j] = sum;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1; j++) {
            sum = 0;
            for (int k = 0; k < numOfPairs; k++) {
                sum += xStarArray[i][k] * yArray[k];
            }
            xStaryArray[i][j] = sum;
        }
    }

    float detOfxStarx = (xStarxArray[0][0] * xStarxArray[1][1]) - (xStarxArray[0][1] * xStarxArray[1][0]);

    adjxStarxArray[0][0] = xStarxArray[1][1];
    adjxStarxArray[0][1] = - xStarxArray[0][1];
    adjxStarxArray[1][0] = - xStarxArray[1][0];
    adjxStarxArray[1][1] = xStarxArray[0][0];

    xStarxInverseArray[0][0] = adjxStarxArray[0][0] / detOfxStarx;
    xStarxInverseArray[0][1] = adjxStarxArray[0][1] / detOfxStarx;
    xStarxInverseArray[1][0] = adjxStarxArray[1][0] / detOfxStarx;
    xStarxInverseArray[1][1] = adjxStarxArray[1][1] / detOfxStarx;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1; j++) {
            sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += xStarxInverseArray[i][k] * xStaryArray[k][j];
            }
            successArray[i] = sum;
        }
        printf("\n");
    }

    for (int i = 0; i < numOfPairs; i++) {
        for (int j = 0; j < 1; j++) {
            sum = 0;
            for (int k = 0; k < 2; k++) {
                sum += xArray[i][k] * successArray[k];
            }
            xSuccessArray[i] = sum;
        }
    }

    for (int i = 0; i < numOfPairs; i++) {
        errorArray[i] = yArray[i] - xSuccessArray[i];
    }

    float error = 0;

    for (int i = 0; i < numOfPairs; i++) {
        error += errorArray[i] * errorArray[i];
    }

    printf("xArray: \n");
    for (int i = 0; i < numOfPairs; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f\t", xArray[i][j]);
        }
        printf("\n");
    }

    printf("yArray: \n");
    for (int i = 0; i < numOfPairs; i++) {
        printf("%f\n", yArray[i]);
        printf("\n");
    }

    printf("xStarArray: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < numOfPairs; j++) {
            printf("%f\t", xStarArray[i][j]);
        }
        printf("\n");
    }

    printf("xStarxArray: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f\t", xStarxArray[i][j]);
        }
        printf("\n");
    }

    printf("xStarxInverseArray: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f\t", xStarxInverseArray[i][j]);
        }
        printf("\n");
    }

    printf("xStaryArray: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1; j++) {
            printf("%f\t", xStaryArray[i][j]);
        }
        printf("\n");
    }
    printf("detOfxStarx: %f\n", detOfxStarx);
    printf("adjxStarxArray: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%f\t", adjxStarxArray[i][j]);
        }
        printf("\n");
    }

    printf("Success Array: \n");
    printf("%f -> Slope (c) \n", successArray[0]);
    printf("%f -> Constant (d) \n", successArray[1]);

    printf("xSuccessArray: \n");
    for (int i = 0; i < numOfPairs; i++) {
        printf("%f\n", xSuccessArray[i]);
    }

    printf("errorArray: \n");
    for (int i = 0; i < numOfPairs; i++) {
        printf("%f\n", errorArray[i]);
    }

    printf("Error: %f", error);


    return 0;
}
*/
/*
The following algorithm prints all the permutations of n integers.
Each integer has an associated direction L to R or R to L. An integer is ‘mobile’ if its adjacent integer in its associated direction is less than it.
Algorithm:
START: Determine the largest mobile integer ‘m’ If there is no mobile integer, stop.
Exchange ‘m’ with its adjacent integer in the associated direction of ‘m’ For all integers greater than ‘m’, change the associated direction. For the remaining integers, retain the same direction
Print the new permutation
Go to START
Output for n=3:
Implement the above algorithm. The output should be printed along with direction of each integer as given in the above example.

*/
/*
#include <stdio.h>

void printPermutation(int numOfNums, int arr[], int dir[]) {
    for (int i = 0; i < numOfNums; i++) {
        if (dir[i] == 0) {
            printf("<-\t");
        } else {
            printf("->\t");
        }
    }

    printf("\n");

    for (int i = 0; i < numOfNums; i++) {
        printf("%d\t", arr[i]);
    }
}

int largeIndex(int arr[], numOfElts) {
    int temp = 0, i;
    int index = 0;
    for (i = 0; i < numOfElts; i++) {
        if (arr[i] > temp) {
            temp = arr[i];
            index = i;
        }
    }

    return index;
}

indexOf(int num, int arr[], int numOfElts) {
    for (int i = 0; i < numOfElts; i++) {
        if (num == arr[i]) {
            return i;
        }
    }
}

int main() {
    // Input
    int numOfNums;
    printf("Enter number of numbers: ");
    scanf("%d", &numOfNums);

    // Create dir and number array
    int orig_arr[numOfNums], arr[numOfNums];
    int dir[numOfNums];
    int i, j;

    // Fill values for dir and number array
    for (i = 0; i < numOfNums; i++) {
        arr[i] = i + 1;
        orig_arr[i] = i + 1;
        dir[i] = 0;    // L = Arrow points from L <- R
    }

    printPermutation(numOfNums, arr, dir);

    int largest = numOfNums;

    for (i = 0; i < numOfNums; i++) {
        if ((arr[0] == largest && dir[0] == 0) || (arr[numOfNums - 1] == largest && dir[numOfNums - 1] == 1)) {
            largest--;
        }

    }

    while (1) {
        // If direction is Left
        if (dir[largeIndex(arr, numOfNums)] == 0) {
            // If number to the left is lesser
            if (arr[largeIndex(arr, numOfNums) - 1] < arr[largeIndex(arr, numOfNums)]) {

            }
            // If number to the left is greater
            else {

            }
        }
        // If direction is Right
        else if (dir[largeIndex(arr, numOfNums)] == 1) {
            // If number to the right is lesser
            if (arr[largeIndex(arr, numOfNums) + 1] < arr[largeIndex(arr, numOfNums)]) {

            }
            // If number to the right is greater
            else {

            }
        }
    }
    return 0;
}

*/
/*
C program which takes another C Program as input and identifies all the keywords presents in the code.
Print all the keywords present in the code together with the total count of keywords.
If a keyword appears multiple times, then it should be counted only once.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Input - Program file name
    char program[1000];
    printf("Enter program file name (with extension): ");
    scanf("%s", program);

    FILE *fptr = fopen(program, "r");    // DO NOT use single-quotes for file mode.

    char keyword[35][10] = {"auto", "else", "long", "switch", "break", "enum", "register", "typedef", "case",
                            "extern", "return", "union", "char", "float", "short", "unsigned", "const", "for",
                            "signed", "void", "continue", "goto", "sizeof", "volatile", "default", "if", "static",
                            "while", "do", "int", "struct", "double"};

    int keywordCount[35] = {0};

    // Number of characters in program
    int numOfChars, i, j;
    fseek(fptr, 0, SEEK_END);
    numOfChars = ftell(fptr);
    rewind(fptr);

    // Clear noise in text
    for (i = 0; i < numOfChars; i++) {
        // Avoid strings
        if (program[i] == '"') {
            while (program[i+1] != '"') {
                i++;
            }
            i += 2;
        }

        // Avoid single-line comments
        if (program[i] == '/' && program[i+1] == '/') {
            while (program[i+1] != '\n') {
                i++;
            }
            i += 2;
        }

        // Avoid multi-line comments
        if (program[i] == '/' && program[i+1] == '*') {
            while (program[i+1] != '/' && program[i+2] != '*') {
                i++;
            }
            i += 3;
        }

        // Change parentheses and semicolons -> Space ('Parentheses' = Plural of 'Parenthesis')
        if (program[i] == ')' || program[i] == '(' || program[i] == ';') {
            program[i] = ' ';
        }
        putc(program[i], stdin);
    }

    rewind(fptr);



    // Count keywords
    char word[50];

    for (i = 0; i < numOfChars; i++) {
        if (program[i] != ' ') {
            strncat(word, &program[i], 1);    // strncat(<destination>, <source>, <num_of_chars>);
        }
        else {
            for (j = 0; j < 32; j++) {
                // If 'word' is a keyword
                if (strcmp(word, keyword[i]) == 0) {
                    // Increment corresponding count by 1
                    keywordCount[i]++;
                }
                else {
                    continue;
                }
            }
            // Clear 'word'
            for (j = 0; j < strlen(word); j++) {
                word[j] = 0;    // 0 = 'NULL' = '\0'
            }
        }
    }

    // Output
    for (i = 0; i < 33; i++) {
        if (keywordCount[i] > 0) {
            printf("%s\t: %d \n", keyword[i], keywordCount[i]);
        }
    }

    return 0;
}

