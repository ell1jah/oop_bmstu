#include "errors.h"

void error_manager(const error_t &code)
{
    switch (code)
    {
        case FILE_ERROR:
            QMessageBox::critical(NULL, "Ошибка", "При открытии файла произошла ошибка.");
            break;
        case MEMORY_ERROR:
            QMessageBox::critical(NULL, "Ошибка", "При выделении памяти произошла ошибка.");
            break;
        case READ_ERROR:
            QMessageBox::critical(NULL, "Ошибка", "При чтении файла произошла ошибка.");
            break;
        case EMPTY_MODEL_ERROR:
            QMessageBox::critical(NULL, "Ошибка", "Фигура не загружена.");
            break;
        default:
            QMessageBox::critical(NULL, "Ошибка", "Неизвестная комманда.");
    }
}
