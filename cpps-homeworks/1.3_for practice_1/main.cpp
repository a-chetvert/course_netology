/**
 * @brief Задача на практику к главе 1.3
 * @note  напишите программу, которая создает строку на русском языке
 *  в виде массива байтов, используя кодировку CP1251, и выводит её на 
 *  экран и в файл. Убедитесь что текст в файле читаемый.
 * @warning Please, reopen with Cyrilic (Windows 1251)
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring> // Для strlen

//Печатаем детальную информацию по строке в консоль и в файл
void printDetailedCoutAndFile(const char* str, std::ofstream* file=0) {
    //выводим строку напрямую
    std::cout << "String: `" << str << "` length=" << strlen(str) << std::endl;
    //выводим в шестнадцатеричном виде
    int i = 0; //начинаем с первого символа
    while (str[i] != '\0') //пока не дошли до конца строки
    {
        int code = static_cast<unsigned char>(str[i]); //переводим в код символа char->int
        std::cout << std::hex << std::setw(2) << std::setfill('0') << code << ' ';
        i++;
    }
    std::cout << " (bytes=" << i<<")" << std::endl;
    if (file && file->is_open())
    {
        file->write(str, i);
        std::cout << "File written" << std::endl;
    }
}

int main() {
    char russian[] = "строка на русском";

    std::ofstream file("output.bin", std::ios::binary | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла\n";
        return 1;
    }
    printDetailedCoutAndFile(russian, &file);
    file.close();
    
    return 0;
}