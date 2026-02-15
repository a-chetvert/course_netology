#pragma once
#include "Triangle.h"
#include "Figure.h"

/**
 * @brief класс равностороннего треугольника
 */
class EquilateralTriangle : public Triangle {
protected:
    stateCheck checkEqu() const;
public:
    EquilateralTriangle(int a, int b, int c, int A, int B, int C);
};