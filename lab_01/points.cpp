#include "points.h"

static error_t points_read_cnt(points_t &points, FILE *f)
{
    if (!f)
        return FILE_ERROR;

    error_t rc = SUCCESS;
    size_t cnt_tmp;

    if (fscanf(f, "%zu\n", &cnt_tmp) == POINTS_CNT_READ)
        points.cnt = cnt_tmp;
    else
        rc = READ_ERROR;

    return rc;
}

static error_t points_alloc_data(points_t &points)
{
    error_t rc = SUCCESS;
    point_t *ptmp = (point_t*) malloc(points.cnt * sizeof(point_t));


    if (ptmp)
        points.data = ptmp;
    else
        rc = MEMORY_ERROR;

    return rc;
}

static error_t points_read(points_t &points, FILE *f)
{
    if (!f)
        return FILE_ERROR;

    error_t rc = SUCCESS;

    for (size_t i = 0; !rc && (i < points.cnt); i++)
        rc = point_read(points.data[i], f);

    return rc;
}

error_t points_load(points_t &points, FILE *f)
{
    if (!f)
        return FILE_ERROR;

    error_t rc = SUCCESS;

    rc = rc ? rc : points_read_cnt(points, f);

    rc = rc ? rc : points_alloc_data(points);

    rc = rc ? rc : points_read(points, f);

    if (rc)
        points_free(points);

    return rc;
}

void points_scale(points_t &points, const scale_params_t &params)
{
    for (size_t i = 0; i < points.cnt; i++)
        point_scale(params, points.data[i]);
}

void points_rotate(points_t &points, const rotate_params_t &params)
{
    for (size_t i = 0; i < points.cnt; i++)
        point_rotate(params, points.data[i]);
}

void points_move(points_t &points, const move_params_t &params)
{
    for (size_t i = 0; i < points.cnt; i++)
        point_move(params, points.data[i]);
}

void points_free(points_t &points)
{
    free(points.data);
    points.data = NULL;
}
