#include <stdio.h>
#include <stdlib.h>
#include "graph_utils.h"

static void dfs(Graph* g, int v, int* visited) {
    visited[v] = 1;
    Edge* e = g->nodes[v].edges;

    while (e) {
        if (!visited[e->to])
            dfs(g, e->to, visited);
        e = e->next;
    }
}


int is_connected(Graph* g) {
    if (!g || g->size == 0) return 0;

    int* visited = calloc(g->size, sizeof(int));
    dfs(g, 0, visited);

    for (int i = 0; i < g->size; i++) {
        if (!visited[i]) {
            free(visited);
            return 0;
        }
    }

    free(visited);
    return 1;
}
