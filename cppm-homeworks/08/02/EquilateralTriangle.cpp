#include "EquilateralTriangle.h"
#include "ExceptionFigure.h"

stateCheck EquilateralTriangle::checkEqu() const
{
    if (a == b && b == c && A == B && B== C)
        return stateCheck::allOk;
    else if (a != b || a != c || b != c)
        return stateCheck::sidesError;
    else if (A != B || A != C || B != C)
        return stateCheck::engError;
    else
        return stateCheck::allBad;
}

EquilateralTriangle::EquilateralTriangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, false) {
    name = "Равносторонний треугольник";

    switch (checkEqu())
    {
    case stateCheck::allOk:
        std::cout << get_name() << " (стороны " << get_a() << ", " << get_b() << ", " << get_c() << "; углы "
            << get_A() << ", " << get_B() << ", " << get_C() << ") создан" << std::endl;
        break;
    case stateCheck::sidesError:
        throw ExceptionFigure("стороны не равны");
        break;
    case stateCheck::engError:
        throw ExceptionFigure("углы не равны");
        break;
    case stateCheck::allBad:
        throw ExceptionFigure("и стороны, и углы не равны");
        break;
    default:
        break;
    }
}
