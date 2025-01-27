/*
 Write a program to implement the insert() and find() operations in the linked list implementation of a binary search tree. You may use the attached printTree() for displaying the contents of the tree. Also write functions to find the largest and the smallest element in a binary search tree.
 */

#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

// Initialise Node
struct node {
    int data;
    struct node *left;
    struct node *right;
} *root;

void insert(int elt, struct node *temp) {
    // Empty root node
    if (root == NULL) {
        temp = (struct node *) malloc(sizeof(struct node));
        temp->data = elt;
        temp->right = NULL;
        temp->left = NULL;
        root = temp;
    }
    // Larger element & right node empty
    else if (elt > temp->data && temp->right == NULL) {
        temp->right = (struct node *) malloc(sizeof(struct node));
        temp = temp->right;
        temp->data = elt;
        temp->right = NULL;
        temp->left = NULL;
    }
    // Smaller element & left node empty
    else if (elt < temp->data && temp->left == NULL) {
        temp->left = (struct node *) malloc(sizeof(struct node));
        temp = temp->left;
        temp->data = elt;
        temp->right = NULL;
        temp->left = NULL;
    }
    // Larger element & right node not empty
    else if (elt > temp->data && temp->right != NULL) {
        insert(elt, temp->right);
    }
    // Smaller element & left node not empty
    else if (elt < temp->data && temp->left != NULL) {
        insert(elt, temp->left);
    }
}

int find(int elt, struct node *temp) {
    // Empty root node
    if (root == NULL) {
        return 0;
    }
    // Empty node
    else if (temp == NULL) {
        return 0;
    }
    // Element found
    else if (temp->data == elt) {
        return 1;
    }
    // Element not found & smaller than element in node
    else if (elt < temp->data) {
        return find(elt, temp->left);
    }
    // Element not found & larger than element in node
    else {
        return find(elt, temp->right);
    }
}

void largest(struct node *temp) {
    // Empty root node
    if (temp == NULL) {
        printf("Tree is empty. No largest element. \n");
    }
    // Right node empty
    else if (temp->right == NULL) {
        printf("Largest element is %d. \n", temp->data);
    }
    // Right node not empty
    else {
        largest(temp->right);
    }
}

void smallest(struct node *temp) {
    // Empty root node
    if (temp == NULL) {
        printf("Tree is empty. No smallest element. \n");
    }
    // Left node empty
    else if (temp->left == NULL) {
        printf("Smallest element is %d. \n", temp->data);
    }
    // Left node not empty
    else {
        smallest(temp->left);
    }
}

void dispTree(struct node *temp, int space) {
    if (temp == NULL) {
        return;
    }
    else {
        space += COUNT;
        
        // Print all right nodes
        dispTree(temp->right, space);
        
        // Print current node
        for (int i = 0; i < space; i++) {
            printf(" ");
        }
        
        printf("%d \n", temp->data);
        
        // Print all left nodes
        dispTree(temp->left, space);
    }
}

int main() {
    printf("*** Binary Search Tree Implementation Using Linked Lists *** \n");
    printf("\n** Options Menu ** \n");
    printf("1. Insert. \n");
    printf("2. Find. \n");
    printf("3. Largest. \n");
    printf("4. Smallest. \n");
    printf("5. Display BST. \n");
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
                if (find(elt, root) == 1) {
                    printf("Invalid element. It already exists in BST. \n");
                }
                else {
                    insert(elt, root);
                    printf("\'%d\' inserted. \n", elt);
                }
                break;
                
            case 2:
                // Find element
                printf("Enter element: ");
                scanf("%d", &elt);
                
                if (find(elt, root) == 1) {
                    printf("\'%d\' found in tree. \n", elt);
                }
                else {
                    printf("Element not found. \n");
                }
                break;
                
            case 3:
                largest(root);
                break;
                
            case 4:
                smallest(root);
                break;
                
            case 5:
                printf("<- This way up. \n");
                dispTree(root, 0);

                break;
	    default:
 		printf("Invalid option. Please enter a valid option (e.g. 2). \n");
        }
    }
    
    return 0;
}

/*
 Note:
 Binary Tree
 - Elements may be repeated any number of times.
 - Unordered elements.
 (v/s)
 Binary Search Tree [BST]
 - Element must occur only 1 time in BST.
 - Element larger than node's element in right child node.
 - Element smaller than node's element in left child node.
 */

