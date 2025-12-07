#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "memory_manager.h"
#include "file_reader.h"
#include "command_parser.h"
#include "interface.h"
#include "hamiltonian.h"
#include "tsp_solver.h"
#include "path_finder.h"

#define MAX_COMMAND_LENGTH 256
#define MAX_FILENAME_LENGTH 100

int main() {
    Graph* graph = NULL;
    char command[MAX_COMMAND_LENGTH];
    
    printf("Sistema TSP - Problema del Vendedor Viajante\n");
    printf("Ingrese comandos (pvv start N, pvv read archivo, pvv graph, pvv exit)\n\n");
    
    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0;
        
        Command cmd = parse_command(command);
        
        switch (cmd.type) {
            case CMD_START: {
                if (graph) {
                    free_graph(graph);
                }
                graph = create_graph(cmd.arg1);
                if (graph) {
                    printf("Grafo creado con %d nodos\n", graph->node_count);
                }
                break;
            }
            
            case CMD_READ: {
                if (!graph) {
                    printf("Error: Primero debe crear un grafo con 'pvv start N'\n");
                    break;
                }
                
                printf("Agregando enlaces desde archivo...\n");
                if (read_graph_from_file(graph, cmd.arg_str)) {
                    printf("Archivo leído correctamente.\n");
                    
                    printf("Verificando que existe una ruta...\n");
                    if (has_hamiltonian_cycle(graph)) {
                        printf("Existe un camino que recorre todas las ciudades y regresa a la ciudad de origen.\n");
                        
                        int path[MAX_NODES];
                        int min_cost;
                        
                        if (solve_tsp(graph, 0, path, &min_cost)) {
                            print_path(graph, path, graph->node_count, min_cost);
                        } else {
                            printf("No se pudo encontrar una ruta mínima.\n");
                        }
                    } else {
                        printf("No existe un camino que recorra todas las ciudades y regrese a la ciudad de origen.\n");
                    }
                } else {
                    printf("Error al leer el archivo.\n");
                }
                break;
            }
            
            case CMD_GRAPH: {
                if (!graph) {
                    printf("Error: No hay grafo creado.\n");
                } else {
                    print_graph(graph);
                }
                break;
            }
            
            case CMD_EXIT: {
                if (graph) {
                    free_graph(graph);
                }
                printf("Limpiando cache y saliendo...\n");
                return 0;
            }
            
            case CMD_ERROR:
            default: {
                printf("Comando no reconocido. Comandos válidos:\n");
                printf("  pvv start N      - Crear grafo con N ciudades\n");
                printf("  pvv read archivo - Leer rutas desde archivo\n");
                printf("  pvv graph        - Mostrar grafo actual\n");
                printf("  pvv exit         - Salir del programa\n");
                break;
            }
        }
    }
    
    return 0;
}