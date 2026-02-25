#pragma once
#include "LibApi.h"
#include "Triangle.h"
/**
 * @brief класс равнобедренного треугольника
 */
class FIG_API IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B);
};

