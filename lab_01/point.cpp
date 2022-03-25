#include "point.h"

static void point_sum_coords(const point_t &point1, const point_t &point2, \
                             point_t &result)
{
    result.x = point1.x + point2.x;
    result.y = point1.y + point2.y;
    result.z = point1.z + point2.z;
}

static void point_sub_coords(const point_t &minued, const point_t &subtr, \
                             point_t &result)
{
    result.x = minued.x - subtr.x;
    result.y = minued.y - subtr.y;
    result.z = minued.z - subtr.z;
}

static double to_radians(double (*f)(double), const double &angle)
{
    return (*f)(angle * PI / 180);
}

error_t point_read(point_t &point, FILE *f)
{
    if (!f)
        return FILE_ERROR;

    error_t rc = SUCCESS;
    double x, y, z;

    if (fscanf(f, "%lf %lf %lf\n", &x, &y, &z) == POINT_COORDS_READ)
    {
        point.x = x;
        point.y = y;
        point.z = z;
    }
    else
        rc = READ_ERROR;

    return rc;
}

static double angles_get_ax(const angles_t &angles)
{
    return angles.ax;
}

static double angles_get_ay(const angles_t &angles)
{
    return angles.ay;
}

static double angles_get_az(const angles_t &angles)
{
    return angles.az;
}

void point_move(const move_params_t &params, point_t &point)
{
    point.x += params.dx;
    point.y += params.dy;
    point.z += params.dz;
}

static void point_scale_coords(const coefs_t &coefs, point_t &point)
{
    point.x *= coefs.kx;
    point.y *= coefs.ky;
    point.z *= coefs.kz;
}

void point_scale(const scale_params_t &params, point_t &point)
{
    point_sub_coords(point, params.about, point);
    point_scale_coords(params.coefs, point);
    point_sum_coords(point, params.about, point);
}

static void point_rotate_x(const double angle, point_t &point)
{
    double cos_radians = to_radians(cos, angle);
    double sin_radians = to_radians(sin, angle);
    double temp_y = point.y;

    point.y = point.y + cos_radians + point.z * sin_radians;
    point.z = -temp_y * sin_radians + point.z * cos_radians;
}

static void point_rotate_y(const double angle, point_t &point)
{
    double cos_radians = to_radians(cos, angle);
    double sin_radians = to_radians(sin, angle);
    double temp_x = point.x;

    point.x = point.x * cos_radians + point.z * sin_radians;
    point.z = -temp_x * sin_radians + point.z * cos_radians;
}

static void point_rotate_z(const double angle, point_t &point)
{
    double cos_radians = to_radians(cos, angle);
    double sin_radians = to_radians(sin, angle);
    double temp_x = point.x;

    point.x = point.x * cos_radians + point.y * sin_radians;
    point.y = -temp_x * sin_radians + point.y * cos_radians;
}

void point_rotate(const rotate_params_t &params, point_t &point)
{
    point_sub_coords(point, params.about, point);

    point_rotate_x(angles_get_ax(params.angles), point);
    point_rotate_y(angles_get_ay(params.angles), point);
    point_rotate_z(angles_get_az(params.angles), point);

    point_sum_coords(point, params.about, point);
}
