/**
 * @brief Задача 1. Приветствие
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.11/01
 */
#include <string>
#include <windows.h>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

// Конвертируем UTF-8 в Windows-1251
std::string utf8To1251(const std::string& utf8Str) {
    int wsize = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);
    if (wsize == 0) return "";
    
    std::vector<wchar_t> wstr(wsize);
    MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, wstr.data(), wsize);
    
    int size = WideCharToMultiByte(1251, 0, wstr.data(), -1, NULL, 0, NULL, NULL);
    if (size == 0) return "";
    
    std::vector<char> str1251(size);
    WideCharToMultiByte(1251, 0, wstr.data(), -1, str1251.data(), size, NULL, NULL);
    
    return std::string(str1251.data(), size - 1); // -1 для удаления нулевого терминатора
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    std::string lblGuess = utf8To1251("Угадайте слово: ");
    std::string lblNo = utf8To1251("Введите фамилию: ");
    std::string label3 = utf8To1251("Здравствуйте, ");
    std::string name{0},      ///< имя
                surname{0};   ///< фамилия
    


    std::cout << label1;
    std::cin >> name;
    std::cout << label2;
    std::cin >> surname;
    
    std::cout << label3 << name << " " << surname << "!";
    
    return EXIT_SUCCESS;
}