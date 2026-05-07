/**
 * @brief Задача 1. Наивная хэш-функция для строки
 * @note  https://github.com/netology-code/algocpp-homeworks/blob/main/6/01
 */
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <vector>

int simple_string_hash(const std::string& strToHash);
std::string utf8To1251(const std::string& utf8Str);

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  std::string str;
  do {
    std::cout << utf8To1251("Введите строку: ");
    getline(std::cin, str);
    std::cout << utf8To1251("Наивный хэш строки ");
    std::cout << str << " = " << simple_string_hash(str) << "\n";
  } while (str != "exit");

  return EXIT_SUCCESS;
}

/**
 * @brief рассчитывает хэш для строки с помощью наивного алгоритма.
 * @param strToHash строка по которой вычисляется хэш
 * @return хэш
 */
int simple_string_hash(const std::string& strToHash) {
  int sum{ 0 };
  for (int i = 0; i < strToHash.size(); i++) {
    sum += static_cast<int>(strToHash[i]);
  }
  return sum;
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
