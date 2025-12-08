#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "command_parser.h"
#include "memory_manager.h" // Para pvv_start, pvv_exit
#include "file_reader.h"    // Para pvv_read
#include "interface.h"      // Para mostrar mensajes
#include "hamiltonian.h"    // Verificacion de ciclo hamiltoniano

#define BUFFER_SIZE 256

void loop_principal(ContextoPvv *contexto) {
    char buffer[BUFFER_SIZE];

    while (1) {
        printf(">pvv "); // Prompt
        if (!fgets(buffer, BUFFER_SIZE, stdin)) break;

        // Remover salto de línea
        buffer[strcspn(buffer, "\n")] = 0;

        // Tokenizar comando
        char *cmd = strtok(buffer, " ");
        if (!cmd) continue; // Línea vacía

        if (strcmp(cmd, "exit") == 0) {
            EstadoPvv st = pvv_exit(contexto);
            if (st == PVV_EXITO) {
                interface_imprimir_linea("Limpiando cache y saliendo");
            } else {
                interface_mostrar_mensaje(st); // Caso raro si falla exit
            }
            break; // Romper el while
        } 
        else if (strcmp(cmd, "start") == 0) {
            char *arg = strtok(NULL, " ");
            if (arg) {
                int n = atoi(arg);
                EstadoPvv st = pvv_start(contexto, (size_t)n);
                if (st == PVV_EXITO) {
                    char msg[64];
                    sprintf(msg, "Grafo creado con %d nodos", n);
                    interface_imprimir_linea(msg);
                } else {
                    interface_mostrar_mensaje(st);
                }
            } else {
                interface_imprimir_linea("Falta argumento: start <n>");
            }
        }
        else if (strcmp(cmd, "read") == 0) {
            char *filename = strtok(NULL, " ");
            if (filename) {
                interface_imprimir_linea("Agregando enlaces desde archivo.");
                int res = pvv_read(contexto, filename);
                if (res == PVV_ERROR_NO_INICIADO) {
                    interface_mostrar_mensaje(PVV_ERROR_NO_INICIADO);
                } else if (res == PVV_ERROR_ARCHIVO) {
                    interface_imprimir_linea("Error: No se pudo abrir el archivo.");
                } else {
                    interface_imprimir_linea("Verificando que existe una ruta...");

                    Grafo *grafo = contexto->grafo_actual;
                    if (hamiltoniano_tiene_ciclo(grafo)) {
                        interface_imprimir_linea(
                            "Existe un camino que recorre todas las ciudades y regresa a la ciudad de origen."
                        );
                    } else {
                        interface_imprimir_linea(
                            "No existe un camino que recorra todas las ciudades y regrese a la ciudad de origen."
                        );
                    }
                }
            } else {
                interface_imprimir_linea("Falta nombre de archivo: read <archivo>");
            }
        }           

        else if (strcmp(cmd, "graph") == 0) {
            if (contexto->grafo_actual) {
                interface_mostrar_grafo(contexto->grafo_actual);
            } else {
                interface_mostrar_mensaje(PVV_ERROR_NO_INICIADO);
            }
        }
        else {
            interface_imprimir_linea("Comando no reconocido.");
        }
    }
}