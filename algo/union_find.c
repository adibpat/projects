#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "union_find.h"

int find_parent(int *parent, int i)
{
    if (parent[i] == -1) {
        return i;
    }
    return (find_parent(parent, parent[i]));
}

void Union (int parent[], int x, int y)
{
    int xpar = find_parent(parent, x);
    int ypar = find_parent(parent, y);
    if (xpar != ypar) {
        parent[xpar] = ypar;
    }
}

int is_cycle(Graph *graph)
{
    int *parent = (int *) malloc(sizeof(int)*(graph->V));
    memset(parent, -1, sizeof(int)*(graph->V));

    for (int i = 0; i < graph->E; i++) {
        int x = find_parent(parent, graph->edge[i].v1);
        int y = find_parent(parent, graph->edge[i].v2);
        if (x == y) {
            return (1);
        }
        Union(parent, x, y);
    }
    return (0);
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
    Graph *graph = create_graph(3,3);
    graph->edge[0].v1 = 0;
    graph->edge[0].v2 = 1;

    graph->edge[1].v1 = 0;
    graph->edge[1].v2 = 2;

    graph->edge[2].v1 = 1;
    graph->edge[2].v2 = 2;

    printf("The graph %s\n", is_cycle(graph)? "is cyclic":"is not cyclic");
}
