#include <stdlib.h>
#include "memory_manager.h"

Grafo *grafo_crear(size_t cantidad_nodos) {
	if (cantidad_nodos == 0 || cantidad_nodos > PVV_MAX_NODOS) return NULL;

	Grafo *grafo = (Grafo *)malloc(sizeof(Grafo));
	if (grafo == NULL) return NULL;

	grafo->cantidad_nodos = cantidad_nodos;

	grafo->nodos = (Nodo *)malloc(cantidad_nodos * sizeof(Nodo));
	if (grafo->nodos == NULL) {
		free(grafo);
		return NULL;
	}

	size_t total_celdas = cantidad_nodos * cantidad_nodos;
	grafo->costos = (int *)malloc(total_celdas * sizeof(int));
	if (grafo->costos == NULL) {
		free(grafo->nodos);
		free(grafo);
		return NULL;
	}

	// Inicializar etiquetas de nodos: 'A', 'B', 'C', ...
	for (size_t i = 0; i < cantidad_nodos; ++i)
		grafo->nodos[i].etiqueta = indice_a_etiqueta(i);

	// Inicializar matriz de costos con PVV_SIN_ARISTA
	for (size_t i = 0; i < total_celdas; ++i)
		grafo->costos[i] = PVV_SIN_ARISTA;

	return grafo;
}

void grafo_destruir(Grafo *grafo) {
	if (grafo == NULL) return;

	free(grafo->costos);
	free(grafo->nodos);
	free(grafo);
}

EstadoPvv pvv_start(ContextoPvv *contexto, size_t cantidad_nodos) {
	if (contexto == NULL) return PVV_ERROR_MEMORIA;

	if (contexto->grafo_actual != NULL) return PVV_ERROR_YA_INICIADO;

	if (cantidad_nodos == 0 || cantidad_nodos > PVV_MAX_NODOS) return PVV_ERROR_CANTIDAD_NODOS_INVALIDA;

	Grafo *nuevo_grafo = grafo_crear(cantidad_nodos);
	if (nuevo_grafo == NULL) return PVV_ERROR_MEMORIA;

	contexto->grafo_actual = nuevo_grafo;
	return PVV_EXITO;
}

EstadoPvv pvv_exit(ContextoPvv *contexto) {
	if (contexto == NULL || contexto->grafo_actual == NULL) return PVV_ERROR_NO_INICIADO;

	grafo_destruir(contexto->grafo_actual);
	contexto->grafo_actual = NULL;

	return PVV_EXITO;
}
