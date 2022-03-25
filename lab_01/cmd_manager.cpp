#include "cmd_manager.h"

error_t cmd_manager(cmd_t cmd)
{
    static model_t model;
    error_t rc = SUCCESS;

    switch (cmd.type)
    {
        case LOAD:
            rc = model_load(model, cmd.fname);
            break;
        case DRAW:
            rc = model_draw(model, cmd.canvas);
            break;
        case SCALE:
            rc = model_scale(model, cmd.scale_params);
            break;
        case ROTATE:
            rc = model_rotate(model, cmd.rotate_params);
            break;
        case MOVE:
            rc = model_move(model, cmd.move_params);
            break;
        case FREE:
            model_free(model);
            break;
        default:
            rc = WRONG_CMD;
    }

    return rc;
}
