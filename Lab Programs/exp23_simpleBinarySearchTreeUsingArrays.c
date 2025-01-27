/*
 Write a program to implement the insert() and find() operations in the array implementation of a binary search tree. You may display the contents of the tree linearly in the order in which they are stored in the array.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000

// Array of structures
struct node {
    int data;
    int exists : 2;    // ': 2' -> Bit field (i.e.) Only '2' bit will be used.
} bst[MAX_SIZE];

// Index of last element
int last;

void insert(int elt, int ind) {
    // Node is empty
    if (bst[ind].exists == 0) {
        bst[ind].exists = 1;
        bst[ind].data = elt;
        last = ind;
    }
    // Node is not empty
    else {
        // Element smaller than node
        if (elt < bst[ind].data) {
            insert(elt, ind * 2);
        }
        // Element larger than node
        else {
            insert(elt, (ind * 2) + 1);
        }
    }
}

int find(int elt, int ind) {
    // Node is not empty
    if (bst[ind].exists == 1) {
        // Element smaller than node
        if (elt < bst[ind].data) {
            return find(elt, ind * 2);
        }
        // Element larger than node
        else if (elt > bst[ind].data){
            return find(elt, (ind * 2) + 1);
        }
        // Element equal to node
        else {
            return 1;
        }
    }
    // Node is empty
    else {
        return 0;
    }
}

void dispTree(void) {
    if (last == 0) {
        printf("[] \n");
    }
    else {
        // Print values
        printf("[");
        
        for (int i = 1; i < last; i++) {
            if (bst[i].exists == 1) {
                printf("%d, ", bst[i].data);
            }
        }
        
        printf("%d] \n", bst[last].data);
    }
}

int main() {
    printf("*** Binary Search Tree Implementation Using Arrays *** \n");
    printf("\n** Options Menu ** \n");
    printf("1. Insert. \n");
    printf("2. Find. \n");
    printf("3. Display BST Array. \n");
    printf("0. Exit. \n");
    
    int opt, elt;
    
    while (1) {
        // Input
        printf("\nEnter option: ");
        scanf("%d", &opt);
        
        switch (opt) {
            case 0:
                exit(0);
            case 1:
                // Insert element
                printf("Enter element: ");
                scanf("%d", &elt);
                
                // Check if element already exists in BST
                if (find(elt, 1) == 1) {
                    printf("Invalid element. It already exists in BST. \n");
                }
                else {
                    insert(elt, 1);
                    printf("\'%d\' inserted. \n", elt);
                }
                
                break;
            case 2:
                // Find element
                printf("Enter element: ");
                scanf("%d", &elt);
                
                if (find(elt, 1) == 0) {
                    printf("Element not found. \n");
                }
                else {
                    printf("\'%d\' found. \n", elt);
                }
                
                break;
            case 3:
                dispTree();
                break;
            default:
                printf("Invalid option. Please enter a valid option (e.g. 2). \n");
        }
    }
    
    return 0;
}

/*
 Note:
 BST Implementation Using Arrays:
 
 Root node index = 1
 Left child index = (Parent index * 2)
 Right child index = (Parent index * 2) + 1
 */

