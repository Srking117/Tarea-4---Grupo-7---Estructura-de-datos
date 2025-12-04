#ifndef FILE_READER_H
#define FILE_READER_H

#include "common.h"
#include "graph.h"

/* pvv_read: Lee un archivo de texto con la estructura "Origen Destino Costo"
   y puebla el grafo actual.
   
   Retorna:
   - PVV_EXITO: Lectura correcta.
   - PVV_ERROR_NO_INICIADO: Si no hay grafo.
   - -1 (u otro código): Si no se puede abrir el archivo.
*/
int pvv_read(ContextoPvv *contexto, const char *nombre_archivo);

#endif