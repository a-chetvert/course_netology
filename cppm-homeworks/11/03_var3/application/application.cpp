/**
 * @brief Задача 3. Динамическая библиотека CMake
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/11/03
 */

#include "application.h"

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
