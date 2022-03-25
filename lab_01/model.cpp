#include "model.h"

static error_t model_tmp_load(model_t &tmp_model, FILE *f)
{
    if (!f)
        return FILE_ERROR;

    error_t rc = SUCCESS;

    rc = rc ? rc : points_load(tmp_model.points, f);
    rc = rc ? rc : edges_load(tmp_model.edges, f);

    if (rc)
        points_free(tmp_model.points);

    return rc;
}

error_t model_load(model_t &model, fname_t fname)
{
    error_t rc = SUCCESS;
    FILE *f = fopen(fname, "rt");
    model_t tmp_model;

    if (!f)
        rc = FILE_ERROR;

    rc = rc ? rc : model_tmp_load(tmp_model, f);

    fclose(f);

    if (!rc)
    {
        model_free(model);
        model = tmp_model;
    }

    return rc;
}

error_t model_draw(const model_t &model, const canvas_t canvas)
{
    error_t rc = SUCCESS;

    if (is_edges_empty(model.edges))
        rc = EMPTY_MODEL_ERROR;

    if (!rc)
    {
        canvas_clear(canvas);
        draw_edges(model.edges, model.points, canvas);
    }

    return rc;
}

error_t model_scale(model_t &model, const scale_params_t &params)
{
    error_t rc = SUCCESS;

    if (is_edges_empty(model.edges))
        rc = EMPTY_MODEL_ERROR;

    if (!rc)
        points_scale(model.points, params);

    return rc;
}

error_t model_rotate(model_t &model, const rotate_params_t &params)
{
    error_t rc = SUCCESS;

    if (is_edges_empty(model.edges))
        rc = EMPTY_MODEL_ERROR;

    if (!rc)
        points_rotate(model.points, params);

    return rc;
}

error_t model_move(model_t &model, const move_params_t &params)
{
    error_t rc = SUCCESS;

    if (is_edges_empty(model.edges))
        rc = EMPTY_MODEL_ERROR;

    if (!rc)
        points_move(model.points, params);

    return rc;
}

void model_free(model_t &model)
{
    points_free(model.points);
    edges_free(model.edges);
}
