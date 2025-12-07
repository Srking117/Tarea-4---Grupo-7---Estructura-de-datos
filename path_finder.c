#include "path_finder.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* path_to_string(Graph* graph, int* path, int node_count) {
    char* str = malloc((node_count * 3 + 1) * sizeof(char));
    str[0] = '\0';
    
    for (int i = 0; i < node_count; i++) {
        char node_name[2];
        node_name[0] = 'A' + path[i];
        node_name[1] = '\0';
        strcat(str, node_name);
        if (i < node_count - 1) strcat(str, " ");
    }
    
    char start_name[2];
    start_name[0] = 'A' + path[0];
    start_name[1] = '\0';
    strcat(str, " ");
    strcat(str, start_name);
    
    return str;
}

void print_path(Graph* graph, int* path, int node_count, int total_cost) {
    printf("Ruta a seguir: ");
    
    for (int i = 0; i < node_count; i++) {
        printf("%c ", 'A' + path[i]);
    }
    printf("%c\n", 'A' + path[0]);
    
    printf("Costo total mínimo: %d\n", total_cost);
}