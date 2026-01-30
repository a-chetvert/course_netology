/**
 * @brief Задача 3. Вывод структуры
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/02/03
 */
#include <windows.h>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Calculator {
 public:
  double num1;
  double num2;

  // Конструктор по умолчанию
  Calculator() : num1(0), num2(0) {};
  double add();
  double multiply();
  double subtract_1_2();
  double subtract_2_1();
  double divide_1_2();
  double divide_2_1();
  /*
  */
  bool set_num1(double num1);
  bool set_num2(double num2);
};

void printEnterNum(int numberNum);
std::string utf8To1251(const std::string& utf8Str);

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  Calculator newCalc;
  double tmpNum[2]{
      0,
  };  ///< временное хранение данных вводимых чисел

  while (true) {
    printEnterNum(1);
    std::cin >> tmpNum[0];
    printEnterNum(2);
    std::cin >> tmpNum[1];

    // если оба числа не равны нулю
    // (функции возвр. true, если оба числа не ноль)
    if (newCalc.set_num1(tmpNum[0]) && newCalc.set_num2(tmpNum[1])) {
      std::cout << "num1 + num2 = " << newCalc.add() << std::endl;
      std::cout << "num1 - num2 = " << newCalc.subtract_2_1() << std::endl;
      std::cout << "num2 - num1 = " << newCalc.subtract_1_2() << std::endl;
      std::cout << "num1 * num2 = " << newCalc.multiply() << std::endl;
      std::cout << "num1 / num2 = " << newCalc.divide_1_2() << std::endl;
      std::cout << "num2 / num1 = " << newCalc.divide_2_1() << std::endl;
      
    } else {
      std::cout << utf8To1251("Неверный ввод!\n");
    }
  }
  return EXIT_SUCCESS;
}

double Calculator::add() { 
  return this->num1 + this->num2; 
}

double Calculator::multiply() { 
  return this->num1 * this->num2; 
}

double Calculator::subtract_1_2() { 
  return this->num2 - this->num1; 
}

double Calculator::subtract_2_1() { 
  return this->num1 - this->num2; 
}

double Calculator::divide_1_2() { 
  return this->num1 / this->num2;
}

double Calculator::divide_2_1() { 
  return this->num2 / this->num1; 
}

bool Calculator::set_num1(double num1) {
  if (num1 == 0)
    return false;
  else
    this->num1 = num1;
  return true;
}

bool Calculator::set_num2(double num2) {
  if (num2 == 0)
    return false;
  else
    this->num2 = num2;
  return true;
}

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