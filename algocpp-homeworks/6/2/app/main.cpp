/**
 * @brief Задача 2. Настоящая хэш-функция для строки
 * @note  https://github.com/netology-code/algocpp-homeworks/blob/main/6/02
 */
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <vector>
#include <cmath>

bool isPrime(int n);
int real_string_hash(const std::string& str_to_hash, int p_num, int module);
std::string utf8To1251(const std::string& utf8Str);

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int p{ 0 }; /// простое число
  int n{ 0 }; /// модуль

  std::string str;

  std::cout << utf8To1251("Введите p: ");
  while (true) {
    std::cin >> p;
    if (isPrime(p))
      break;
    else
      std::cout << utf8To1251("Вы ввели составное число. \nВведите простое число p: ");
  }
  std::cout << utf8To1251("Введите n: ");
  std::cin >> n;
  std::cin.ignore();

  do {
    std::cout << utf8To1251("Введите строку: ");
    getline(std::cin, str);
    std::cout << utf8To1251("Хэш строки ");
    std::cout << str << " = " << real_string_hash(str, p, n) << "\n";
  } while (str != "exit");

  return EXIT_SUCCESS;
}

/**
 * @brief рассчитывает хэш для строки с помощью серьёзного алгоритма
 * @param str_to_hash  строка по которой вычисляется хэш
 * @param p_num основание полинома
 * @param module модуль для хэширования
 * @return хэш
 */
int real_string_hash(const std::string& str_to_hash, int p_num, int module) {
  uint64_t sum{ 0 };
  uint64_t simple_in_power{ 1 };
  for (int i = 0; i < str_to_hash.size(); i++) {
    sum += (static_cast<int>(str_to_hash[i]) * simple_in_power) % module;
    simple_in_power = (simple_in_power * p_num) % module;
    sum %= module;
  }
  return static_cast<int>(sum);
}

/**
 * @brief является ли число простым
 * @param n число
 * @return true == является
 */
bool isPrime(int n) {
  if (n < 2) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false; //все чётные составные

  int lim = static_cast<int>(std::sqrt(n));
  for (int d = 3; d <= lim; d += 2) {
    if (n % d == 0) return false;
  }
  return true;
}

/**
 * @brief Конвертация строки из кодировки UTF-8 в Windows-1251.
 * @details Необходима для корректного вывода кириллических символов в консоль Windows,
 * которая по умолчанию работает с кодировкой CP-1251.
 * @param utf8Str Исходная строка в кодировке UTF-8.
 * @return std::string Результирующая строка в кодировке Windows-1251.
 * В случае ошибки возвращает пустую строку.
 */
std::string utf8To1251(const std::string& utf8Str) {
  int wsize = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);
  if (wsize == 0) return "";

  std::vector<wchar_t> wstr(wsize);
  MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, wstr.data(), wsize);

  int size = WideCharToMultiByte(1251, 0, wstr.data(), -1, NULL, 0, NULL, NULL);
  if (size == 0) return "";

  std::vector<char> str1251(size);
  WideCharToMultiByte(1251, 0, wstr.data(), -1, str1251.data(), size, NULL, NULL);

  return std::string(str1251.data(), size - 1); // -1 для удаления нулевого терминатора
}
