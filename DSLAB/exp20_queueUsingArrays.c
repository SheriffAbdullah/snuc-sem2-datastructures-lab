/*
Write a program to implement the Queue ADT using arrays. You must implement
enqueue(), dequeue(), peek(), isEmpty() and isFull() operations. Implement
queue in a circular fashion in the array.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

// Initialising queue
int queue[MAX_SIZE] = {};
int front = -1;
int rear = -1;

int isEmpty(void) {
    return front == -1;
}

int isFull(void) {
    if (front == 0 && rear == MAX_SIZE - 1) {
        return 1;
    }
    else if (rear == front - 1) {
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
    else {
        // Empty queue
        if (isEmpty()) {
            front++;
            rear++;
            queue[rear] = elt;
        }
        else if (rear == MAX_SIZE - 1) {
            rear = 0;
            queue[rear] = elt;
        }
        else {
            rear++;
            queue[rear] = elt;
        }
        
        return elt;
    }
}

int dequeue(void) {
    if (isEmpty()) {
        return '\0';
    }
    else {
        int retVal = queue[front];
        
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == MAX_SIZE - 1) {
            front = 0;
        }
        else {
            front++;
        }
            
        return retVal;
    }
}

void peek(void) {
    isEmpty() ? printf("Queue is empty. Nothing to peek at. \n") : printf("%d <- Front. \n", queue[front]);
}

void display(void) {
    if (isEmpty()) {
        printf("[] \n");
    }
    else {
        printf("[");
        
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d, ", queue[i]);
        }
                   
        printf("%d] \n", queue[rear]);
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

/*
Ternary Operators:
<condition> ? <execute_if_condition_is_true> : <execute_if_condition_is_false>;
*/

