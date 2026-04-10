/**
 * @brief Задача 1. Снова числа Фибоначчи
 * @note  https://github.com/netology-code/algocpp-homeworks/blob/main/2/01/readme.md
 * 
 * Ответ!!!
 * По памяти O(n), по времени O(2^n)
 */
#include <iostream>

/**
 * @brief Рекурсивное вычисление числа Фибоначчи
 * @param num номер числа (от 0)
 * @return значение числа Фибоначчи
 */
int fibonacciRecursive(int num) {
  if (num == 0) return 0;
  if (num == 1) return 1;
  return (fibonacciRecursive(num - 1) + fibonacciRecursive(num - 2));
}

int main() {
  int num{ 0 };
  std::cout << "Введите номер числа Фибонначи: ";
  std::cin >> num;

  std::cout << "Фибоначчи числа " << num << " - это ";
  std::cout << fibonacciRecursive(num);

  return EXIT_SUCCESS;
}