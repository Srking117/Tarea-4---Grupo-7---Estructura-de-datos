#include <stdio.h>
#include <stdlib.h>
#include "hamiltonian.h"
#include "graph_utils.h"

static int is_valid_edge(Graph* g, int from, int to) {
    Edge* e = g->nodes[from].edges;
    while (e) {
        if (e->to == to) return 1;
        e = e->next;
    }
    return 0;
}

static int backtrack(Graph* g, int* path, int pos, int* visited) {
    int n = g->size;

   
    if (pos == n) {
        
        return is_valid_edge(g, path[n - 1], path[0]);
    }

    for (int v = 1; v < n; v++) {
        if (!visited[v] && is_valid_edge(g, path[pos - 1], v)) {
            visited[v] = 1;
            path[pos] = v;

            if (backtrack(g, path, pos + 1, visited))
                return 1;

            visited[v] = 0;
        }
    }

    return 0;
}

int check_hamiltonian(Graph* g) {
    if (!g) return 0;

    printf("Verificando que existe una ruta.\n");

    
    if (!is_connected(g)) {
        printf("No existe un camino que recorra todos las ciudades y regrese a la ciudad de origen.\n");
        return 0;
    }

    int n = g->size;
    int* path = calloc(n, sizeof(int));
    int* visited = calloc(n, sizeof(int));

    path[0] = 0;
    visited[0] = 1;

    int result = backtrack(g, path, 1, visited);

    if (result)
        printf("Existe un camino que recorre todos las ciudades y regresa a la ciudad de origen.\n");
    else
        printf("No existe un camino que recorra todos las ciudades y regrese a la ciudad de origen.\n");

    free(path);
    free(visited);

    return result;
}
