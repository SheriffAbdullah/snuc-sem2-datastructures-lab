/*
Write a program to implement list operations using arrays. The list operations to be implemented are
a. Insertion
b. Deletion
c. Search
d. Display list.
The program should be menu-driven which allows user to choose any operation at any point in time. The user may also choose to exit the program.
*/

#include <stdio.h>

int main() {
    int option = 1;

    // Print menu
    printf("*** LIST IMPLEMENTATION *** \n");
    printf("\n** OPERATIONS MENU ** \n");
    printf("1. Insert Element. \n");    // Insert element at specified index
    printf("2. Delete Element Using Index. \n");    // Delete element at given index
    printf("3. Delete Element. \n");    // Delete first occurrence element
    printf("4. Search Element. \n");    // Search for first occurrence of element
    printf("5. Display List. \n");    // Display entire list
    printf("0. Exit. \n");

    int lst[100] = {};    // Initialise all elements to zero
    int lst_size = 0;    // Set list size to '0'
    int elt, ind;
    int i, j, flag;


    while (option != 0) {

        printf("\nEnter an option: ");
        scanf("%d", &option);

        if (option == 0) {
            // Exit program
            printf("\nProgram ended. \n");
        }
        else if (option == 1) {
            // Insert element at index
            printf("Enter element to insert: ");
            scanf("%d", &elt);

            // Empty list - insert at first position
            if (lst_size == 0) {
                lst[0] = elt;
                printf("\'%d\' inserted at index - '0'. \n", elt);
            }
            else {
                printf("Enter index number: ");
                scanf("%d", &ind);

                if (ind > lst_size) {
                    printf("Invalid index value. Out of bounds. \n");
                    continue;
                }
                else {
                    // Shift elements to the right
                    for (i = lst_size - 1; i >= ind; i--) {
                        lst[i+1] = lst[i];
                    }

                    // Insert element
                    lst[ind] = elt;
                    printf("\'%d\' inserted at index - \'%d\'. \n", elt, ind);
                }
            }

            lst_size++;
        }
        else if (option == 2) {
            // Delete index element
            if (lst_size == 0) {
                printf("List is empty. Nothing to delete. \n");
                continue;
            }
            else {
                printf("Enter index of element to delete: ");
                scanf("%d", &ind);

                if (ind > lst_size - 1) {
                    printf("Invalid index value. Out of bounds. \n");
                    continue;
                }
                else {
                    // Shift elements to left
                    for (i = ind; i < lst_size - 1; i++) {
                        lst[i] = lst[i+1];
                    }
                    printf("Element deleted at index - \'%d\'. \n", ind);
                }
            }

            lst_size--;
        }
        else if (option == 3) {
            printf("Enter element to delete: ");
            scanf("%d", &elt);

            flag = 0;

            for (i = 0; i < lst_size; i++) {
                if (lst[i] == elt) {
                    // Shift elements to left
                    for (j = i; j < lst_size - 1; j++) {
                        lst[j] = lst[j+1];
                    }
                    printf("Element deleted at index - \'%d\'. \n", i);
                }
            }
            lst_size--;
        }
        else if (option == 4) {
            // Search for element
            printf("Enter element to search: ");
            scanf("%d", &elt);

            flag = 0;

            for (i = 0; i < lst_size; i++) {
                if (lst[i] == elt) {
                    printf("\'%d\' found at index - \'%d\'. \n", elt, i);
                    flag = 1;
                    break;
                }
            }

            if (flag == 0) {
                printf("Element not found. \n");
            }
        }
        else if (option == 5) {
            // Display elements of list
            if (lst_size == 0) {
                printf("[ ] \n");
            }
            else {
                printf("[");

                for (i = 0; i < lst_size - 1; i++) {
                    printf("%d, ", lst[i]);
                }

                printf("%d] \n", lst[lst_size-1]);
            }
        }
        else {
            printf("Please enter a valid option from the menu (e.g. 1). \n");
        }
    }

    return 0;
}

