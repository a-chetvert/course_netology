/**
 * @brief Задача 1. Месяцы
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/02/01
 */
#include <iostream>
#include <locale>
#include <windows.h>
/**
* @brief структура для хранения информации о банковском счёте
*/
struct account {
    int accountNumber;
    std::string ownerSName;
    float amount;
};

void printAccountData(struct account &acc_) {
    std::cout << "Ваш счёт: " << acc_.ownerSName << ", " << acc_.accountNumber << ", " << acc_.amount;
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    int input{0};
    const int endInput = 0;
    struct account newAccount {123, "asd", 3.4 };


    return 0;
}