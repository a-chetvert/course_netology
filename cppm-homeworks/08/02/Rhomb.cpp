#include "Rhomb.h"
#include "ExceptionFigure.h"

Rhomb::Rhomb(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, false) {
    name = "Ромб";

    switch (checkRhomb())
    {
    case stateCheck::allOk:
        std::cout << get_name() << " (стороны " << get_a() << ", " << get_b()
            << ", " << get_c() << ", " << get_d() << "; углы " << get_A() << ", " << get_B()
            << ", " << get_C() << ", " << get_D() << ") создан" << std::endl;
        break;
    case stateCheck::sidesError:
        throw ExceptionFigure("стороны не равны");
        break;
    case stateCheck::engError:
        throw ExceptionFigure("углы попарно не равны");
        break;
    case stateCheck::allBad:
        throw ExceptionFigure("и стороны не равны, и углы попарно не равны");
        break;
    default:
        break;
    }
}

stateCheck Rhomb::checkRhomb() const
{
    if (a == b && b == c && c == d && A == C && B == D)
        return stateCheck::allOk;
    else if (a != c || b != d)
        return stateCheck::sidesError;
    else if (A != C || B != D)
        return stateCheck::engError;
    else
        return stateCheck::allBad;
}
