/**
 * @brief Задача 1. Статическая библиотека
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/11/01
 */
#include <iostream>
#include "StaticLib\StaticLib.h"
#include <windows.h> 
#include <sstream>
#include <string>
#include <vector>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Greeter greeter;
    std::string tmp;
    std::cout << utf8To1251("Введите имя: ");
    std::cin >> tmp;
    greeter.greet(tmp);
}
