#include "IsoscelesTriangle.h"
#include "ExceptionFigure.h"

stateCheck IsoscelesTriangle::checkIsos() const
{
    if (a == c && A == C)
        return stateCheck::allOk;
    else if (a != c)
        return stateCheck::sidesError;
    else if (A != C)
        return stateCheck::engError;
    else
        return stateCheck::allBad;
}

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int c, int A, int B, int C)
    : Triangle(a, b, c, A, B, C, false) {
    name = "Равнобедренный треугольник";

    switch (checkIsos())
    {
    case stateCheck::allOk:
            std::cout << get_name() << " (стороны " << get_a() << ", " << get_b() << ", " << get_c() << "; углы "
                << get_A() << ", " << get_B() << ", " << get_C() << ") создан" << std::endl;
        break;
    case stateCheck::sidesError:
            throw ExceptionFigure("стороны a и c не равны");
        break;
    case stateCheck::engError:
            throw ExceptionFigure("углы A и C не равны");
        break;
    case stateCheck::allBad:
            throw ExceptionFigure("и стороны a и c не равны, и углы A и C не равны");
        break;
    default:
        break;
    }
}