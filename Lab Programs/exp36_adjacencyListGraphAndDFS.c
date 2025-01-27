/*
 Adjacency list representation of graph and breadth-first search.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NEW_LINE printf("\n");

typedef struct Node {
    int vertex;
    // Pointer to next node
    struct Node *next;    // (same as) node *next;
} node;

typedef struct Graph {
    // Adjacency list - Array of pointers to node
    node **adjList;
    int *visited;
    int numOfVertices;
} graph;

graph *create_graph(int numOfVertices) {
    // Allocate space for graph
    graph *g = (graph *) malloc(sizeof(graph));
    
    // Allocate space for an array of linked lists (adjacency list)
    g->adjList = malloc(numOfVertices * sizeof(node *));
    // Allocate space for a 'visited' array
    g->visited = malloc(numOfVertices * sizeof(int));
    
    // Initialise values to 'NULL' & 'not visited' respectively
    for (int i = 0; i < numOfVertices; i++) {
        g->adjList[i] = NULL;
        g->visited[i] = 0;
    }
    
    g->numOfVertices = numOfVertices;
    
    return g;
}

// Check if all vertices in graph have been visited
int all_nodes_visited(graph *g) {
    for (int i = 0; i < g->numOfVertices; i++) {
        // If 'not visited' vertex found
        if (g->visited[i] == 0) {
            return 0;
        }
    }
    
    return 1;
}

// Set all vertices to 'not visited'
void unvisit_all_nodes(graph *g) {
    for (int i = 0; i < g->numOfVertices; i++) {
        g->visited[i] = 0;
    }
}

void print_adjacency_list(graph *g) {
    printf("[ \n");
    
    for (int i = 0; i < g->numOfVertices; i++) {
        node *temp = g->adjList[i];
        
        // Print vertex
        if (temp == NULL) {
            printf("|%d| -> / \n", i);
        }
        else {
            printf("|%d| -> ", i);
            // Print adjacent vertices
            while (temp->next != NULL) {
                printf("%d -> ", temp->vertex);
                temp = temp->next;
            }
            printf("%d -> \\ \n", temp->vertex);
        }
    }
    
    unvisit_all_nodes(g);
    printf("] \n");
}

void add_edge(graph *g, int src, int dst) {
    // If edge already exists
    if (g->adjList[src] != NULL) {
        node *temp = g->adjList[src];
        while (temp != NULL) {
            if (temp->vertex == dst) {
                printf("Edge already exists. \n");
                return;
            }
            temp = temp->next;
        }
    }
    // If source edge has no existing edges
    if (g->adjList[src] == NULL) {
        g->adjList[src] = (node *) malloc(sizeof(node));
        g->adjList[src]->vertex = dst;
        g->adjList[src]->next = NULL;
    }
    // If source edge has edges
    else {
        node *temp = g->adjList[src];
        
        // Move to last vertex in adjacency list
        while (temp->next != NULL) {
            temp = temp->next;
        }
        
        // Add vertex at end
        temp->next = (node *) malloc(sizeof(node));
        temp = temp->next;
        temp->vertex = dst;
        temp->next = NULL;
        
    }
}

void depth_first_search(graph *g, int start) {
    // If all vertices are visited, un-visit them and quit
    if (all_nodes_visited(g) == 1) {
        unvisit_all_nodes(g);
        return;
    }
    
    // Assign pointer to first adjacent vertex
    node *temp = g->adjList[start];
    
    // Mark as visited
    g->visited[start] = 1;
    printf("%d ", start);
    
    while (temp->next != NULL) {
        // If adjacent vertex is not visited
        if (g->visited[temp->vertex] == 0) {
            // DFS form that vertex
            depth_first_search(g, temp->vertex);
        }
        // Move to next vertex
        temp = temp->next;
    }
    
    // Last adjacent vertex
    if (g->visited[temp->vertex] == 0) {
        // DFS form that vertex
        depth_first_search(g, temp->vertex);
    }
}

int main() {
    printf("*** GRAPH IMPLEMENTATION USING ADJACENCY LIST *** \n");
    
    // Input
    int numOfVertices;
    printf("\nEnter number of vertices: ");
    scanf("%d", &numOfVertices);
    
    // Adjacency Matrix representation of Graphs
    graph *g = create_graph(numOfVertices);
    
    // Options menu
    printf("\n** Options Menu ** \n");
    printf("1. Add edge. \n");
    printf("2. Depth-first search. \n");
    printf("3. Display graph. \n");
    printf("0. Exit. \n");
    
    int opt;
    int src, dst;
    int start;
    
    while (1) {
        printf("\nEnter option: ");
        scanf("%d", &opt);
        
        switch (opt) {
                // Free allocated memory & end program
            case 0:
                free(g);
                printf("Program ended. \n");
                exit(0);
                // Add edge
            case 1:
                printf("Enter source: ");
                scanf("%d", &src);
                printf("Enter destination: ");
                scanf("%d", &dst);
                
                if (src >= g->numOfVertices || dst > g->numOfVertices || src < 0 || dst < 0) {
                    printf("Invalid vertex/vertices. \n");
                }
                else {
                    add_edge(g, src, dst);
                }
                
                break;
                // DFS
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                
                if (start >= g->numOfVertices || start < 0) {
                    printf("Invalid vertex. \n");
                }
                else {
                    printf("DFS: ");
                    depth_first_search(g, start);
                    unvisit_all_nodes(g);
                    NEW_LINE
                }
                break;
                // Print adjacency list
            case 3:
                print_adjacency_list(g);
                break;
                // Invalid input
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
 */

