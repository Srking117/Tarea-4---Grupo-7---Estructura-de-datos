#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include "common.h"
#include "graph.h"

char* path_to_string(Graph* graph, int* path, int node_count);
void print_path(Graph* graph, int* path, int node_count, int total_cost);

#endif