/**
 * @brief Задача 2. Динамическая библиотека
 * @note  https://github.com/netology-code/cppm-homeworks/blob/main/11/02
 */

#include <iostream>
#include "frstDLL\frstDLL.h"
#include <windows.h> 

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Leaver greeter;
    std::string tmp;
    std::cout << utf8To1251("Введите имя: ");
    std::cin >> tmp;
    greeter.leave(tmp);
}
