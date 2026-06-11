/**
 * @brief Задача 1
 * @note  https://github.com/netology-code/cppl-homeworks/tree/main/02/01
 */

#include <iostream>

struct point {
  double m_x;
  double m_y;
  point(double x, double y) {
    m_x = x;
    m_y = y;
  }
};

void print_point(const point& point_object) {
  std::cout << "x:" << point_object.m_x << ", y: ";
  std::cout << point_object.m_y << std::endl;
}

int main() {
  int i;
  for (i = 0; i < 5; i++) {
    point my_point(i, 2 * i);
    print_point(my_point);
  }
  return 0;
}