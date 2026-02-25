#include "Figure.h"

std::string Figure::get_name() const { return name; }

/**
 * @brief Функция для вывода информации о фигуре
 */
void print_info(Figure* figure) {
    figure->print_info();
}