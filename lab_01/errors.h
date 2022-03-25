#ifndef ERRORS_H
#define ERRORS_H

#include <QMessageBox>

enum error
{
    SUCCESS,
    FILE_ERROR,
    EMPTY_MODEL_ERROR,
    WRONG_CMD,
    READ_ERROR,
    MEMORY_ERROR
};

using error_t = enum error;

void error_manager(const error_t &code);

#endif // ERRORS_H
