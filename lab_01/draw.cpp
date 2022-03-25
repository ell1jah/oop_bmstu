#include "draw.h"

static void draw_edge(const edge_t &edge, const points_t &points, \
                      const canvas_t &canvas)
{
    point_t point1 = points.data[edge.point1];
    point_t point2 = points.data[edge.point2];

    paint_line(point1, point2, canvas);
}

void draw_edges(const edges_t &edges, const points_t &points, \
                const canvas_t &canvas)
{
    for (size_t i = 0; i < edges.cnt; i++)
        draw_edge(edges.data[i], points, canvas);
}

void canvas_clear(const canvas_t &canvas)
{
    canvas.scene->clear();
}
