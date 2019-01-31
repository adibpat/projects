#include <stdio.h>

typedef struct Edge {
    // properties of edge
    int v1, v2, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge *edge;
} Graph;

Graph * create_graph (int V, int E);
