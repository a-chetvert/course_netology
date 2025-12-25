/**
 * @brief Задача 1. Приветствие
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.11/01
 */
#include <iostream>
#include <cstring>
#include <Windows.h>

using namespace std;

int main(int argc, char** argv)
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  string name, surname;
  cout << "Введите имя: ";
  cin >> name;
  cout << "Введите фамилию: ";
  cin >> surname;
  cout << "Здравствуйте, " << name << " " << surname << "!";

  return EXIT_SUCCESS;
}