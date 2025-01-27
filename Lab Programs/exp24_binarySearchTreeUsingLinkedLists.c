/*
 To a BST (Binary Search Tree) implementation with insert(), find() and display() functions, add functions for deletion of nodes and 3 types of traversals (inorder, preorder and postorder).
 */

#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

// Binary Search Tree [BST] Node
struct node {
    int data;
    struct node *left, *right;
};

// Declare BST root node
struct node *root, *xNode;

struct node * insert(int elt, struct node *temp) {
    // Node is empty
    if (temp == NULL) {
        temp = (struct node *) malloc(sizeof(struct node));
        temp->data = elt;
        temp->left = NULL;
        temp->right = NULL;
        
        // Root node is empty
        if (root == NULL) {
            root = temp;
        }
        
        // Send 'temp' node as previous node's left (or) right
        return temp;
    }
    // Element smaller than node's element (node's element = temp->data)
    else if (elt < temp->data) {
        temp->left = insert(elt, temp->left);
    }
    // Element larger than node's element
    else {
        // Condition: (elt > temp->data)
        temp->right = insert(elt, temp->right);
    }
    
    // Return argument node
    return temp;
}

int find(int elt, struct node *temp) {
    // Empty node
    if (temp == NULL) {
        return 0;
    }
    // Argument element smaller than node's element
    else if (elt < temp->data) {
        return find(elt, temp->left);
    }
    // Argument element larger than node's element
    else if (elt > temp->data) {
        return find(elt, temp->right);
    }
    // Argument element = node's element (Element found)
    else {
        return 1;
    }
}

void dispTree(struct node *temp, int space) {
    // Leaf node's left / right
    if (temp == NULL) {
        return;
    }
    
    space += COUNT;
    
    // Print right sub-tree
    dispTree(temp->right, space);
    
    // Print current node's data
    printf("%*d \n",space, temp->data);
    
    // Print left sub-tree
    dispTree(temp->left, space);
}

struct node * smallest(struct node *temp) {
    // Node is leftmost node
    if (temp->left == NULL) {
        
        return temp;
    }
    // Traverse to the leftmost node
    else {
        return smallest(temp->left);
    }
}

struct node * delete(int elt, struct node *temp) {
    // Node is empty
    if (temp == NULL) {
        return NULL;
    }
    // Arg element smaller than node's element
    else if (elt < temp->data) {
        temp->left = delete(elt, temp->left);
    }
    // Arg element larger than node's element
    else if (elt > temp->data) {
        temp->right = delete(elt, temp->right);
    }
    // Arg element = Node's element
    else {
        // Node has no children (leaf node)
        if (temp->left == NULL && temp->right == NULL) {
            return NULL;
        }
        // Node has only left child
        else if (temp->left != NULL && temp->right == NULL) {
            return temp->left;
        }
        // Node has only right child
        else if (temp->left == NULL && temp->right != NULL) {
            return temp->right;
        }
        // Node has 2 children
        else {
            // Select smallest element from right child
            int min = smallest(temp->right)->data;
            // Delete the smallest element
            delete(min, root);
            // Replace node with smallest element
            temp->data = min;
        }
    }
    
    // Return argument node to restore existing connections
    return temp;
}

// Pre-order traversal -> root, (left, right)
void preOrdTrav(struct node *temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);
        preOrdTrav(temp->left);
        preOrdTrav(temp->right);
    }
}

// In-order traversal -> left, root, right
void inOrdTrav(struct node *temp) {
    if (temp == NULL) {
        return;
    }
    else {
        inOrdTrav(temp->left);
        printf("%d ", temp->data);
        inOrdTrav(temp->right);
    }
}

// Post-order traversal -> (Left, Right), Root
void postOrdTrav(struct node *temp) {
    if (temp != NULL) {
        preOrdTrav(temp->left);
        preOrdTrav(temp->right);
        printf("%d ", temp->data);
    }
}

int main() {
    // Print menu
    printf("*** Implementation of BST Using Linked Lists *** \n");
    printf("** Options Menu ** \n");
    printf("1. Insert. \n");
    printf("2. Delete. \n");
    printf("3. Find. \n");
    printf("4. Pre-order traversal. \n");
    printf("5. In-order traversal. \n");
    printf("6. Post-order traversal. \n");
    printf("7. Display BST. \n");
    
    int opt, elt;
    
    while (1) {
        // Input
        printf("\nEnter an option: ");
        scanf("%d", &opt);
        
        switch(opt) {
            case 0:
                exit(0);
            case 1:
                // Insert
                printf("Enter element: ");
                scanf("%d", &elt);
                if (find(elt, root) == 1) {
                    printf("Invalid input. Element exists in BST. \n");
                }
                else {
                    insert(elt, root);
                }
                break;
            case 2:
                // Delete
                printf("Enter element: ");
                scanf("%d", &elt);
                delete(elt, root);
                break;
            case 3:
                // Find elemebt
                printf("Enter element: ");
                scanf("%d", &elt);
                find(elt, root) == 1 ? printf("\'%d\' found. \n", elt) : printf("Element not found. \n");
                break;
            case 4:
                preOrdTrav(root);
                break;
            case 5:
                inOrdTrav(root);
                break;
            case 6:
                postOrdTrav(root);
                break;
            case 7:
                dispTree(root, 0);
                break;
            default:
                printf("Invalid option. Please enter a valid option (e.g. 4). \n");
        }
    }
    
    return 0;
}

