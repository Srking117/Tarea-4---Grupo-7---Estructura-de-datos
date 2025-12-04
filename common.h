#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

// ----------------- Constantes generales ----------------- 
#define PVV_MAX_NODOS 9 	 // Máximo de nodos permitido en el grafo (según enunciado: 5 a 9)
#define PVV_SIN_ARISTA  (-1) // Valor especial para indicar que no existe arista entre dos nodos

// ----------------- Estructuras de datos -----------------
typedef struct Nodo { // Representa una ciudad / nodo del grafo
	char etiqueta;	    // 'A', 'B', 'C', ...
} Nodo;

typedef struct Arista { // Representa una arista entre dos nodos del grafo
	size_t desde;         // índice del nodo de origen
	size_t hasta;         // índice del nodo de destino
	int    costo;         // costo / longitud de la arista
} Arista;

typedef struct Grafo { 	  // Representa el grafo completo mediante matriz de adyacencia
	size_t cantidad_nodos;  // número de nodos en el grafo
	Nodo  *nodos;           // arreglo de nodos (tamaño cantidad_nodos)
	int   *costos;          // matriz de costos (cantidad_nodos^2)
} Grafo;

typedef struct ContextoPvv { // Contexto global del programa: grafo actual en memoria
	Grafo *grafo_actual;
} ContextoPvv;

typedef enum EstadoPvv {       // Códigos de estado generales para las operaciones del programa
	PVV_EXITO = 0,                    // Operación realizada correctamente
	PVV_ERROR_YA_INICIADO,            // Ya existe un grafo iniciado
	PVV_ERROR_NO_INICIADO,            // No hay grafo iniciado
	PVV_ERROR_CANTIDAD_NODOS_INVALIDA,// Número de nodos fuera de rango
	PVV_ERROR_MEMORIA,                 // Error al reservar memoria
	PVV_ERROR_ARCHIVO                 // Error al leer archivo
} EstadoPvv;

// ----------------- Funciones auxiliares -----------------

// Convierte una etiqueta de ciudad (por ejemplo 'A') a índice (0, 1, 2, ...)
static int etiqueta_a_indice(char etiqueta) {
	return (int)(etiqueta - 'A');
}

// Convierte un índice (0, 1, 2, ...) a etiqueta de ciudad ('A', 'B', 'C', ...)
static char indice_a_etiqueta(size_t indice) {
	return (char)('A' + indice);
}

#endif // COMMON_H 
