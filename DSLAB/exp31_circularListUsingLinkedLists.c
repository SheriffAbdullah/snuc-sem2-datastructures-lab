/*
 A circular linked list is a linked list in which the last node points to the first node. Implement the insertion and deletion operations in a circular linked list.
*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head;

// Return list length
int listLen(void) {
    if (head == NULL) {
        return 0;
    }
    else {
        struct node *temp = head;
        int size = 1;
        
        while (temp->next != head) {
            temp = temp->next;
            size++;
        }
        
        return size;
    }
}

// Insert element in index - '0'
void startInsert(int elt) {
    if (head == NULL) {
        head = (struct node *) malloc(sizeof(struct node *));
        head->next = head;
        head->data = elt;
    }
    else {
        struct node *temp = head;
        
        // Go to element before head
        while (temp->next != head) {
            temp = temp->next;
        }
        
        // Insert element between last element and head
        temp->next = (struct node *) malloc(sizeof(struct node));
        temp = temp->next;
        
        temp->next = head;
        temp->data = elt;
        
        head = temp;
    }
    
    printf("\'%d\' inserted at index \'0\'. \n", elt);
}

// Insert element in index - '<list_length> - 1'
void endInsert(int elt) {
    if (head == NULL) {
        startInsert(elt);
    }
    else {
        struct node *temp = head;
        
        // Go to element before head
        while (temp->next != head) {
            temp = temp->next;
        }
        
        // Insert element between last element and head
        temp->next = (struct node *) malloc(sizeof(struct node));
        temp = temp->next;
        
        temp->next = head;
        temp->data = elt;
        
        printf("\'%d\' inserted at index \'%d\'. \n", elt, listLen() - 1);
    }
}

// Insert element in index - '1' to '<list_length> - 2'
void indexInsert(int elt, int ind) {
    if (ind == 0) {
        startInsert(elt);
    }
    else if (ind > listLen() - 1) {
        printf("Invalid index. Index out of bounds. \n");
    }
    else {
        int i = 0;
        struct node *temp = head;
        
        while (i < ind - 1) {
            temp = temp->next;
            i++;
        }
        
        struct node *temp1 = (struct node *) malloc(sizeof(struct node));
        temp1->next = temp->next;
        temp1->data = elt;
        
        temp->next = temp1;
        
        printf("\'%d\' inserted at index \'%d\'. \n", elt, ind);
    }
}

// Delete element from index - '0'
void startDelete(void) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete. \n");
    }
    else if (head->next == head) {
        printf("\'%d\' deleted from index \'0\'. \n", head->data);
        head = NULL;
    }
    else {
        printf("\'%d\' deleted from index \'0\'. \n", head->data);
        
        struct node *temp = head;
        
        // Go to element before head
        while (temp->next != head) {
            temp = temp->next;
        }
        
        // Delete element between last element and head
        temp->next = head->next;
        head = temp->next;
    }
}

// Delete element in index - '<list_length> - 1'
void endDelete(void) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete. \n");
    }
    else if (head->next == head) {
        printf("\'%d\' deleted from index \'%d\'. \n", head->data, listLen() - 1);
        head = NULL;
    }
    else {
        struct node *temp1 = head, *temp2 = head->next;
            
        while (temp2->next != head) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        printf("\'%d\' deleted from index \'%d\'. \n", temp2->data, listLen() - 1);
        temp1->next = temp2->next;
    }
}

// Delete element in index - '1' to '<list_length> - 2'
void indexDelete(int ind) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete. \n");
    }
    else if (ind > listLen() - 1 || ind < 0) {
        printf("Invalid index. Index out of bounds. \n");
    }
    else {
        if (ind == 0) {
            startDelete();
        }
        else if (ind == listLen() - 1) {
            endDelete();
        }
        else {
            int i = 0;
            struct node *temp = head;
            
            while (i < ind - 1) {
                temp = temp->next;
                i++;
            }
            
            printf("\'%d\' deleted from index \'%d\'. \n", temp->next->data, ind);
            temp->next = temp->next->next;
        }
    }
}

void eltDelete(int elt) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete. \n");
    }
    else {
        int ind = 0;
        struct node *temp = head;
        
        // Find element in list
        while (temp->data != elt && temp->next != head) {
            ind++;
            temp = temp->next;
        }
        
        // Element found
        if (temp->data == elt) {
            // Element is at start
            if (temp == head) {
                startDelete();
            }
            // Element is at end
            else if (temp->next == head) {
                endDelete();
            }
            else {
                // Element is in middle
                indexDelete(ind);
            }
        }
        
        // Element not found
        else {
            printf("\'%d\' not found. \n", elt);
        }
    }
}

void search(int elt) {
    if (head == NULL) {
        printf("List is empty. Nothing to search. \n");
    }
    else {
        struct node *temp = head;
        int flag = 0;
        int ind = 0;
        
        while (temp->data != elt) {
            ind++;
            if (temp->next == head) {
                flag = 1;
                break;
            }
            temp = temp->next;
        }
        
        if (flag == 1) {
            printf("\'%d\' not found in list. \n", elt);
        }
        else {
            printf("\'%d\' found at index - \'%d\'. \n", elt, ind);
        }
    }
}

void display(void) {
    if (listLen() == 0) {
        printf("[] \n");
    }
    else if (listLen() == 1) {
        printf("[%d] \n", head->data);
    }
    else {
        struct node *temp = head;
        
        printf("[");
        while (temp->next->next != head) {
            printf("%d, ", temp->data);
            temp = temp->next;
        }
        printf("%d, %d] \n", temp->data, temp->next->data);
    }
}

int main() {
    int option = 1;
    int elt, ind;
    int pos;
    
    // Print menu
    printf("*** LIST IMPLEMENTATION *** \n");
    
    printf("\n** OPERATIONS MENU ** \n");
    printf("1. Insert Element. \n");    // Insert element at specified index
    printf("2. Delete Element. \n");    // Delete element at given index
    printf("3. Search Element. \n");    // Search for first occurrence of element
    printf("4. Display List. \n");    // Display entire list
    printf("0. Exit. \n");
    
    while (option != 0) {
        
        printf("\nEnter an option: ");
        scanf("%d", &option);
        
        switch (option) {
            case 0:
                printf("Program ended. \n");
                break;
                
            case 1:
                printf("\n* INSERT POSITION * \n");
                printf("1. Start. \n");
                printf("2. Specified index. \n");
                printf("3. End. \n");
                
                printf("\nEnter position to insert: ");
                scanf("%d", &pos);
                
                if (pos == 1) {
                    printf("Enter element to insert: ");
                    scanf("%d", &elt);
                    startInsert(elt);
                }
                else if (pos == 2) {
                    printf("Enter index number: ");
                    scanf("%d", &ind);
                    printf("Enter element to insert: ");
                    scanf("%d", &elt);
                    
                    if (ind == 0) {
                        startInsert(elt);
                    } else if (ind == listLen()) {
                        endInsert(elt);
                    }
                    else {
                        indexInsert(elt, ind);
                    }
                }
                else if (pos == 3) {
                    printf("Enter element to insert: ");
                    scanf("%d", &elt);
                    endInsert(elt);
                }
                else {
                    printf("Invalid option. \n");
                }
                
                break;
                
            case 2:
                printf("\n* DELETE POSITION * \n");
                printf("1. Start. \n");
                printf("2. Specified index. \n");
                printf("3. Specified element. \n");
                printf("4. End. \n");
                
                printf("\nEnter position to delete: ");
                scanf("%d", &pos);
                
                if (pos == 1) {
                    startDelete();
                }
                else if (pos == 2) {
                    printf("Enter index number: ");
                    scanf("%d", &ind);
                    indexDelete(ind);
                }
                else if (pos == 3) {
                    printf("Enter element to delete: ");
                    scanf("%d", &elt);
                    eltDelete(elt);
                }
                else if (pos == 4) {
                    endDelete();
                }
                else {
                    printf("Invalid option. \n");
                }
                
                break;
                
            case 3:
                printf("\nEnter element to search: ");
                scanf("%d", &elt);
                search(elt);
                break;
                
            case 4:
                display();
                break;
                
            default:
                printf("Invalid option. Please choose a valid option from the menu. \n");
        }
    }
    
    return 0;
}

