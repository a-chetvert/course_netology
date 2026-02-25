#pragma once
#include "LibApi.h"
#include "Figure.h"

/**
 * @brief класс треугольника
 */
class FIG_API Triangle : public Figure {
    const int a, b, c;  ///< стороны фигуры
    const int A, B, C;  ///< углы
public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : Figure("Треугольник"), a(a), b(b), c(c), A(A), B(B), C(C) {
    };
    void print_info() const override;
    int get_a() const;
    int get_b() const;
    int get_c() const;
    int get_A() const;
    int get_B() const;
    int get_C() const;
};

