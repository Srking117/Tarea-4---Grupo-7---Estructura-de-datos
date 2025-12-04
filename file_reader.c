#include <stdio.h>
#include <stdlib.h>
#include "file_reader.h"

int pvv_read(ContextoPvv *contexto, const char *nombre_archivo) {
    if (!contexto || !contexto->grafo_actual) {
        return PVV_ERROR_NO_INICIADO;
    }

    FILE *fp = fopen(nombre_archivo, "r");
    if (!fp) {
        return PVV_ERROR_ARCHIVO; // Error abriendo archivo
    }

    // Limpiamos aristas viejas antes de cargar nuevas (según lógica común de recarga)
    
    char origen_lbl, destino_lbl;
    int costo;

    // Formato del archivo: "A B 15" 
    while (fscanf(fp, " %c %c %d", &origen_lbl, &destino_lbl, &costo) == 3) {
        int u = etiqueta_a_indice(origen_lbl);
        int v = etiqueta_a_indice(destino_lbl);
        
        // Intentamos agregar. Si falla (índices fuera de rango), ignoramos o reportamos.
        grafo_agregar_arista_no_dirigida(contexto->grafo_actual, u, v, costo);
    }

    fclose(fp);
    return PVV_EXITO;
}