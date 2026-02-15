#pragma once
#include "Triangle.h"
/**
 * @brief класс прямоугольного треугольника
 */
class RightAngTriangle : public Triangle {
protected:
    bool check() const override;
public:
    RightAngTriangle(int a, int b, int c, int A, int B, int C);
};