#include "tsp_solver.h"
#include <limits.h>
#include <string.h>

static int all_visited(int* visited, int count) {
    for (int i = 0; i < count; i++) {
        if (!visited[i]) return 0;
    }
    return 1;
}

static void backtrack(Graph* graph, int start, int current, int* visited, 
                      int* path, int depth, int current_cost, 
                      int* best_path, int* min_cost) {
    
    if (depth == graph->node_count) {
        int return_cost = graph_get_distance(graph, current, start);
        if (return_cost > 0) {
            int total = current_cost + return_cost;
            if (total < *min_cost) {
                *min_cost = total;
                memcpy(best_path, path, graph->node_count * sizeof(int));
            }
        }
        return;
    }

    for (int i = 0; i < graph->node_count; i++) {
        int dist = graph_get_distance(graph, current, i);
        if (!visited[i] && dist > 0) {
            visited[i] = 1;
            path[depth] = i;
            backtrack(graph, start, i, visited, path, depth + 1, 
                     current_cost + dist, best_path, min_cost);
            visited[i] = 0;
        }
    }
}

int solve_tsp(Graph* graph, int start, int* best_path, int* min_cost) {
    if (!graph || start < 0 || start >= graph->node_count) return 0;

    int visited[MAX_NODES] = {0};
    int path[MAX_NODES];
    
    visited[start] = 1;
    path[0] = start;
    
    *min_cost = INT_MAX;
    
    backtrack(graph, start, start, visited, path, 1, 0, best_path, min_cost);
    
    return (*min_cost != INT_MAX);
}