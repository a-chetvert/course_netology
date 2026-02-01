/**
 * @brief Задача 1. Фигуры. Количество сторон
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/05/01
 */
#include <windows.h>
#include <iostream>

class Figure {
protected:
    int sidesCount;

public:
    int get_sides_count();
    Figure(int sidesCount = 0);
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3) {};
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4) {};
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure newFigure;
    Triangle newTriangle;
    Quadrangle newQuadrangle;

    std::cout << "Количество сторон:" << std::endl;
    std::cout << "Фигура: ";
    std::cout << newFigure.get_sides_count() << std::endl;
    std::cout << "Треугольник: ";
    std::cout << newTriangle.get_sides_count() << std::endl;
    std::cout << "Четырёхугольник: ";
    std::cout << newQuadrangle.get_sides_count() << std::endl;

    return EXIT_SUCCESS;
}

Figure::Figure(int sidesCount) {
    this->sidesCount = sidesCount;
}

int Figure::get_sides_count() {
    return sidesCount;
}
