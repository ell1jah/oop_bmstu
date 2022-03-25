#ifndef DRAW_H
#define DRAW_H

#include "ui_mainwindow.h"
#include "points.h"
#include "point.h"
#include "edges.h"
#include "edge.h"
#include "paint.h"
#include <cstddef>

struct canvas
{
    QGraphicsScene *scene;
    double width;
    double height;
};

using canvas_t = struct canvas;

void draw_edges(const edges_t &edges, const points_t &points, \
                const canvas_t &canvas);
void canvas_clear(const canvas_t &canvas);

#endif // DRAW_H
