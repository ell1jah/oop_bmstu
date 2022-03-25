#ifndef CMD_MANAGER_H
#define CMD_MANAGER_H

#include "errors.h"
#include "model.h"

enum cmd_type
{
    LOAD,
    DRAW,
    SCALE,
    ROTATE,
    MOVE,
    FREE
};

using cmd_type_t = enum cmd_type;

struct cmd
{
    cmd_type_t type;

    union
    {
        fname_t fname;
        canvas_t canvas;
        scale_params_t scale_params;
        rotate_params_t rotate_params;
        move_params_t move_params;
    };
};

using cmd_t = struct cmd;

error_t cmd_manager(cmd_t cmd);

#endif // CMD_MANAGER_H
