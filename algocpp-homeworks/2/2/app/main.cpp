/**
 * @brief Задача 2. Ускоряем Фибоначчи
 * @note  https://github.com/netology-code/algocpp-homeworks/blob/main/2/02/readme.md
 */
#include <iostream>
#include <vector>

#define NOT_CALC  -1 ///< значение не вычислялось

/**
 * @brief Рекурсивное вычисление числа Фибоначчи
 * с использованием мемоизации.
 * @param num номер числа (от 0)
 * @param memo массив для мемоизации
 * @return число Фибоначчи
 */
int fib(int num, std::vector <int> &memo) {
  if (num <= 1) return num;
  if (memo[num] == NOT_CALC) {
    memo[num] = fib(num - 2, memo) + fib(num - 1, memo);
  }
  return memo[num];
}

/**
 * @brief Вычисление числа Фибоначчи
 * @param num номер числа (от 0)
 * @return значение числа Фибоначчи
 */
int fibonacciRecursive(int num) {

  std::vector <int> memo (num+1, NOT_CALC);

  return fib(num, memo);
}

int main() {
  int num{ 0 };
  std::cout << "Введите номер числа Фибонначи: ";
  std::cin >> num;

  std::cout << "Фибоначчи числа " << num << " - это ";
  std::cout << fibonacciRecursive(num);

  return EXIT_SUCCESS;
}