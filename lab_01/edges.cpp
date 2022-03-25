#include "edges.h"

bool is_edges_empty(const edges_t &edges)
{
    return edges.cnt ? false : true;
}

static error_t edges_read_cnt(edges_t &edges, FILE *f)
{
    if (!f)
        return FILE_ERROR;

    error_t rc = SUCCESS;
    size_t cnt_tmp;

    if (fscanf(f, "%zu\n", &cnt_tmp) == EDGES_CNT_READ)
        edges.cnt = cnt_tmp;
    else
        rc = READ_ERROR;

    return rc;
}

static error_t edges_alloc_data(edges_t &edges)
{
    error_t rc = SUCCESS;
    edge_t *ptmp = (edge_t*) malloc(edges.cnt * sizeof(edge_t));


    if (ptmp)
        edges.data = ptmp;
    else
        rc = MEMORY_ERROR;

    return rc;
}

static error_t edges_read(edges_t &edges, FILE *f)
{
    if (!f)
        return FILE_ERROR;

    error_t rc = SUCCESS;

    for (size_t i = 0; !rc && (i < edges.cnt); i++)
        rc = edge_read(edges.data[i], f);

    return rc;
}

error_t edges_load(edges_t &edges, FILE *f)
{
    if (!f)
        return FILE_ERROR;

    error_t rc = SUCCESS;

    rc = edges_read_cnt(edges, f);

    rc = rc ? rc : edges_alloc_data(edges);

    rc = rc ? rc : edges_read(edges, f);

    if (rc)
        edges_free(edges);

    return rc;
}

void edges_free(edges_t &edges)
{
    free(edges.data);
    edges.data = NULL;
}
