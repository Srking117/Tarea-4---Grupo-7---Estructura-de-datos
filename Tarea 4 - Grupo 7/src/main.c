#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "graph.h"
#include "file_reader.h"
#include "interface.h"
#include "command_parser.h"
#include "hamiltonian.h"
#include "tsp_solver.h"

Graph* global_graph = NULL;

int main() {
    char input[128];
    char cmd[64];
    char arg[64];

    printf("Sistema PVV iniciado.\n");

    while (1) {
        printf(">pvv ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;

        int has_arg = parse_command(input, cmd, arg);

        
        if (strcmp(cmd, "start") == 0) {
            if (!has_arg) {
                printf("Debe indicar número de nodos.\n");
                continue;
            }

            int n = atoi(arg);

            if (global_graph)
                graph_free(global_graph);

            global_graph = graph_create(n);
            printf("Grafo creado con %d nodos\n", n);
        }

        
        else if (strcmp(cmd, "read") == 0) {
            if (!global_graph) {
                printf("Debe crear un grafo con start antes.\n");
                continue;
            }
            if (!has_arg) {
                printf("Debe indicar archivo.\n");
                continue;
            }

            if (read_edges_from_file(global_graph, arg) == 0) {
                printf("Archivo leído correctamente.\n");

                int exists = check_hamiltonian(global_graph);

                if (!exists)
                    continue;

                solve_tsp(global_graph);
            }
        }

        
        else if (strcmp(cmd, "graph") == 0) {
            print_graph(global_graph);
        }

        
        else if (strcmp(cmd, "exit") == 0) {
            printf("Limpiando cache y saliendo ...\n");
            if (global_graph)
                graph_free(global_graph);
            return 0;
        }

        else if (strlen(cmd) > 0) {
            printf("Comando no reconocido: %s\n", cmd);
        }
    }

    return 0;
}
