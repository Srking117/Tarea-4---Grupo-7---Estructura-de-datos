#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include "common.h"
#include "graph.h"

/* Manejo de memoria del grafo y comandos lógicos pvv_start / pvv_exit.
 Este módulo se encarga de:
 - Reservar y liberar la memoria asociada a un Grafo.
 - Inicializar y limpiar el ContextoPvv.
 - Implementar la lógica de los comandos pvv start y pvv exit,
   devolviendo códigos de EstadoPvv para que otra capa decida qué mensajes mostrar al usuario. */

/* grafo_crear: Crea un grafo con la cantidad de nodos indicada.
 Devuelve:
 - Puntero al Grafo creado si tuvo éxito.
 - NULL si hubo error (por ejemplo, memoria insuficiente o cantidad_nodos fuera de rango).

 Nota: los nodos se inicializan con etiquetas 'A', 'B', 'C', ... y la matriz de costos se inicializa con PVV_SIN_ARISTA. */
Grafo *grafo_crear(size_t cantidad_nodos);

// Libera toda la memoria asociada al grafo. Si grafo es NULL, no hace nada.
void grafo_destruir(Grafo *grafo);

/* pvv_start: Implementación lógica del comando "pvv start <n>".
- contexto: contexto global del programa.
- cantidad_nodos: cantidad de nodos del grafo a crear.

Devuelve:
- PVV_EXITO si se creó el grafo correctamente.
- PVV_ERROR_YA_INICIADO si ya existía un grafo en contexto->grafo_actual.
- PVV_ERROR_CANTIDAD_NODOS_INVALIDA si cantidad_nodos es 0 o > PVV_MAX_NODOS.
- PVV_ERROR_MEMORIA si ocurrió un problema al reservar memoria. */
EstadoPvv pvv_start(ContextoPvv *contexto, size_t cantidad_nodos);

/* pvv_exit: Implementación lógica del comando "pvv exit".
- contexto: contexto global del programa.

Devuelve:
 - PVV_EXITO si se liberó el grafo correctamente (o si se limpió contexto).
 - PVV_ERROR_NO_INICIADO si no había grafo en memoria (contexto->grafo_actual es NULL). */
EstadoPvv pvv_exit(ContextoPvv *contexto);

#endif // MEMORY_MANAGER_H
