#pragma once
#include "Figure.h"

/**
 * @brief класс четырёхугольника
 */
class Quadrilateral : public Figure {
protected:
    const int a, b, c, d;   ///< стороны фигуры
    const int A, B, C, D;  ///< углы
    bool check() const override;

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, bool doCheck);
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
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

