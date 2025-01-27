/*
Implement 2 stacks in one array. The size of each stack must not be fixed - each stack should be able
to grow as long as there is space left in the array.
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 5

// Stack
int dualStk[MAX_SIZE];
int stk1Size = 0, stk2Size = 0;
// Note: Stack '1' base index = '0' & stack '2' base index = 'MAX_SIZE - 1'

bool isFull() {
    if (stk1Size + stk2Size == MAX_SIZE) {
        return true;
    }
    else {
        return false;
    }
}

bool isEmpty(int stkID) {
    if (stkID == 1) {
        if (stk1Size == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else if (stkID == 2) {
        if (stk2Size == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

void push() {
    if (isFull()) {
        printf("Stack overflow. \n");
    }
    else {
        int elt, stkID;
        printf("Enter stack ID: ");
        scanf("%d", &stkID);
        printf("Enter element to push: ");
        scanf("%d", &elt);

        if (stkID == 1) {
            stk1Size++;
            dualStk[stk1Size - 1] = elt;
            printf("\'%d\' pushed into stack \'%d\'. \n", elt, stkID);
        }
        else if (stkID == 2) {
            stk2Size++;
            dualStk[MAX_SIZE - stk2Size] = elt;
            printf("\'%d\' pushed into stack \'%d\'. \n", elt, stkID);
        }
        else {
            printf("Invalid stack ID. \n");
        }
    }
}

void pop() {
    int stkID;
    printf("Enter stack ID: ");
    scanf("%d", &stkID);

    if (stkID > 2 || stkID < 1) {
        printf("Invalid stack ID. \n");
    }
    else if (isEmpty(stkID)) {
        printf("Stack underflow. \n");
    }
    else {
        if (stkID == 1) {
            printf("\'%d\' popped out of stack \'%d\'. \n", dualStk[stk1Size - 1], stkID);
            stk1Size--;
        }
        else if (stkID == 2) {
            printf("\'%d\' popped out of stack \'%d\'. \n", dualStk[MAX_SIZE - stk2Size], stkID);
            stk2Size--;
        }
        else {
            printf("Invalid stack ID. \n");
        }
    }
}

void top() {
    int stkID;
    printf("Enter stack ID: ");
    scanf("%d", &stkID);

    if (isEmpty(stkID)) {
        printf("Stack \'%d\' is empty. \n", stkID);
    }
    else {
        if (stkID == 1) {
            printf("%d <- Stack \'%d\' top. \n", dualStk[stk1Size - 1], stkID);
        }
        else if (stkID == 2) {
            printf("%d <- Stack \'%d\' top. \n", dualStk[MAX_SIZE - stk2Size], stkID);
        }
        else {
            printf("Invalid stack ID. \n");
        }
    }
}

int main() {
    printf("*** TWO Stacks In ONE Array Implementation *** \n");
    printf("** Options Menu ** \n");
    printf("1. Push into stack. \n");
    printf("2. Pop out of stack. \n");
    printf("3. Peek at top. \n");
    printf("0. Exit. \n");

    int opt;

    while (true) {
        printf("\nEnter option: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                top();
                break;
            case 0:
                printf("Program ended. \n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please enter a valid option. \n");
                break;
        }
    }

    return 0;
}


