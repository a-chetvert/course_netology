/**
 * @brief Задача 1. Месяцы
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/02/01
 */
#include <iostream>
#include <locale>
#include <windows.h>

enum class month {
    january = 1,
    february,
    march,
    april,
    may,
    june,
    july,
    august,
    september,
    october,
    november,
    december
};

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    int input{0};
    const int endInput = 0;

    while (true) {
        std::cout << "Введите номер месяца: ";
        // получаем от пользователя номер месяца
        std::cin >> input;

        if ((input > static_cast<int>(month::december))|| 
            (input < endInput))
        {
            std::cout << "Неправильный номер!" << std::endl;
            continue;
        }
        else if (input == endInput)
        {
            std::cout << "До свидания";
            break;
        }

        //  переводим в месяцы 
        month inputMonth = static_cast<month>(input);

        switch (static_cast<int>(inputMonth)) {
            case 1:
                std::cout << "Январь" << std::endl;
                break;
            case 2:
                std::cout << "Февраль" << std::endl;
                break;
            case 3:
                std::cout << "Март" << std::endl;
                break;
            case 4:
                std::cout << "Апрель" << std::endl;
                break;
            case 5:
                std::cout << "Май" << std::endl;
                break;
            case 6:
                std::cout << "Июнь" << std::endl;
                break;
            case 7:
                std::cout << "Июль" << std::endl;
                break;
            case 8:
                std::cout << "Август" << std::endl;
                break;
            case 9:
                std::cout << "Сентябрь" << std::endl;
                break;
            case 10:
                std::cout << "Октябрь" << std::endl;
                break;
            case 11:
                std::cout << "Ноябрь" << std::endl;
                break;
            case 12:
                std::cout << "Декабрь" << std::endl;
                break;
            default:
                std::cout << "Неправильный номер!" << std::endl;
        }
    }
    return 0;
}