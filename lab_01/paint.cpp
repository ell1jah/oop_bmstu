#include "paint.h"

void paint_line(point_t point1, point_t point2, canvas_t canvas)
{
    canvas.scene->addLine(
        point1.x + canvas.width / 2,
        point1.y + canvas.height / 2,
        point2.x + canvas.width / 2,
        point2.y + canvas.height / 2
   );
}

void canvas_clear(const canvas_t &canvas)
{
    canvas.scene->clear();
}
