#pragma once
#include "Triangle.h"
#include "Figure.h"

/**
 * @brief класс равнобедренного треугольника
 */
class IsoscelesTriangle : public Triangle {
protected:
    stateCheck checkIsos() const;
public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C);
};

