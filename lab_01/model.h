#ifndef MODEL_H
#define MODEL_H

#include "edges.h"
#include "points.h"
#include "errors.h"
#include "draw.h"
#include <cstdio>

using namespace std;

struct model
{
    points_t points;
    edges_t edges;
};

using model_t = struct model;
using fname_t = const char *;

error_t model_load(model_t &model, fname_t fname);
error_t model_draw(const model_t &model, const canvas_t canvas);
error_t model_scale(model_t &model, const scale_params_t &params);
error_t model_rotate(model_t &model, const rotate_params_t &params);
error_t model_move(model_t &model, const move_params_t &params);
void model_free(model_t &model);

#endif // MODEL_H
