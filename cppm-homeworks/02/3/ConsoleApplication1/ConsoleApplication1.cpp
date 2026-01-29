/**
 * @brief Задача 3. Вывод структуры
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/02/03
 */
#include <string>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

struct adress {
    std::string city;
    std::string street;
    int house;
    int flat;
    int index;
};

void printAdress(struct adress& printAdress);
std::string utf8To1251(const std::string& utf8Str);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    struct adress firstAdr { utf8To1251("Москва"), utf8To1251("Арбат"), 12, 8, 123456 },
                  secondAdr{ utf8To1251("Ижевск"), utf8To1251("Пушкина"), 59, 143, 953769 };
    
    printAdress(firstAdr);
    printAdress(secondAdr);

    return EXIT_SUCCESS;
}

/**
 * @brief Выводит информацию об адресе
 *
 * @param[in] printAdress Ссылка на структуру адреса для вывода
 */
void printAdress(struct adress& printAdress) {
    std::string label1 = utf8To1251("Город: ");
    std::string label2 = utf8To1251("Улица: ");
    std::string label3 = utf8To1251("Номер дома: ");
    std::string label4 = utf8To1251("Номер квартиры: ");
    std::string label5 = utf8To1251("Индекс: ");
    
    std::cout << label1 << printAdress.city << std::endl;
    std::cout << label2 << printAdress.street << std::endl;
    std::cout << label3 << printAdress.house << std::endl;
    std::cout << label4 << printAdress.flat << std::endl;
    std::cout << label5 << printAdress.index << std::endl;
    std::cout << "\n";
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
    WideCharToMultiByte(1251, 0, wstr.data(), -1, str1251.data(), size, NULL, NULL);

    return std::string(str1251.data(), size - 1);
}