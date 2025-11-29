#include "graph.h"

// Función auxiliar interna para obtener el índice en la matriz de costos
static size_t indice_matriz(const Grafo *grafo, size_t desde, size_t hasta) {
	return desde * grafo->cantidad_nodos + hasta;
}

size_t grafo_obtener_cantidad_nodos(const Grafo *grafo) {
	if (grafo == NULL) return 0;
	return grafo->cantidad_nodos;
}

bool grafo_agregar_arista_no_dirigida(Grafo *grafo, size_t desde, size_t hasta, int costo) {
	if (grafo == NULL) return false;

	size_t cantidad = grafo->cantidad_nodos;
	if (desde >= cantidad || hasta >= cantidad) return false;

	if (costo < 0) return false;

	size_t indice_1 = indice_matriz(grafo, desde, hasta);
	size_t indice_2 = indice_matriz(grafo, hasta, desde);

	grafo->costos[indice_1] = costo;
	grafo->costos[indice_2] = costo;

	return true;
}

bool grafo_tiene_arista(const Grafo *grafo, size_t desde, size_t hasta) {
	if (grafo == NULL) return false;

	size_t cantidad = grafo->cantidad_nodos;
	if (desde >= cantidad || hasta >= cantidad) return false;

	size_t indice = indice_matriz(grafo, desde, hasta);
	return grafo->costos[indice] != PVV_SIN_ARISTA;
}

int grafo_obtener_costo(const Grafo *grafo, size_t desde, size_t hasta) {
	if (grafo == NULL) return PVV_SIN_ARISTA;

	size_t cantidad = grafo->cantidad_nodos;
	if (desde >= cantidad || hasta >= cantidad) return PVV_SIN_ARISTA;

	size_t indice = indice_matriz(grafo, desde, hasta);
	return grafo->costos[indice];
}

void grafo_limpiar_aristas(Grafo *grafo) {
	if (grafo == NULL) return;

	size_t cantidad = grafo->cantidad_nodos;
	size_t total_celdas = cantidad * cantidad;

	for (size_t i = 0; i < total_celdas; ++i)
		grafo->costos[i] = PVV_SIN_ARISTA;
}
