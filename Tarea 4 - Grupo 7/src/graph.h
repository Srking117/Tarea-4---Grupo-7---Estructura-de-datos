#ifndef GRAPH_H
#define GRAPH_H

#include "common.h"

Graph* graph_create(int size);
void graph_free(Graph* g);
void graph_init_names(Graph* g);

#endif
