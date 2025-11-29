#ifndef GRAPH_H
#define GRAPH_H

#include "common.h"

// Devuelve la cantidad de nodos del grafo. Si grafo es NULL, devuelve 0.
size_t grafo_obtener_cantidad_nodos(const Grafo *grafo); 

/*grafo_agregar_arista_no_dirigida: Agrega una arista no dirigida entre dos nodos del grafo.
 - grafo: puntero al grafo.
 - desde, hasta: índices de los nodos (0 .. cantidad_nodos-1).
 - costo: costo de la arista (debe ser >= 0).
 
 Devuelve:
 - true  si la arista se agregó correctamente.
 - false si hay parámetros inválidos o grafo es NULL.
 */
bool grafo_agregar_arista_no_dirigida(Grafo *grafo, size_t desde, size_t hasta, int costo);

/* grafo_tiene_arista: Indica si existe una arista entre dos nodos.
 Devuelve:
 - true  si existe arista.
 - false si no existe o hay parámetros inválidos.
 */
bool grafo_tiene_arista(const Grafo *grafo, size_t desde, size_t hasta);

/* grafo_obtener_costo: Obtiene el costo de la arista entre dos nodos.
 Devuelve:
 - costo de la arista si existe.
 - PVV_SIN_ARISTA si no existe o hay parámetros inválidos.
 */
int grafo_obtener_costo(const Grafo *grafo, size_t desde, size_t hasta);

// Elimina todas las aristas del grafo, dejando la matriz en PVV_SIN_ARISTA.
void grafo_limpiar_aristas(Grafo *grafo);

#endif // GRAPH_H
