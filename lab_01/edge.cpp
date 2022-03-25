#include "edge.h"

error_t edge_read(edge_t &edge, FILE *f)
{
    if (!f)
        return FILE_ERROR;

    error_t rc = SUCCESS;
    size_t point1, point2;

    if (fscanf(f, "%zu %zu\n", &point1, &point2) == EDGE_COORDS_READ)
    {
        edge.point1 = point1;
        edge.point2 = point2;
    }
    else
        rc = READ_ERROR;

    return rc;
}
