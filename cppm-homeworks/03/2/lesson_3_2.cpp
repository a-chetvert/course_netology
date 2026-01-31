/**
 * @brief Задача 2. Счётчик
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/03/02
 */
#include <windows.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Counter {
 private:
  int num;

 public:
  Counter() : num(1) {};
  Counter(int num);

  void increment();
  void decrement();
  void print();
};

void printEnterNum(int numberNum);
std::string utf8To1251(const std::string& utf8Str);
std::string cp1251ToUtf8(const std::string& cp1251Str);

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  std::string answer;
  std::string tmpAnswer;
  int tmpNum{0};
  char tmpSym{0};

  Counter newCounter;

  std::cout << utf8To1251(
      "Вы хотите указать начальное значение счётчика? Введите да или нет: ");
  std::cin >> answer;
  if (cp1251ToUtf8(answer) == "да") {
    std::cout << utf8To1251("Введите начальное значение счётчика: ");
    std::cin >> tmpNum;
    newCounter = Counter(tmpNum);
  } else {
    newCounter = Counter();
    newCounter.print();
  }

  while (tmpSym != 'x') {
    std::cout << utf8To1251("Введите команду ('+', '-', '=' или 'x'): ");
    std::cin >> tmpSym;
    switch (tmpSym) { 
        case '+': 
            newCounter.increment();
        break;
        case '-': 
            newCounter.decrement();
        break;
        case '=': 
            newCounter.print();
        break;
    }
  }
  std::cout << utf8To1251("До свидания!");
  return EXIT_SUCCESS;
}

void Counter::increment() { num++; }

void Counter::decrement() { num--; }

void Counter::print() { std::cout << num << std::endl; }

Counter::Counter(int num) { this->num = num; }

/**
 * @brief Приглащение к вводу числа
 *
 * param[in] numberNum номер вводимого числа
 */
void printEnterNum(int numberNum) {
  std::cout << utf8To1251("Введите num") << numberNum << ": ";
}

/**
 * @brief Конвертирует строку из кодировки UTF-8 в Windows-1251
 *
 * @param[in] utf8Str Строка в кодировке UTF-8 для конвертации
 * @return std::string Строка в кодировке Windows-1251
 * @retval Пустая строка В случае ошибки преобразования
 *
 * @details Функция выполняет двухэтапное преобразование кодировки:
 * 1. UTF-8 → UTF-16 (широкие символы)
 * 2. UTF-16 → Windows-1251
 */
std::string utf8To1251(const std::string& utf8Str) {
  int wsize = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);
  if (wsize == 0) return "";

  std::vector<wchar_t> wstr(wsize);
  MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, wstr.data(), wsize);

  int size = WideCharToMultiByte(1251, 0, wstr.data(), -1, NULL, 0, NULL, NULL);
  if (size == 0) return "";

  std::vector<char> str1251(size);
  WideCharToMultiByte(1251, 0, wstr.data(), -1, str1251.data(), size, NULL,
                      NULL);

  return std::string(str1251.data(), size - 1);
}

/**
 * @brief Конвертирует строку из кодировки Windows-1251 в UTF-8
 *
 * @param[in] cp1251Str Строка в кодировке Windows-1251 для конвертации
 * @return std::string Строка в кодировке UTF-8
 * @retval Пустая строка В случае ошибки преобразования
 *
 * @details Функция выполняет двухэтапное преобразование кодировки:
 * 1. Windows-1251 → UTF-16 (широкие символы)
 * 2. UTF-16 → UTF-8
 */
std::string cp1251ToUtf8(const std::string& cp1251Str) {
  // 1. Windows-1251 → UTF-16
  int wsize = MultiByteToWideChar(1251, 0, cp1251Str.c_str(), -1, NULL, 0);
  if (wsize == 0) return "";

  std::vector<wchar_t> wstr(wsize);
  MultiByteToWideChar(1251, 0, cp1251Str.c_str(), -1, wstr.data(), wsize);

  // 2. UTF-16 → UTF-8
  int size =
      WideCharToMultiByte(CP_UTF8, 0, wstr.data(), -1, NULL, 0, NULL, NULL);
  if (size == 0) return "";

  std::vector<char> utf8Str(size);
  WideCharToMultiByte(CP_UTF8, 0, wstr.data(), -1, utf8Str.data(), size, NULL,
                      NULL);

  return std::string(utf8Str.data(), size - 1);
}