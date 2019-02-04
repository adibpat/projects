#include <stdio.h>
#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__
typedef struct Edge {
    // properties of edge
    int v1, v2, weight;
} Edge;

typedef struct Graph {
    int V, E;
    Edge *edge;
} Graph;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

Graph * create_graph (int V, int E);

#endif /* __UNION_FIND_H__ */