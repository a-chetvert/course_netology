#include "counter.h"
#include <iostream>

void Counter::increment() { num++; }

void Counter::decrement() { num--; }

void Counter::print() const { std::cout << num << std::endl; }

Counter::Counter(int num) { this->num = num; }