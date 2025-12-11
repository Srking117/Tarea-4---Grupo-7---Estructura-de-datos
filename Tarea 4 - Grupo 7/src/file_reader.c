#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"
#include "memory_manager.h"


static void add_edge(Graph* g, int from, int to, int weight) {
    Edge* e = mm_alloc(sizeof(Edge));
    e->to = to;
    e->weight = weight;
    e->next = g->nodes[from].edges;
    g->nodes[from].edges = e;
}


static int node_index(char c) {
    return c - 'A';
}

int read_edges_from_file(Graph* g, const char* filename) {
    if (!g) return -1;

    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Error al abrir archivo %s\n", filename);
        return -1;
    }

    char a, b;
    int w;

    printf("Agregando enlaces desde archivo.\n");

    while (fscanf(f, " %c %c %d", &a, &b, &w) == 3) {
        int i = node_index(a);
        int j = node_index(b);

        if (i < 0 || i >= g->size || j < 0 || j >= g->size) {
            printf("Advertencia: enlace %c-%c fuera de rango, ignorado.\n", a, b);
            continue;
        }

        add_edge(g, i, j, w);
        add_edge(g, j, i, w);
    }

    fclose(f);
    return 0;
}
