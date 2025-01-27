/*
A Priority Queue is a Queue in which each element in the queue has an associated priority.
Each element to be enqueued is inserted into the queue in its correct position according
to its priority. Elements with same priority are enqueued in first-come-first-serve order.

Implement a priority queue using a linked list by including priority as a part of the node structure.
The enqueue(), dequeue() and display() operations must be implemented.
*/

#include <stdio.h>
#include <stdlib.h>

// Linked list - Priority queue
struct node {
    int data;
    int prty;    // Priority of element
    struct node *next;
};

int isEmpty(struct node **ptrFront) {
    return (*ptrFront == NULL);
}

void enqueue(int elt, int prty, struct node **ptrFront, struct node **ptrRear) {
    // No elements in queue
    if(isEmpty(ptrFront)) {
        *ptrFront = (struct node *) malloc(sizeof(struct node));
        (*ptrFront)->data = elt;
        (*ptrFront)->prty = prty;
        (*ptrFront)->next = NULL;
        *ptrRear = *ptrFront;
    }
    // Highest priority element = First in queue
    else if(prty > (*ptrFront)->prty) {
        (*ptrFront)->next = (struct node *) malloc(sizeof(struct node));
        (*ptrFront) = (*ptrFront)->next;
        (*ptrFront)->data = elt;
        (*ptrFront)->prty = prty;
        (*ptrFront)->next = NULL;
    }
    // Least priority element = Last in queue
    else if(prty <= (*ptrRear)->prty) {
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        temp->data = elt;
        temp->prty = prty;
        temp->next = (*ptrRear);
        (*ptrRear) = temp;
    }
    // Insert in-between elements
    else {
        struct node *temp1, *temp2;
        temp1 = (*ptrRear);
        temp2 = (*ptrRear);
        
        while(prty > temp1->prty && temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        
        temp2->next = (struct node *) malloc(sizeof(struct node));
        temp2 = temp2->next;
        temp2->data = elt;
        temp2->prty = prty;
        temp2->next = temp1;
    }
}

int dequeue(struct node **ptrFront, struct node **ptrRear) {
    // No elements in queue
    if(isEmpty((ptrFront))) {
        printf("Queue is empty. Nothing to dequeue. \n");
        return '\0';
    }
    // 1 element in queue
    else if(*ptrFront == *ptrRear) {
        
        int retVal = (*ptrFront)->data;
        free(*ptrFront);
        *ptrFront = NULL;
        *ptrRear = NULL;
        
        return retVal;
    }
    // Normal case - remove front element
    else {
        int retVal = (*ptrFront)->data;
        struct node *temp1, *temp2;
        temp1 = (*ptrRear);
        temp2 = (*ptrRear);
        
        while(temp1->next != NULL) {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        
        free(temp1);
        temp2->next = NULL;
        (*ptrFront) = temp2;
        
        return retVal;
    }
}

void display(struct node **ptrFront, struct node **ptrRear) {
    // No elements in queue
    if (isEmpty(ptrFront)) {
        printf("Queue is empty. Nothing to display. \n");
    }
    // Atleast 1 element in queue
    else {
        struct node *temp = *ptrRear;
        printf("[");
        while(temp->next != NULL) {
            printf("%d, ", temp->data);
            temp = temp->next;
        }
        
        printf("%d] \n", temp->data);
    }
}

int main() {
    // Declare 'front' & 'rear' pointers
    struct node *front;
    struct node *rear;
    
    // Declare & Initialise double pointers which point to addresses of 'front' & 'rear'
    struct node **ptrFront = &front;
    struct node **ptrRear = &rear;
    
    *ptrFront = NULL;    // Initialise front pointer to 'NULL'
    
    // Print title & menu
    printf("*** PRIORITY QUEUE IMPLEMENTATION ***\n");
    printf("*** Options Menu ***\n");
    printf("1. Enqueue. \n");
    printf("2. Dequeue. \n");
    printf("3. Display. \n");
    printf("0. Exit. \n");
    printf("\nNote: Enter only integral numbers (integers) for both elements and their priority. \n");
    
    int opt, elt, prty;
    
    while(1) {
        printf("\nEnter option: ");
        scanf("%d", &opt);
        
        switch(opt) {
            case 0:
                // Exit
                printf("Program ended. \n");
                exit(0);
            case 1:
                // Enqueue
                printf("Enter element: ");
                scanf("%d", &elt);
                printf("Enter priority: ");
                scanf("%d", &prty);
                
                enqueue(elt, prty, ptrFront, ptrRear);
                
                printf("\'%d\' enqueued. \n", elt);
                break;
            case 2:
                // Dequeue
                elt = dequeue(ptrFront, ptrRear);
                
                if (elt != '\0') {
                    printf("\'%d\' dequeued. \n", elt);
                }
                
                break;
            case 3:
                // Display
                display(ptrFront, ptrRear);
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
    struct node **ptrFront;
    ptrFront = &front;
 
    *is same as*
 
    struct node **ptrFront = &front;
 
 (2)
    Linked list as parameter will not work with 'front' & 'rear' pointers only.
    'ptrFront' & 'ptrRear' are required.
 
    (or)
 
    Declare 'front' & 'rear' globally & avoid linked list parameters in functions.
 

 (3)
    'front' & 'rear' of queue are passed as parameters using 'ptrFront' & 'ptrRear' (double pointers)
    instead of global declaration of pointers.
*/

