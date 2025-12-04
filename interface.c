#include <stdio.h>
#include "interface.h"

void interface_mostrar_mensaje(EstadoPvv estado) {
    switch (estado) {
        case PVV_EXITO:
            // Generalmente no se imprime nada en éxito genérico, salvo que el comando lo requiera
            break;
        case PVV_ERROR_YA_INICIADO:
            printf("Error: El grafo ya ha sido inicializado.\n");
            break;
        case PVV_ERROR_NO_INICIADO:
            printf("Error: No se ha iniciado un grafo. Use 'pvv start <n>'.\n");
            break;
        case PVV_ERROR_CANTIDAD_NODOS_INVALIDA:
            printf("Error: Cantidad de nodos inválida (Debe ser entre 1 y %d).\n", PVV_MAX_NODOS);
            break;
        case PVV_ERROR_MEMORIA:
            printf("Error: Fallo de asignación de memoria.\n");
            break;
        case PVV_ERROR_ARCHIVO:
            printf("Error: No se pudo leer el archivo especificado.\n");
            break;
        default:
            printf("Error desconocido.\n");
    }
}

void interface_imprimir_linea(const char *mensaje) {
    if (mensaje) printf("%s\n", mensaje);
}

void interface_mostrar_grafo(const Grafo *grafo) {
    if (!grafo) return;

    size_t n = grafo_obtener_cantidad_nodos(grafo);

    // Cabecera de columnas
    printf("   ");
    for (size_t i = 0; i < n; i++) {
        printf(" %c  ", indice_a_etiqueta(i));
    }
    printf("\n");

    // Filas
    for (size_t i = 0; i < n; i++) {
        printf(" %c ", indice_a_etiqueta(i));
        for (size_t j = 0; j < n; j++) {
            int costo = grafo_obtener_costo(grafo, i, j);
            if (costo == PVV_SIN_ARISTA) {
                printf(" -  "); // O espacio vacío
            } else {
                printf("%-3d ", costo);
            }
        }
        printf("\n");
    }
}