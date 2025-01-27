/*
Given an expression, check if the expression is correctly parenthesized or not using a stack. 
Assume that 3 types of parentheses are used in the expression: { }, ( ), [ ].
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack
char stk[100];
int stkSize = 0;

void push(char elt) {
    stkSize++;
    stk[stkSize - 1] = elt;
}

void pop() {
    stkSize--;
}

char top() {
    return stk[stkSize - 1];
}

int main() {
    // Input
    char expr[1000];
    printf("Enter an expression: ");
    fgets(expr, 100, stdin);    // 'STDIN' -> Invalid
    // 'scanf("%s", expr)' scans only first word if space in sentence. Use 'fgets(<string_var>, <max_chars>, stdin)'.

    for (int i = 0; i < strlen(expr); i++) {
        // If opening brackets are encountered, push into stack
        if (expr[i] == '{' || expr[i] == '(' || expr[i] == '[') {
            push(expr[i]);
        }
        // If closing brackets encountered are of same kind as top element, pop top element from stack
        else if (expr[i] == '}' || expr[i] == ')' || expr[i] == ']') {
            // If closing bracket without any opening bracket
            if (stkSize == 0) {
                printf("The sentence is not properly parenthesised. \n");
                exit(0);
            }
            else if (expr[i] == '}') {
                if (top() == '{') {
                    pop();
                }
                else {
                    printf("The sentence is not properly parenthesised. \n");
                    exit(0);
                }
            }
            else if (expr[i] == ')') {
                if (top() == '(') {
                    pop();
                }
                else {
                    printf("The sentence is not properly parenthesised. \n");
                    exit(0);
                }
            }
            else if (expr[i] == ']') {
                if (top() == '[') {
                    pop();
                }
                else {
                    printf("The sentence is not properly parenthesised. \n");
                    exit(0);
                }
            }
        }
        else {
            continue;
        }
    }
    
    if (stkSize != 0) {
        printf("The sentence is not properly parenthesised. \n");
        exit(0);
    }

    printf("The sentence is properly parenthesised. \n");
    return 0;
}
