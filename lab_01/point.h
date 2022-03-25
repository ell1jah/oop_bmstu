#ifndef POINT_H
#define POINT_H

#include "errors.h"
#include <cstdio>
#include <math.h>

#define POINT_COORDS_READ 3
#define PI 3.1415926535

struct point
{
    double x;
    double y;
    double z;
};

using point_t = struct point;

struct coefs
{
    double kx;
    double ky;
    double kz;
};

using coefs_t = struct coefs;

struct angles
{
    double ax;
    double ay;
    double az;
};

using angles_t = struct angles;

struct scale_params
{
    coefs_t coefs;
    point_t about;
};

struct rotate_params
{
    angles_t angles;
    point_t about;
};

struct move_params
{
    double dx;
    double dy;
    double dz;
};

using scale_params_t = struct scale_params;
using rotate_params_t = struct rotate_params;
using move_params_t = struct move_params;

error_t point_read(point_t &point, FILE *f);
void point_move(const move_params_t &params, point_t &point);
void point_scale(const scale_params_t &params, point_t &point);
void point_rotate(const rotate_params_t &params, point_t &point);

#endif // POINT_H
