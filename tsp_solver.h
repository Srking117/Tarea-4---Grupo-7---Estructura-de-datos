#ifndef TSP_SOLVER_H
#define TSP_SOLVER_H

#include "common.h"
#include "graph.h"

int solve_tsp(Graph* graph, int start, int* path, int* min_cost);

#endif