#ifndef EDGE_H
#define EDGE_H

#include "point.h"
#include <cstdio>

#define EDGE_COORDS_READ 2

struct edge
{
    size_t point1;
    size_t point2;
};

using edge_t = struct edge;

error_t edge_read(edge_t &edge, FILE *f);

#endif // EDGE_H
