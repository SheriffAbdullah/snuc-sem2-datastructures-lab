/*
Program to implement the stack ADT using arrays. push(), pop(), top(), isEmpty() and isFull() operations must be implemented.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Declare stack globally
int stk[MAX_SIZE];
int stkSize = 0;
// Note: It is a better practice to NOT use global variables.

bool isFull() {
	if (stkSize == MAX_SIZE) {
		return true;
	}
	else {
		return false;
	}
}

bool isEmpty() {
	if (stkSize == 0) {
		return true;
	}
	else {
		return false;
	}
}

void push() {
	if (isFull()) {
		printf("Stack overflow. \n");
	}
	else {
		int elt;
		printf("Enter element: ");
		scanf("%d", &elt);
		
		stkSize++;
		stk[stkSize - 1] = elt;
		printf("%d pushed into stack. \n", elt);
	}
}

void pop() {
	if (isEmpty()) {
		printf("Stack underflow. \n");
	}
	else {
		printf("%d popped out of stack. \n", stk[stkSize - 1]);
		stkSize--;
	}
}

void top() {
	if (isEmpty()) {
		printf("Stack is empty. \n");
	}
	else {
		printf("%d <- Top. \n", stk[stkSize-1]);
	}
}

int main() {
	printf("*** STACK IMPLEMENTATION USING ARRAYS *** \n");
	
	int option;
	printf("** Options Menu ** \n");
	printf("1. Push (Insert element). \n");
	printf("2. Pop (Delete element). \n");
	printf("3. Peek (Print top element). \n");
	printf("0. Exit. \n");
			
	while (true) {
		printf("\nEnter option: ");
		scanf("%d", &option);
		
		switch (option) {
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
				printf("Please enter a valid option (e.g. 1) from the menu. \n");		
		}
	}
		
	return 0;
}
