/**
 * @brief Задача 1. Математические функции
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/06/01
 */

#include <iostream>

#include "calculator.h"

int main() {
  Calculator newCalc;
  int x{0}, y{0}, numOperation{0};
  std::cout << "Введите первое число: ";
  std::cin >> x;
  std::cout << "Введите первое число: ";
  std::cin >> y;
  std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 "
               "- деление, 5 - возведение в степень): ";
  std::cin >> numOperation;

  switch (numOperation) {
    case 1:
      std::cout << x;
      std::cout << " плюс ";
      std::cout << y;
      std::cout << " = ";
      std::cout << newCalc.addition(x, y);
      break;
    case 2:
      std::cout << x;
      std::cout << " минус ";
      std::cout << y;
      std::cout << " = ";
      std::cout << newCalc.division(x, y);
      break;
    case 3:
      std::cout << x;
      std::cout << " умножить на ";
      std::cout << y;
      std::cout << " = ";
      std::cout << newCalc.multiplication(x, y);
      break;
    case 4:
      std::cout << x;
      std::cout << " разделить на ";
      std::cout << y;
      std::cout << " = ";
      std::cout << newCalc.division(x, y);
      break;
    case 5:
      std::cout << x;
      std::cout << " в степени ";
      std::cout << y;
      std::cout << " = ";
      std::cout << newCalc.exponentiation(x, y);
      break;

    default:
      break;
  }

}
