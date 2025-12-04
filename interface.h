#ifndef INTERFACE_H
#define INTERFACE_H

#include "common.h"
#include "graph.h"

// Muestra mensajes de estado (Éxito, Error de memoria, etc.)
void interface_mostrar_mensaje(EstadoPvv estado);

// Muestra un mensaje personalizado
void interface_imprimir_linea(const char *mensaje);

// Imprime la representación del grafo (Comando >pvv graph)
void interface_mostrar_grafo(const Grafo *grafo);

#endif