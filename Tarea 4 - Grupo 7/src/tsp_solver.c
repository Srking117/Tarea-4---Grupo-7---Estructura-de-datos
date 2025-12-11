#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "tsp_solver.h"
#include "path_finder.h"

static void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static void permute(Graph* g, int* arr, int l, int r, 
                    int* best_cost, int* best_path) {

    if (l == r) {
        int cost = calculate_path_cost(g, arr, r + 1);
        if (cost >= 0 && cost < *best_cost) {
            *best_cost = cost;
            for (int i = 0; i <= r; i++)
                best_path[i] = arr[i];
        }
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(&arr[l], &arr[i]);
        permute(g, arr, l + 1, r, best_cost, best_path);
        swap(&arr[l], &arr[i]);
    }
}

void solve_tsp(Graph* g) {
    int n = g->size;

    int* arr = malloc(sizeof(int) * n);
    int* best_path = malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
        arr[i] = i;

    int best_cost = INT_MAX;

    permute(g, arr, 1, n - 1, &best_cost, best_path);

    printf("Ruta a seguir: ");
    for (int i = 0; i < n; i++)
        printf("%c ", g->nodes[best_path[i]].name);
    printf("%c\n", g->nodes[best_path[0]].name);

    printf("Costo total mínimo: %d\n", best_cost);

    free(arr);
    free(best_path);
}
