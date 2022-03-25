#ifndef EDGES_H
#define EDGES_H

#include "edge.h"
#include <cstddef>
#include <cstdlib>

#define EDGES_CNT_READ 1

struct edges
{
    size_t cnt = 0;
    edge_t *data = NULL;
};

using edges_t = struct edges;

bool is_edges_empty(const edges_t &edges);
error_t edges_load(edges_t &edges, FILE *f);
void edges_free(edges_t &edges);

#endif // EDGES_H
