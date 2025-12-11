#include <stdio.h>
#include "interface.h"

void print_graph(Graph* g) {
    if (!g) {
        printf("No hay grafo cargado.\n");
        return;
    }

    printf("Representación del grafo:\n");

    for (int i = 0; i < g->size; i++) {
        printf("%c -> ", g->nodes[i].name);

        Edge* e = g->nodes[i].edges;

        while (e) {
            printf("%c(%d) ", g->nodes[e->to].name, e->weight);
            e = e->next;
        }

        printf("\n");
    }
}
