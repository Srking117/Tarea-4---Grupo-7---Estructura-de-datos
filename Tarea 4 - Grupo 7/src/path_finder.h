#ifndef PATH_FINDER_H
#define PATH_FINDER_H

#include "common.h"
#include "graph.h"

int get_edge_cost(Graph* g, int from, int to);
int calculate_path_cost(Graph* g, int* path, int n);

#endif
