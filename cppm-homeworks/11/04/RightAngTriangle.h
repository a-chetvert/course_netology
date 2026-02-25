#pragma once
#include "LibApi.h"
#include "Triangle.h"
/**
 * @brief класс прямоугольного треугольника
 */
class FIG_API RightAngTriangle : public Triangle {
public:
    RightAngTriangle(int a, int b, int c, int A, int B);
};