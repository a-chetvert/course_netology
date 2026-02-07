/**
 * @brief Задача 1. Препроцессорные директивы
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/07/01
 */
#include <iostream>

/// @brief варианты режимов
#define MODE_TEST 0
#define MODE_COMBAT 1
#define MODE_OTHER 2

/// @brief выбор режима
#define MODE MODE_TEST

// если MODE не определен
#ifndef MODE 
#error Macro MODE required 
#endif 

// определение функции для боевого режима
#if MODE == MODE_COMBAT
int add(int x, int y) {
    return x + y;
}
#endif 

int main() {
#if MODE == MODE_TEST
    std::cout << "Работаю в режиме тренировки" << std::endl;
#elif MODE == MODE_COMBAT
    int x{ 0 }, y{ 0 };
    std::cout << "Работаю в боевом режиме" << std::endl;
    std::cout << "Введите число 1: ";
    std::cin >> x;
    std::cout << "Введите число 2: ";
    std::cin >> y;
    std::cout << "Результат сложения: " << add(x, y) << std::endl;
#else
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
#endif 

    return EXIT_SUCCESS;
}
