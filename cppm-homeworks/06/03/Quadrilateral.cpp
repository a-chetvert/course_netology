#include "Quadrilateral.h"

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