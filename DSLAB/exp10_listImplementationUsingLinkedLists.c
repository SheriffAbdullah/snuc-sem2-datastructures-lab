/*
Write a program to implement list operations using the concept of linked lists. The list operations to be implemented are
a. Insertion
b. Deletion
c. Search
d. Display list.
The program should be menu-driven which allows user to choose any operation at any point in time. The user may also choose to exit the program.
*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}

struct node *head;

// Return list length
int listLen() {
    if (head == NULL) {
        return 0;
    }
    else {
        struct node *temp = head;
        int size = 1;

        while (temp->next != NULL) {
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
        head->next = NULL;
        head->data = elt;
    }
    else {
        struct node *temp = (struct node *) malloc(sizeof(struct node));
        temp->data = elt;
        temp->next = head;
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

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = (struct node *) malloc(sizeof(struct node));
        temp->next->data = elt;
        temp->next->next = NULL;

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
void startDelete() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete. \n");
    }
    else {
        printf("\'%d\' deleted from index \'0\'. \n", head->data);
        head = head->next;
    }
}

// Delete element in index - '<list_length> - 1'
void endDelete() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete. \n");
    }
    else {
        if (head->next == NULL) {
            startDelete();
        }
        else {
            struct node *temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }

            printf("\'%d\' deleted from index \'%d\'. \n", temp->next->data, listLen() - 1);
            temp->next = NULL;
        }
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
        struct node *temp = head;

        if (temp->data == elt) {
            head = head->next;
            printf("\'%d\' deleted from index \'0\'. \n", elt);
        }
        else {
            int ind = 0;
            while (temp->next != NULL && temp->next->data != elt) {
                temp = temp->next;
                ind++;
            }

            if (temp->next != NULL) {
                temp->next = temp->next->next;
                printf("\'%d\' deleted from index \'%d\'. \n", elt, ind + 1);
            }
            else {
                printf("\'%d\' not found. \n", elt);
            }
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
            if (temp->next == NULL) {
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

void display() {
    if (listLen() == 0) {
        printf("[] \n");
    }
    else if (listLen() == 1) {
        printf("[%d] \n", head->data);
    }
    else {
        struct node *temp = head;

        printf("[");
        while (temp->next->next != NULL) {
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
