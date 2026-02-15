#pragma once
#include "Figure.h"

/**
 * @brief класс треугольника
 */
class Triangle : public Figure {
protected:
    const int a, b, c;  ///< стороны фигуры
    const int A, B, C;  ///< углы
    bool check() const override; 

public:
    Triangle(int a, int b, int c, int A, int B, int C, bool doCheck);
    Triangle(int a, int b, int c, int A, int B, int C);
    void print_info() const override;
    int get_a() const;
    int get_b() const;
    int get_c() const;
    int get_A() const;
    int get_B() const;
    int get_C() const;
};

