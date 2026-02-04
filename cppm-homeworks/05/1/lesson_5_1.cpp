/**
 * @brief Задача 1. Фигуры. Количество сторон
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/05/01
 */
#include <windows.h>
#include <iostream>
#include <string>

class Figure {
protected:
    int sidesCount;     ///< число сторон
    std::string name;   ///< название фигуры

public:
    std::string get_name();
    int get_sides_count();
    Figure(int sidesCount = 0, std::string name = "Фигура");
};

class Triangle : public Figure {
public:
    Triangle() : Figure(3, "Треугольник") {};
};

class Quadrangle : public Figure {
public:
    Quadrangle() : Figure(4, "Четырёхугольник") {};
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Figure newFigure;
    Triangle newTriangle;
    Quadrangle newQuadrangle;

    std::cout << "Количество сторон:" << std::endl;
    std::cout << newFigure.get_name() << ": ";
    std::cout << newFigure.get_sides_count() << std::endl;
    std::cout << newTriangle.get_name() << ": ";
    std::cout << newTriangle.get_sides_count() << std::endl;
    std::cout << newQuadrangle.get_name() << ": ";
    std::cout << newQuadrangle.get_sides_count() << std::endl;

    return EXIT_SUCCESS;
}

Figure::Figure(int sidesCount, std::string name) {
    this->sidesCount = sidesCount;
    this->name = name;
}

std::string Figure::get_name(){
    return name;
}

int Figure::get_sides_count() {
    return sidesCount;
}
