/**
 * @brief Задача 3. Упрощённый алгоритм Рабина-Карпа
 * @note  https://github.com/netology-code/algocpp-homeworks/blob/main/6/03
 */
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <vector>
#include <cmath>

int simple_string_hash(const std::string& strToHash);
std::string utf8To1251(const std::string& utf8Str);

/**
 * @brief  находит в предоставленной строке заданную подстроку с помощью упрощённого алгоритма Рабина-Карпа
 * @param text строка, в которой ищется фрагмент phrase
 * @param phrase фрагмент, которы требуется найти
 */
int find_substring_light_rabin_karp(const std::string& text, const std::string& phrase) {
  int p_hash = simple_string_hash(phrase);
  int p_size = phrase.size();
  int h_hash{ 0 };
    for (int i = 0; i <= text.size() - p_size; i++) {
    if (i == 0)
      h_hash = simple_string_hash(text.substr(0, p_size));
    else {
      h_hash -= static_cast<int>(text[i - 1]);
      h_hash += static_cast<int>(text[i + p_size - 1]);
    }
    if (h_hash == p_hash) {
      bool match{ true };
      for (int j=0; j<p_size; j++) 
        if (text[i + j] != phrase[j]) {
          match = false;
          break;
        }
      if(match)
        return i;
    }
  }
  return -1;
};

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  std::string txt;
  std::cout << utf8To1251("Введите строку, в которой будет осуществляться поиск: ");
  while (true) {
    getline(std::cin, txt);
    if (txt.empty()) {
      std::cout << utf8To1251("Строка не может быть пустой! Введите другую строку: ");
    }
    else if (txt.size() < 2) {
      std::cout << utf8To1251("!Слишком короткая строка! Введите другую строку: ");
    }
    else break;
  }

  std::string str;
  do {
    int search_result{ 0 };
    std::cout << utf8To1251("Введите подстроку, которую нужно найти: ");
    while (true) {
      getline(std::cin, str);
      if (str.empty()) {
        std::cout << utf8To1251("Подстрока не может быть пустой! Введите другую подстроку: ");
      }
      else if (str.size() > txt.size() && str == "exit") {
        std::cout << utf8To1251("Подстрока exit не найдена") << "\n";
        return EXIT_SUCCESS;
      }
      else if (str.size() > txt.size()) {
        std::cout << utf8To1251("Подстрока больше строки! Введите другую подстроку: ");
      }
      else break;
    }
    search_result = find_substring_light_rabin_karp(txt, str);
    if (search_result >= 0) {
      std::cout << utf8To1251("Подстрока ") << str;
      std::cout << utf8To1251(" найдена по индексу ") << search_result << "\n";
    }
    else {
      std::cout << utf8To1251("Подстрока ") << str;
      std::cout << utf8To1251(" не найдена") << "\n";
    }
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
