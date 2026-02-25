#include "FRectangle.h"

FRectangle::FRectangle(int a, int b)
    : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {
    name = "Прямоугольник";
}