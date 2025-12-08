#ifndef GRAPH_UTILS_H
#define GRAPH_UTILS_H

#include "common.h"
#include "graph.h"

/* Devuelve el grado (cantidad de vecinos) de un nodo del grafo.
Si el grafo es NULL o el nodo esta fuera de rango, devuelve 0. */
size_t grafo_grado(const Grafo *grafo, size_t nodo);

/* Verifica si todos los nodos del grafo tienen grado al menos "min_grado".
Devuelve:
- true  si todos los nodos cumplen grado >= min_grado.
- false si algun nodo no lo cumple o el grafo es invalido. */
bool grafo_todos_nodos_con_grado_al_menos(const Grafo *grafo, size_t min_grado);

#endif // GRAPH_UTILS_H
