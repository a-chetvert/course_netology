#include "RightAngTriangle.h"
#include "ExceptionFigure.h"

//#define ADD_CHECK 

RightAngTriangle::RightAngTriangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, false) {
    name = "Прямоугольный треугольник";

    if (check()) {
        std::cout << get_name() << " (стороны " << get_a() << ", " << get_b() << ", " << get_c() << "; углы "
            << get_A() << ", " << get_B() << ", " << get_C() << ") создан" << std::endl;
    }
    else {
        throw ExceptionFigure("угол C не равен 90");
    }

#ifdef ADD_CHECK
    if (Triangle::check()) {
        throw ExceptionFigure("сумма углов не равна 180");
    }
#endif
}

/**
 * @brief Переопределение виртального метода для проверки правильности
 *
 * @return true правильно
 * @return false неправильно
 */
bool RightAngTriangle::check() const {
    if (C == 90)
        return true;
    else 
        return false;
}
