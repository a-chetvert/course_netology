#include "Triangle.h"

void Triangle::print_info() const {
    std::cout << get_name() << ": " << std::endl;
    std::cout << "Стороны: a=" << get_a() << " b=" << get_b() << " c=" << get_c()
        << std::endl;
    std::cout << "Углы: A=" << get_A() << " B=" << get_B() << " C=" << get_C()
        << "\n"
        << std::endl;
}

int Triangle::get_a() const { return a; }
int Triangle::get_b() const { return b; }
int Triangle::get_c() const { return c; }
int Triangle::get_A() const { return A; }
int Triangle::get_B() const { return B; }
int Triangle::get_C() const { return C; }