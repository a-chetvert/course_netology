#pragma once
#include "Figure.h"

/**
 * @brief класс четырёхугольника
 */
class Quadrilateral : public Figure {
    const int a, b, c, d;
    ;                      ///< стороны фигуры
    const int A, B, C, D;  ///< углы

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
        : Figure("Четырёхугольник"),
        a(a),
        b(b),
        c(c),
        d(d),
        A(A),
        B(B),
        C(C),
        D(D) {
    };
    void print_info() const override;
    int get_a() const;
    int get_b() const;
    int get_c() const;
    int get_d() const;
    int get_A() const;
    int get_B() const;
    int get_C() const;
    int get_D() const;
};

