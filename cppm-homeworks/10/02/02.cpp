/**
 * @brief Задача 2. Проект посложнее
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/10/02
 */
#include <windows.h>

#include <iostream>
#include <string>

 /// группа библиотек классов
#include "Figure.h"
#include "Triangle.h"
#include "RightAngTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "FRectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"

 /**
  * @brief Функция для вывода информации о фигуре
  */
void print_info(Figure* figure) {
    figure->print_info();
}

int main() {
    // SetConsoleCP(1251);
    // SetConsoleOutputCP(1251);

    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightAngTriangle rightAngledTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateralTriangle(30);
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    FRectangle fRectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhomb rhomb(30, 30, 40);

    print_info(&triangle);
    print_info(&rightAngledTriangle);
    print_info(&isoscelesTriangle);
    print_info(&equilateralTriangle);
    print_info(&quadrilateral);
    print_info(&fRectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhomb);

    return EXIT_SUCCESS;
}

