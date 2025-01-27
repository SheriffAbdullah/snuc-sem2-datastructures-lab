/*
A deque is a data structure consisting of a list of items, on which the following operations are possible:

push(x): Inserts item 'x' in the front end of the deque.
pop(): Removes the front item from the deque and returns it.
inject(x): Inserts item 'x' in the rear end of the deque.
eject(): Removes the rear item from thr queue and returns it.

Write routines to support the deque that take O(1) time per operation.

Note: The deque must be circular.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5    // Maximum size of deque

// Initialise empty Deque
int dq[MAX_SIZE] = {0};
int front = -1;
int rear = -1;

int isEmpty() {
	return (front == -1);
}

int isFull() {
	if ((rear == MAX_SIZE - 1 && front == 0) || (front - 1 == rear)) {
		printf("Deque is full. \n");
		return 1;
	}
	else {
		return 0;
	}
}

void push(int elt) {
	// Deque is full
	if (isFull()) {
		return;
	}
	// Deque is not full
	else {
		// No elements
		if (isEmpty()) {
			front++;
			rear++;
			dq[front] = elt;
		}
		// Only 1 element
		else if (front == 0) {
			front = MAX_SIZE - 1;
			dq[front] = elt;
		}
		// Normal case
		else {
			front--;
			dq[front] = elt;
		}
		
		printf("\'%d\' was pushed. \n", elt);
	}	
}

int pop() {
	// Deque is empty
	if (isEmpty()) {
		printf("Deque is empty. Nothing to pop. \n");
		return '\0';
	}
	// Deque has elements
	else {
		int retElt = dq[front];
		printf("\'%d\' was popped. \n", retElt);

		// Only 1 element
		if (front == rear) {
			front = -1;
			rear = -1;
			return retElt;		
		}
		// 'front' at 'MAX_SIZE - 1' -> Jump to '0'
		else if (front == MAX_SIZE - 1) {
			front = 0;
			return retElt;
		}
		// Normal case
		else {
			front++;
			return retElt;
		}
	}
}

void inject(int elt) {
	// Deque is full
	if (isFull()) {
		return;
	}
	// Deque is not full
	else {	
		// No elements
		if (rear == -1) {
			front++;
			rear++;
			dq[rear] = elt;
		}
		// 'rear' at 'MAX_SIZE - 1' -> Jump to '0' 
		else if (rear == MAX_SIZE - 1) {
			rear = 0;
			dq[rear] = elt;
		}
		// Normal case
		else {
			rear++;
			dq[rear] = elt;
		}
		
		printf("\'%d\' was injected. \n", elt);
	}
}

int eject() {
	// Deque is empty
	if (isEmpty()) {
		printf("Deque is empty. Nothing to eject. \n");
		return '\0';
	}
	// Deque has elements
	else {
		int retElt = dq[rear];
		printf("\'%d\' was ejected. \n", retElt);

		// Only 1 element
		if (rear == front) {
			front = -1;
			rear = -1;
			return retElt;
		}
		// 'rear' at '0' -> Jump to 'MAX_SIZE - 1'
		else if (rear == 0) {
			rear = MAX_SIZE - 1;
			return retElt;
		}
		// Normal case
		else {
			rear--;
			return retElt;
		}
	}
}

void display() {
	// Deque is empty
	if (isEmpty()) {
		printf("Deque is empty. Nothing to display. \n");
		return;
	}
	// Deque has elements
	else {
		int i;
		printf("[");
			
		for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
			printf("%d, ", dq[i]);
		}
		printf("%d] \n", dq[rear]);
		}	
}

int main() {
	// Print menu
	printf("*** CIRCULAR DEQUE IMPLEMENTATION *** \n");
	printf("*** Options Menu *** \n");
	printf("1. Push    - Insert at front of deque. \n");
	printf("2. Pop     - Remove front element of deque. \n");
	printf("3. Inject  - Insert at rear of deque. \n");
	printf("4. Eject   - Remove rear element of deque. \n");
	printf("5. Display - Display elements of deque. \n");
    printf("0. Exit    - End program. \n");
	
	int opt, elt;
	
	while(1) {
		// Input
		printf("\nEnter option: ");
		scanf("%d", &opt);
		
		switch(opt) {
			case 0:
				// Exit 
				printf("Program ended. \n");
				exit(0);
			case 1:
				// Push
				printf("Enter element: ");
				scanf("%d", &elt);
				
				push(elt);
				break;
			case 2:
				// Pop
				pop();
				break;
			case 3:
				// Inject
				printf("Enter element: ");
				scanf("%d", &elt);
				
				inject(elt);
				break;
			case 4:
				// Eject
				eject();
				break;
			case 5:
				// Display
				display();
				break;
			default:
				printf("Invalid option. \n");
		}		
	}
	
	return 0;
}

/*
Note:
(1)
	if (frontIsEmpty() == 1)
		
	*is same as*
	
	if (frontIsEmpty())
	
	-> 'frontIsEmpty()' will return '1'/'0'. 'if(1)' will 
	execute statements under it & 'if(0)' will not.

(2)
	1 = true
	0 = false
	
(3)
	if (front == 1) {
		return 1;
	} else {
		return 0;
	}
	
	*is same as*
		
	return (front == 1);
		
	-> 'front == 1' will return '1'/'0' directly.
*/
