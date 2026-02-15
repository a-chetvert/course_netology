#include "Triangle.h"
#include "ExceptionFigure.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    : Figure("Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C)
{
    if (check()) {
        std::cout << get_name() << " (стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C <<") создан" << std::endl;
    }
    else {
        throw ExceptionFigure("сумма углов не равна 180");
    }
};

Triangle::Triangle(int a, int b, int c, int A, int B, int C, bool doCheck)
    : Figure("Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C)
{
    if (doCheck) {
        if (check()) {
            std::cout << get_name() << " (стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C << ") создан" << std::endl;
        }
        else {
            throw ExceptionFigure("сумма углов не равна 180");
        }
    }
};

void Triangle::print_info() const {
    std::cout << get_name() << ": " << std::endl;
    std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c()
        << std::endl;
    std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C()
        << "\n"
        << std::endl;
}

/**
 * @brief Переопределение виртального метода для проверки правильности
 *
 * @return true правильно
 * @return false неправильно
 */
bool Triangle::check() const {
    // Проверяем сумму углов треугольника
    if ((A + B + C) == 180)
        return true;
    else return false;
}

int Triangle::get_a() const { return a; }
int Triangle::get_b() const { return b; }
int Triangle::get_c() const { return c; }
int Triangle::get_A() const { return A; }
int Triangle::get_B() const { return B; }
int Triangle::get_C() const { return C; }