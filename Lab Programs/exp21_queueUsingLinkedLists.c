/*
 Write a program to implement the Queue ADT using linked list. You must implement enqueue(), dequeue(), peek(), isEmpty() and isFull() operations.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

struct node {
    int data;
    struct node *next;
} *front, *rear;


int isEmpty(void) {
    return front == NULL;
}

int isFull(void) {
    struct node *temp = front;
    int nodeCount = 0;
    
    // Count number of nodes between front and rear
    while (temp != rear) {
        temp = temp->next;
        nodeCount++;
    }
    
    if (nodeCount == MAX_SIZE - 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int enqueue(int elt) {
    /*
     Returns '\0' (NULL) if queue is full. Returns argument 'elt' otherwise.
    */
    // Full queue
    if (isFull()) {
        return '\0';
    }
    else if (isEmpty()) {
        rear = (struct node *) malloc(sizeof(struct node));
        rear->data = elt;
        rear->next = NULL;
        front = rear;
        return elt;
    }
    else {
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        temp->data = elt;
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
        return elt;
    }
}

int dequeue(void) {
    if (isEmpty()) {
        return '\0';
    }
    else if (front->next == NULL) {
        int retVal = front->data;
        front = NULL;
        
        return retVal;
    }
    else {
        int retVal = front->data;
        front = front->next;
        
        return retVal;
    }
}

void peek(void) {
    isEmpty() ? printf("Queue is empty. Nothing to peek at. \n") : printf("\'%d\' <- Front. \n", front->data);
}

void display(void) {
    if (isEmpty()) {
        printf("[] \n");
    }
    else {
        struct node *temp = front;
        
        printf("[");
        while (temp != rear) {
            printf("%d, ", temp->data);
            temp = temp->next;
        }
        printf("%d] \n", temp->data);
    }
}

int main() {
    // Print options menu
    printf("*** IMPLEMENTATION OF CIRCULAR QUEUE ADT USING ARRAYS *** \n");
    printf("** Options Menu ** \n");
    printf("1. Enqueue - Insert element at rear. \n");
    printf("2. Dequeue - Delete element at front. \n");
    printf("3. Peek    - View front element. \n");
    printf("4. Display - Display entire queue. \n");
    printf("0. Exit    - End program. \n");
    
    int opt, elt;
    
    while(1) {
        // Input
        printf("\nEnter option: ");
        scanf("%d", &opt);
        
        switch (opt) {
            case 0:
                printf("Program ended. \n");
                exit(0);
            case 1:
                printf("Enter element: ");
                scanf("%d", &elt);
                enqueue(elt) == '\0' ? printf("Queue is full. \n") : printf("\'%d\' enqueued. \n", elt);
                break;
            case 2:
                elt = dequeue();
                elt == '\0' ? printf("Queue is empty. Nothing to dequeue. \n") : printf("'\%d\' dequeued. \n", elt);
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid option. Enter a valid option (e.g. 4). \n");
        }
    }
    return 0;
}

