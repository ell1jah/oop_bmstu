#ifndef POINTS_H
#define POINTS_H

#include "point.h"
#include "errors.h"
#include <cstdio>
#include <cstdlib>

#define POINTS_CNT_READ 1

struct points
{
    size_t cnt = 0;
    point_t *data = NULL;
};

using points_t = struct points;

error_t points_load(points_t &points, FILE *f);
void points_scale(points_t &points, const scale_params_t &params);
void points_rotate(points_t &points, const rotate_params_t &params);
void points_move(points_t &points, const move_params_t &params);
void points_free(points_t &points);

#endif // POINTS_H
