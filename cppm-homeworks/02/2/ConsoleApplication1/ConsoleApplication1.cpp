/**
 * @brief Задача 2. Счета
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/02/02
 */
#include <iostream>
#include <string> // Для std::wstring и std::getline
#include <windows.h>
#include <io.h>
#include <fcntl.h>

/**
* @brief структура для хранения информации о банковском счёте
*/
struct account {
    int accountNumber;
    std::wstring ownerSName;
    float amount;
};

void changeAmount(account& account_, float newAmount);
void printAccountData(struct account& acc_);

int main() {
    struct account newAccount { 0, L"TEST", 1.23 };
    float newAmount{ 0 };

    // Установка режима для Unicode
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    std::wcout << L"Введите номер счёта: ";
    std::wcin >> newAccount.accountNumber;
    std::wcin.ignore();

    std::wcout << L"Введите имя владельца: ";
    std::getline(std::wcin, newAccount.ownerSName);  // Используем wcin для wstring

    
    std::wcout << L"Введите баланс: ";
    std::wcin >> newAccount.amount;

    std::wcout << L"Введите новый баланс: ";
    std::wcin >> newAmount;

    changeAmount(newAccount, newAmount);

    printAccountData(newAccount);

    return EXIT_SUCCESS;
}

/**
 * @brief Изменяет баланс банковского счета
 *
 * @param[in,out] account_ Ссылка на структуру банковского счета, который нужно изменить
 * @param[in] newAmount Новое значение баланса 
 */
void changeAmount(account& account_, float newAmount) {
    account_.amount = newAmount;
}

/**
 * @brief Выводит информацию о банковском счете в консоль
 * 
 * @param[in] acc_ Константная ссылка на структуру банковского счета для вывода *
 */
void printAccountData(struct account& acc_) {
    std::wcout << L"Ваш счёт: " << acc_.ownerSName;
    std::wcout << ", " << acc_.accountNumber << ", " << acc_.amount;
}
