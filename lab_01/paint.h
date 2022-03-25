#ifndef PAINT_H
#define PAINT_H

#include "point.h"
#include "ui_mainwindow.h"

struct canvas
{
    QGraphicsScene *scene;
    double width;
    double height;
};

using canvas_t = struct canvas;

void paint_line(point_t point1, point_t point2, canvas_t canvas);
void canvas_clear(const canvas_t &canvas);

#endif // PAINT_H
