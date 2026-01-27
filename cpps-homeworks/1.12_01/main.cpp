/**
 * @brief Задача 1. Вывод файла
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.12/01
 */

#include <iostream>
#include <fstream>

int main() {
    std::string s;
    std::ifstream fin("in.txt");
    if(fin.is_open())
    { 
        while(!(fin >> s).eof())
        {
            std::cout << s << std::endl;
        }
        fin.close();
    }
    else
    {
    std::cout << "Не получилось открыть файл!" << std::endl;
    }
        
    return EXIT_SUCCESS;
}
