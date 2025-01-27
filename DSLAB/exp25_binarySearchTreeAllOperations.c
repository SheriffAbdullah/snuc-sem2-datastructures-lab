/*
 1. To a BST (Binary Search Tree) implementation with insert(), find() and display() functions, add functions for deletion of nodes and 3 types of traversals (inorder, preorder and postorder).
 2. Write a function for level order traversal of a tree (Level order traversal is a traversal method in which nodes are visited level by level from left to right).
 (Hint: Keep enqueuing the child nodes of every node that is visited starting from root. Visit nodes in the order of the queue)
 3. Write a program to check if a binary tree is balanced. A binary tree is balanced if the modulus of height difference 'h' between the right subtree and left subtree is lesser than 2 (|h| < 2).
 4. Write a function to find the in-order predecessor of an element in the tree.
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
struct node *root;

// Queue - for level order traversal
struct node *queue[100];
int front = -1;
int rear = -1;

void enqueue(struct node *temp) {
    // Queue is empty
    if (front == -1) {
        front = 0;
        rear = 0;
        queue[rear] = temp;
    }
    else {
        rear++;
        queue[rear] = temp;
    }
}

struct node * dequeue(void) {
    if (front == -1) {
        return NULL;
    }
    else if (front == 0 && rear == 0) {
        front = -1;
        rear = -1;
        return queue[front+1];
    }
    else {
        front++;
        return queue[front-1];
    }
}

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
    // Node is empty
    if (temp == NULL) {
        return;
    }
    
    space += COUNT;
    
    // Print right sub-tree
    dispTree(temp->right, space);
    
    // Print current node's data
    printf("%*d \n", space, temp->data);
    
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

struct node * largest(struct node *temp) {
    // Node is rightmost node
    if (temp->right == NULL) {
        return temp;
    }
    // Traverse to the rightmost node
    else {
        return largest(temp->right);
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

int subTreeHt(struct node *temp) {
    if (temp == NULL) {
        return -1;
    }
    else {
        int lHt = subTreeHt(temp->left);
        int rHt = subTreeHt(temp->right);
        
        // Use greater height
        if (lHt > rHt) {
            return lHt + 1;
        }
        else {
            return rHt + 1;
        }
    }
}

// Level order traversal
void lvlOrdTrav(struct node *temp) {
    if (temp != NULL) {
        // Visit node
        printf("%d ", temp->data);
        
        // Enqueue left child
        if (temp->left != NULL) {
            enqueue(temp->left);
        }
        // Enqueue right child
        if (temp->right != NULL) {
            enqueue(temp->right);
        }
        
        // Visit nodes in the queue order
        lvlOrdTrav(dequeue());
    }
}

int isBalanced(struct node *temp) {
    // If tree is empty
    if (temp == NULL) {
        return 1;
    }
    
    // Balance factor = Height of left subtree - Height of right subtree
    int balFac = subTreeHt(temp->left) - subTreeHt(temp->right);
    
    // Current node is balanced & child nodes are balanced
    if (balFac <= 1 && balFac >= -1 && isBalanced(temp->left) && isBalanced(temp->right)) {
        return 1;
    }
    
    // Not balanced
    return 0;
}

// In-order predecessor
int inOrderPredec(int elt, struct node *temp) {
    // Element does not exist in tree
    if (find(elt, root) == 0) {
        return '\0';
    }
    
    // Element is the smallest element in tree (no in-order predecessor)
    if (smallest(root)->data == elt) {
        return '\0';
    }
    
    // Find element in tree
    if (elt < temp->data) {
        return inOrderPredec(elt, temp->left);
    }
    if (elt > temp->data) {
        return inOrderPredec(elt, temp->right);
    }
    
    // Element found
    
    // Node has left sub-tree
    if (temp->left != NULL) {
        return largest(temp->left)->data;
    }
    
    // Node does not have left sub-tree
    if (temp->left == NULL) {
        int pred = '\0';
        
        struct node *temp1 = root;
        
        while (temp->data != temp1->data) {
            if (elt > temp1->data) {
                pred = temp1->data;
                temp1 = temp1->right;
            }
            if (elt < temp1->data) {
                temp1 = temp1->left;
            }
        }
        
        return pred;
    }
}

int main() {
    // Print menu
    printf("*** Implementation of BST Using Linked Lists *** \n");
    printf("** Options Menu ** \n");
    printf("01. Insert. \n");
    printf("02. Delete. \n");
    printf("03. Find. \n");
    printf("04. Pre-order traversal. \n");
    printf("05. In-order traversal. \n");
    printf("06. Post-order traversal. \n");
    printf("07. Level-order traversal. \n");
    printf("08. Height of Tree. \n");
    printf("09. In-order predecessor.");
    printf("10. Display BST. \n");
    printf("11. Check if BST is balanced. \n");
    printf("0. Exit. \n");
    
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
                root = delete(elt, root);
                break;
            case 3:
                // Find elemebt
                printf("Enter element: ");
                scanf("%d", &elt);
                find(elt, root) == 1 ? printf("\'%d\' found. \n", elt) : printf("Element not found. \n");
                break;
            case 4:
                printf("Pre-order traversal: ");
                preOrdTrav(root);
                printf("\n");
                break;
            case 5:
                printf("In-order traversal: ");
                inOrdTrav(root);
                printf("\n");
                break;
            case 6:
                printf("Post-order traversal: ");
                postOrdTrav(root);
                printf("\n");
                break;
            case 7:
                printf("Level-order traversal: ");
                lvlOrdTrav(root);
                printf("\n");
                break;
            case 8:
                printf("Height of tree is %d. \n", subTreeHt(root));
                break;
            case 9:
                printf("Enter element: ");
                scanf("%d", &elt);
                
                // Element does not exist in tree
                if (find(elt, root) == 0) {
                    printf("Invalid input. Element does not exist in tree. \n");
                }
                else if (inOrderPredec(elt, root) == '\0') {
                    printf("In-order predecessor doesn't exist. \n");
                }
                else {
                    printf("In-order predecessor is %d. \n", inOrderPredec(elt, root));
                }
                break;
            case 10:
                dispTree(root, 0);
                break;
            case 11:
                isBalanced(root) == 1 ? printf("The tree is balanced. \n") : printf("The tree is not balanced. \n");
                break;
            default:
                printf("Invalid option. Please enter a valid option (e.g. 4). \n");
        }
    }
    
    return 0;
}

/*
 Alternate Level Order Traversal function:
 
 void currLevelTraversal(int lvl, struct node *temp) {
     // Level greater than sub-tree height -> Invalid
     if (lvl > subTreeHt(temp)) {
         return;
     }
     // Tree is empty
     if (root == NULL) {
         return;
     }
     // Level reached (or) Root Node = Level 0
     if (lvl == 0) {
         printf("%d ", temp->data);
     }
     if (lvl > 0) {
         currLevelTraversal(lvl - 1, temp->left);
         currLevelTraversal(lvl - 1, temp->right);
     }
 }
 
 // Level order traversal
 void lvlOrdTrav(struct node *temp) {
     for (int i = 0; i <= subTreeHt(temp); i++) {
         printf("Level %d: ", i);
         currLevelTraversal(i, temp);
         printf("\n");
     }
 }
 */




