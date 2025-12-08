#include "hamiltonian.h"
#include "graph_utils.h"

static bool hamiltoniano_backtrack(const Grafo *grafo, size_t *camino, bool *visitado, size_t posicion, size_t cantidad_nodos) {
    // Caso base: ya llenamos todos los nodos
    if (posicion == cantidad_nodos) {
        size_t ultimo = camino[cantidad_nodos - 1];
        size_t primero = camino[0];

        // Debe existir arista desde el ultimo hacia el primero para cerrar el ciclo
        return grafo_tiene_arista(grafo, ultimo, primero);
    }

    size_t ultimo = camino[posicion - 1];

    // Probamos con todos los nodos posibles (excepto el 0, ya usado al inicio)
    for (size_t candidato = 1; candidato < cantidad_nodos; ++candidato) {
        if (!visitado[candidato] && grafo_tiene_arista(grafo, ultimo, candidato)) {
            // Elegimos este nodo
            camino[posicion] = candidato;
            visitado[candidato] = true;

            if (hamiltoniano_backtrack(grafo, camino, visitado, posicion + 1, cantidad_nodos)) {
                return true; // Encontramos un ciclo valido
            }

            // backtracking
            visitado[candidato] = false;
        }
    }

    // No se encontro ningun ciclo continuando desde esta configuracion
    return false;
}

bool hamiltoniano_tiene_ciclo(const Grafo *grafo) {
    if (grafo == NULL) return false;

    size_t cantidad_nodos = grafo_obtener_cantidad_nodos(grafo);
    if (cantidad_nodos < 3) {
        // Con menos de 3 nodos no tiene sentido un ciclo hamiltoniano que regrese al origen
        return false;
    }

    // Poda rapida: todos los nodos deben tener al menos grado 2
    if (!grafo_todos_nodos_con_grado_al_menos(grafo, 2)) {
        return false;
    }

    bool visitado[PVV_MAX_NODOS] = { false };
    size_t camino[PVV_MAX_NODOS];

    // Fijamos siempre el nodo 0 ('A') como inicio del ciclo
    camino[0] = 0;
    visitado[0] = true;

    // Empezamos a completar desde la posición 1
    return hamiltoniano_backtrack(grafo, camino, visitado, 1, cantidad_nodos);
}
