/*
Program to check whether a given number is palindrome or not using Stack data structure.
*/

#include <stdio.h>

// Stack
int stk[100];
int stkSize = 0;

void push(int elt) {
    stkSize++;    // Note: ALWAYS increment/grow stack size, THEN insert element.
    stk[stkSize-1] = elt;
}

int numLen(long int num) {
    if (num == 0) {
        return 0;
    }
    else {
        return 1 + numLen(num / 10);
    }
}

void pop() {
    stkSize--;
}

int top() {
    return stk[stkSize - 1];
}

int main() {
    printf("*** Palindrome Or Not *** \n");

    // Input
    long int num;
    printf("\nEnter a number: ");
    scanf("%ld", &num);

    int len = numLen(num);

    // Push first half of into stack
    for (int i = 0; i < len / 2; i++) {
        push(num % 10);
        num /= 10;
    }

    // Ignore middle element (if number of digits is odd)
    if (len % 2 != 0) {
        num /= 10;
    }

    // Check if reverse of first half = second half
    int flag = 0;

    for (int i = len / 2; i < len; i++) {
        if (top() == num % 10) {
            num /= 10;
            pop();
        }
        else {
            flag = 1;
            break;
        }
    }

    // Output
    if (flag == 0) {
        printf("Number is palindrome. \n");
    }
    else {
        printf("Number is not palindrome. \n");
    }

    return 0;
}
