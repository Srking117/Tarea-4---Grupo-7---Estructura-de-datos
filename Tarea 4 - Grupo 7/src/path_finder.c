#include <stdio.h>
#include "path_finder.h"

int get_edge_cost(Graph* g, int from, int to) {
    Edge* e = g->nodes[from].edges;
    while (e) {
        if (e->to == to)
            return e->weight;
        e = e->next;
    }
    return -1; 
}

int calculate_path_cost(Graph* g, int* path, int n) {
    int total = 0;

    for (int i = 0; i < n - 1; i++) {
        int w = get_edge_cost(g, path[i], path[i + 1]);
        if (w < 0) return -1;
        total += w;
    }

    int w = get_edge_cost(g, path[n - 1], path[0]);
    if (w < 0) return -1;

    total += w;
    return total;
}
