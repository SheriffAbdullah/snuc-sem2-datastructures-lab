/*
 Program to evaluate a postfix expression using 'stack' data structure.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Linked List Implementation of Stacks
struct node {
    int data;
    struct node *next;
} *head;

void push(float elt) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->next = head;
    temp->data = elt;
    head = temp;
}

float pop(void) {    // Note: Enter 'void' if function takes no parameters
    float retVal = head->data;
    head = head->next;
    return retVal;
}

// Checks if argument character is a number (0-9) or not
bool isNum(char num) {
    char numArr[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    
    for (int i = 0; i < 10; i++) {
        if (num == numArr[i]) {
            return true;
        }
    }
    return false;
}

// Checks if argument character is a symbol (+,-,/,*) or not
bool isSym(char sym) {
    char symArr[4] = {'+', '-', '*', '/'};
    
    for (int i = 0; i < 4; i++) {
        if (sym == symArr[i]) {
            return true;
        }
    }
    return false;
}

float charToInt(char num) {
    if (num == '1') {
        return 1.0;
    }
    else if (num == '2') {
        return 2.0;
    }
    else if (num == '3') {
        return 3.0;
    }
    else if (num == '4') {
        return 4.0;
    }
    else if (num == '5') {
        return 5.0;
    }
    else if (num == '6') {
        return 6.0;
    }
    else if (num == '7') {
        return 7.0;
    }
    else if (num == '8') {
        return 8.0;
    }
    else if (num == '9') {
        return 9.0;
    }
    else {
        // If 'num' is '0'
        return 0.0;
    }
}

// Evaluates the expression
float evaluate(float a, float b, char sym) {
    if (sym == '+') {
        return a + b;
    }
    else if (sym == '-') {
        return a - b;
    }
    else if (sym == '/') {
        return a / b;
    }
    else {
        // Symbol is '*'
        return a * b;
    }
}

int main() {
    
    printf("*** Postfix Evaluator *** \n");
    
    // Input
    char postfix[100];
    printf("\nEnter postfix expression: ");
    scanf("%s", postfix);
    
    int a, b;
    int i;
    
    for (i = 0; i < strlen(postfix); i++) {
        if (isNum(postfix[i]) == true) {
            push(charToInt(postfix[i]));
        }
        else if (isSym(postfix[i]) == true) {
            b = pop();
            a = pop();
            push(evaluate(a, b, postfix[i]));
        }
        else {
            printf("Invalid character(s) in expression. Only numbers (0-9) and \'+\', \'-\', \'/\' and \'*\' are allowed. \n");
            exit(0);
        }
    }
    
    // Output
    printf("Evaluated expression is %f \n", pop());
    
    return 0;
}

/*
 Note:
	'-4 7 * 5 +' -> Update code to evaluate expression with negative numbers.
*/

