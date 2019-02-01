#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "union_find.h"

/* 
 * APIs marked verion 1 have a worst case performance of O(n)
 */
int find_parent1(int *parent, int i)
{
    if (parent[i] == -1) {
        return i;
    }
    return (find_parent1(parent, parent[i]));
}

void Union1 (int parent[], int x, int y)
{
    int xpar = find_parent1(parent, x);
    int ypar = find_parent1(parent, y);
    if (xpar != ypar) {
        parent[xpar] = ypar;
    }
}

int is_cycle1(Graph *graph)
{
    int *parent = (int *) malloc(sizeof(int)*(graph->V));
    memset(parent, -1, sizeof(int)*(graph->V));

    for (int i = 0; i < graph->E; i++) {
        int x = find_parent1(parent, graph->edge[i].v1);
        int y = find_parent1(parent, graph->edge[i].v2);
        if (x == y) {
            return (1);
        }
        Union1(parent, x, y);
    }
    return (0);
}

/*
 * APIs maked 2 have a worst case performance of O(lgn)
 */

void print_subset (Subset *subset, int V)
{
    for (int i = 0; i < V; i++) {
        printf("%d ", subset[i].parent);
    }
    printf("\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", subset[i].rank);
    }
}

int find_parent2 (Subset subset[], int i)
{
     return subset[i].parent;
}  

void Union2 (Subset subset[], int x, int y)
{
    int xpar = find_parent2(subset, x);
    int ypar = find_parent2(subset, y);   
    if (subset[xpar].rank > subset[ypar].rank) {
        subset[ypar].parent = xpar;
        subset[xpar].rank++;
    } else {
        subset[xpar].parent = ypar;
        subset[ypar].rank++;
    }
}

int is_cycle2 (Graph *graph)
{
    Subset *subset = (Subset *) malloc(sizeof(Subset)*graph->V);
    for (int i = 0; i < graph->V; i++) {
        subset[i].parent = i;
        subset[i].rank = 0;
    }
    print_subset(subset, graph->V);
    printf("\n");
    for (int i = 0; i < graph->E; i++) {
        int xpar = find_parent2(subset, graph->edge[i].v1);
        int ypar = find_parent2(subset, graph->edge[i].v2);
        if (xpar == ypar) {
            //print_subset(subset, graph->V);
            printf("%d and %d have same parent\n", graph->edge[i].v1, graph->edge[i].v2);
            return 1;
        }
        Union2(subset, graph->edge[i].v1, graph->edge[i].v2);
        print_subset(subset, graph->V);
        printf("\n");
    }
    //printf("\n");
    print_subset(subset, graph->V);
    return 0;
}

Graph *create_graph (int V, int E)
{
    Graph *graph = (Graph*) malloc(sizeof(Graph));
    if (!graph) {
        return NULL;
    }
    graph->V = V;
    graph->E = E;

    graph->edge = (Edge*) malloc(sizeof(Edge)*E);
    return (graph);
}
/* Following is the diagram. Find if there is a cycle
            0
           / \
          1_ _2
*/
int main (int argc, char *argv[]) 
{
    Graph *graph = create_graph(6,6);
    graph->edge[0].v1 = 0;
    graph->edge[0].v2 = 1;

    graph->edge[1].v1 = 1;
    graph->edge[1].v2 = 2;

    graph->edge[2].v1 = 1;
    graph->edge[2].v2 = 4;

    graph->edge[3].v1 = 1;
    graph->edge[3].v2 = 3;

    graph->edge[4].v1 = 2;
    graph->edge[4].v2 = 5;

    graph->edge[5].v1 = 4;
    graph->edge[5].v2 = 5;

    //printf("The graph %s\n", is_cycle1(graph)? "is cyclic":"is not cyclic");
    printf("The graph %s\n", is_cycle2(graph)? "is cyclic":"is not cyclic");
}
