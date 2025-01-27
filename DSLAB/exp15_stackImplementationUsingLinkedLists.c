/*
Program to implement the stack ADT using linked lists. push(), pop(), top() and isEmpty() operations must be implemented.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Linked List - Node
struct node {
    int data;
    struct node *next;
} *head;

bool isEmpty() {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void push() {
    int elt;
    printf("Enter element to push: ");
    scanf("%d", &elt);

    printf("\'%d\' pushed into stack. \n", elt);

    if (isEmpty()) {
        head = (struct node *) malloc(sizeof(struct node));
        head->data = elt;
        head->next = NULL;
    }
    else {
        // Add a new node before head & make it head node.
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        temp->data = elt;
        temp->next = head;
        head = temp;
    }
}

void pop() {
    if (isEmpty()) {
        printf("Stack underflow. \n");
    }
    else {
        printf("\'%d\' popped out of stack. \n", head->data);
        head = head->next;
    }
}

void top() {
    if (isEmpty()) {
        printf("Stack is empty. \n");
    }
    else {
        printf("\'%d\' <- Stack top. \n", head->data);
    }
}

int main() {
    printf("*** Implementation of Stack Using Linked Lists *** \n");
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

/*
Note: Typical linked list format is not used.
 
For stack implementation using linked lists:
push() -> Add a new node before 'head' and make it 'head'.
pop() -> Move to next node in list and make it 'head'.
top() -> Read data in 'head' node.
*/
