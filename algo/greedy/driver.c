#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "union_find.h"

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
    //printf("The graph %s\n", is_cycle2(graph)? "is cyclic":"is not cyclic");
    
}