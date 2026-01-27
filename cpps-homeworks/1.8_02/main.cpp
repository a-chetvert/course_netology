/**
 * @brief Задача 2. Одинаковые, но разные функции
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.8/02
 */
#include <iostream>

namespace add
{
  int calc(int x, int y){
    return x + y;
  }
}

namespace sub
{
  int calc(int x, int y){
    return x - y;
  }
}

namespace mult
{
  int calc(int x, int y){
    return x * y;
  }
}

namespace div_
{
  int calc(int x, int y){
    return x / y;
  }
}

int main(int argc, char** argv)
{
  int x{6}, y{9};
  std::cout << "x = " << x << ", y = " << y << std::endl;
  std::cout << "Сложение: " << add::calc(x, y) << std::endl;
  std::cout << "Вычитание: " << sub::calc(x, y) << std::endl;
  std::cout << "Умножение: " << mult::calc(x, y) << std::endl;
  std::cout << "Деление: " << div_::calc(x, y);

  return EXIT_SUCCESS;
}
