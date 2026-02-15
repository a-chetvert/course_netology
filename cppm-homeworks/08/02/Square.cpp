#include "Square.h"
#include "ExceptionFigure.h"

Square::Square(int a, int b, int c, int d, int A, int B, int C, int D)
    : Quadrilateral(a, b, c, d, A, B, C, D, false) {
    name = "Квадрат";

    switch (checkSquare())
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
        throw ExceptionFigure("углы не равны 90");
        break;
    case stateCheck::allBad:
        throw ExceptionFigure("и стороны не равны, и углы не 90");
        break;
    default:
        break;
    }
}

stateCheck Square::checkSquare() const
{
    if (a == b && b == c && c == d && A == 90 && B == 90 && C == 90 && D == 90)
        return stateCheck::allOk;
    else if (a != b || b != c || c != d)
        return stateCheck::sidesError;
    else if (A != 90 || B != 90 && C != 90 && D != 90)
        return stateCheck::engError;
    else
        return stateCheck::allBad;
}
