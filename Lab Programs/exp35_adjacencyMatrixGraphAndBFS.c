/*
Adjacency matrix representation of graph and breadth-first search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define QUEUE_MAX 10
#define NEW_LINE printf("\n");
#define PRINT_QUEUE printf("["); for (int i = 0; i < QUEUE_MAX; i++) printf("%d ", queue[i]); printf("]\n");

// Queue
int queue[QUEUE_MAX];
int front = -1;
int rear = -1;

void enqueue(int vertex) {
    if (rear == QUEUE_MAX - 1) {
        printf("Queue full. \n");
        return;
    }
    else if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear++;
    }
    
    queue[rear] = vertex;
}

int dequeue(void) {
    if (front == -1) {
        printf("Queue empty. \n");
        return '\0';
    }
    else if (front == rear) {
        int retVal = queue[front];
        front = -1;
        rear = -1;
        
        return retVal;
    }
    else {
        int retVal = queue[front];
        front++;
        
        return retVal;
    }
}

int isEmpty(void) {
    if (front == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

typedef struct Graph {
    int numOfVertices;
    // Double pointer acts as an array
    int **vertex;
    // To check if a node is visited or not
    int *visited;
} graph;

graph *create_graph(int numOfVertices) {
    // Allocate space for graph
    graph *g = (graph *) malloc(sizeof(graph));
    
    // Allocate space for an array of arrays ('vertex' array)
    g->vertex = calloc(numOfVertices, sizeof(int *));
    // 'calloc(<number_of_blocks>, <size_of_blocks>)' initialises all memory locations to '0'.
    
    // Assign a pointer to an array in every memory location in 'vertex' array
    for (int i = 0; i < numOfVertices; i++) {
        g->vertex[i] = (int *)calloc(numOfVertices, sizeof(int));
    }
    
    // Initialise array with '0's
    g->visited = calloc(numOfVertices, sizeof(int));
    
    g->numOfVertices = numOfVertices;
    
    return g;
}

void print_adjacency_matrix(graph *g) {
    printf("[ \n");
    printf(" \t");
    
    // Print column index
    for (int i = 0; i < g->numOfVertices; i++) {
        printf("%d \t", i);
    }
    
    NEW_LINE
    
    for (int i = 0; i < g->numOfVertices; i++) {
        // Print row index
        printf("%d |\t", i);

        for (int j = 0; j < g-> numOfVertices; j++) {
            // Print values
            printf("%d \t", g->vertex[i][j]);
        }
        printf("\n");
    }
    
    printf("] \n");
}

void add_edge(graph *g, int prev, int next) {
    g->vertex[prev][next] = 1;
}

void remove_edge(graph *g, int prev, int next) {
    g->vertex[prev][next] = 0;
}

// Check if all nodes in graph have been visited
int all_nodes_visited(graph *g) {
    for (int i = 0; i < g->numOfVertices; i++) {
        if (g->visited[i] == 0) {
            return 0;
        }
    }
    return 1;
}

// Set all nodes to 'not visited'
void unvisit_all_nodes(graph *g) {
    for (int i = 0; i < g->numOfVertices; i++) {
        g->visited[i] = 0;
    }
}

void breadth_first_search(graph *g, int start) {
    printf("BFS: ");
    
    // Mark vertex as visited
    g->visited[start] = 1;
    // Enqueue vertex
    enqueue(start);

    // Until all vertices are visited
    while (!all_nodes_visited(g)) {
        // Enqueue all unvisited ajacent vertices & mark them as 'visited'
        for (int i = 0; i < g->numOfVertices; i++) {
            if (g->vertex[start][i] == 1) {
                if (g->visited[i] == 0) {
                    g->visited[i] = 1;
                    enqueue(i);
                }
            }
        }
        // Repeat the same for front vertex in queue
        start = dequeue();
        printf("%d ", start);
    }
    
    unvisit_all_nodes(g);
    
    // Print remaining vertices in queue
    while (!isEmpty()) {
        int i = dequeue();
        printf("%d ", i);
    }
    
    printf("\n");
}

int main() {
    printf("*** GRAPH IMPLEMENTATION USING ADJACENCY MATRIX *** \n");
    
    // Input
    int numOfVertices;
    printf("\nEnter number of vertices: ");
    scanf("%d", &numOfVertices);
    
    // Adjacency Matrix representation of Graphs
    graph *g = create_graph(numOfVertices);
    
    // Options menu
    printf("\n** Options Menu ** \n");
    printf("1. Add edge. \n");
    printf("2. Remove edge. \n");
    printf("3. Breadth-first search. \n");
    printf("4. Display graph. \n");
    printf("0. Exit. \n");
    
    int opt;
    int src, dst;
    int start;
    
    while (1) {
        printf("\nEnter option: ");
        scanf("%d", &opt);
        
        switch (opt) {
            case 0:
                // Free allocated memory
                free(g);
                printf("Program ended. \n");
                exit(0);
            case 1:
                printf("Enter source: ");
                scanf("%d", &src);
                printf("Enter destination: ");
                scanf("%d", &dst);
                
                if (src > g->numOfVertices || dst > numOfVertices) {
                    printf("Invalid vertex/vertices. \n");
                }
                else {
                    add_edge(g, src, dst);
                }
                
                break;
            case 2:
                printf("Enter source: ");
                scanf("%d", &src);
                printf("Enter destination: ");
                scanf("%d", &dst);
                
                if (src > g->numOfVertices || dst > g->numOfVertices) {
                    printf("Invalid vertex/vertices. \n");
                }
                else {
                    remove_edge(g, src, dst);
                }
                
                break;
            case 3:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                
                if (start > g->numOfVertices) {
                    printf("Invalid vertex. \n");
                }
                else {
                    breadth_first_search(g, start);
                }
                
                break;
            case 4:
                print_adjacency_matrix(g);
                break;
            default:
                printf("Invalid input. Please enter a valid input. \n");
        }
    }
    
    return 0;
}

/*
Simple directed connected graph:
 add_edge(g, 1, 2);
 add_edge(g, 2, 1);
 add_edge(g, 1, 3);
 add_edge(g, 3, 0);
 add_edge(g, 0, 1);

Assumption:
    - To use BFS (breadth-first search), the graph must be connected (i.e.) there must be NO disconnected vertex.
 
TYPEDEF
    Syntax: typedef <data_type/data_structure> <new_name>;
    E.g. typedef long long int lint; ('lint', the last word, is the new name)
    So, instead of 'long long int multiple;' use 'lint multiple;'
*/

