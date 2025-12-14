/**
 * @brief ¬вод и вывод числа
 */
#include <Windows.h>
#include <iostream>

using namespace std;

int main() {
  char string[20];

  SetConsoleCP(1251);         // установка кодовой страницы win-cp 1251 в поток ввода
  SetConsoleOutputCP(1251);   // установка кодовой страницы win-cp 1251 в поток
                              // вывода char string[20];
  cout << "¬ведите число:" << endl;  // вывод строки

  cin >> string;  // вводим строку, использу€  ириллицу
  cout << "¬ы ввели:\n" << string << endl;  // вывод строки

  return 0;
}
