#include "Quadrilateral.h"
#include "ExceptionFigure.h"

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
    : Figure("Четырёхугольник"),
    a(a),
    b(b),
    c(c),
    d(d),
    A(A),
    B(B),
    C(C),
    D(D)
{
    if (check()) {
        std::cout << get_name() << " (стороны " << get_a() << ", " << get_b()
            << ", " << get_c() << ", " << get_d() << "; углы " << get_A() << ", " << get_B() 
            << ", " << get_C() << ", " << get_D() << ") создан" << std::endl;
    }
    else {
        throw ExceptionFigure("сумма углов не равна 180");
    }
}

bool Quadrilateral::check() const
{   
    if ((A + B + C + D) == 360)
        return true;
    else return false;
}

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, bool doCheck)
    : Figure("Четырёхугольник"),
    a(a),
    b(b),
    c(c),
    d(d),
    A(A),
    B(B),
    C(C),
    D(D) 
{
    if (doCheck) {
        if (check()) {
            std::cout << "Четырехугольник (стороны " << get_a() << ", " << get_b()
                << ", " << get_c() << ", " << get_d() << "; углы " << get_A() << ", " << get_B()
                << ", " << get_C() << ", " << get_D() << ") создан" << std::endl;
        }
        else {
            throw ExceptionFigure("сумма углов не равна 180");
        }
    }
}

void Quadrilateral::print_info() const {
    std::cout << get_name() << ": " << std::endl;
    std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c()
        << " d=" << get_d() << std::endl;
    std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C()
        << " D=" << get_D() << "\n"
        << std::endl;
}

int Quadrilateral::get_a() const { return a; }
int Quadrilateral::get_b() const { return b; }
int Quadrilateral::get_c() const { return c; }
int Quadrilateral::get_d() const { return d; }
int Quadrilateral::get_A() const { return A; }
int Quadrilateral::get_B() const { return B; }
int Quadrilateral::get_C() const { return C; }
int Quadrilateral::get_D() const { return D; }