#include "graph_utils.h"

size_t grafo_grado(const Grafo *grafo, size_t nodo) {
    if (grafo == NULL) return 0;

    size_t cantidad = grafo_obtener_cantidad_nodos(grafo);
    if (nodo >= cantidad) return 0;

    size_t grado = 0;

    for (size_t i = 0; i < cantidad; ++i) {
        if (grafo_tiene_arista(grafo, nodo, i)) {
            grado++;
        }
    }

    return grado;
}

bool grafo_todos_nodos_con_grado_al_menos(const Grafo *grafo, size_t min_grado) {
    if (grafo == NULL) return false;

    size_t cantidad = grafo_obtener_cantidad_nodos(grafo);
    if (cantidad == 0) return false;

    for (size_t i = 0; i < cantidad; ++i) {
        if (grafo_grado(grafo, i) < min_grado) {
            return false;
        }
    }

    return true;
}
