#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "memory_manager.h"


Graph* graph_create(int size) {
    Graph* g = mm_alloc(sizeof(Graph));
    g->size = size;
    g->nodes = mm_alloc(sizeof(Node) * size);

    for (int i = 0; i < size; i++) {
        g->nodes[i].edges = NULL;
        g->nodes[i].name = 'A' + i;  
    }

    return g;
}

void graph_free(Graph* g) {
    if (!g) return;

    for (int i = 0; i < g->size; i++) {
        Edge* current = g->nodes[i].edges;
        while (current) {
            Edge* tmp = current;
            current = current->next;
            free(tmp);
        }
    }

    free(g->nodes);
    free(g);
}
