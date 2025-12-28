/**
 * @brief Задача 2. Чтение массива из файла
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.12/02
 */

#include <iostream>
#include <fstream>

void printRevertArr(unsigned* arr, int cols);

int main() {
    unsigned numElements{0};
    unsigned* fileArray{nullptr};
    std::string s;
    std::ifstream fin("in.txt");
    if(fin.is_open())
    {
        fin >> numElements;
        fileArray = new unsigned[numElements]{0};
        unsigned i{0};
        while(!(fin >> fileArray[i++]).eof());
        fin.close();
    }
    else
    {
    std::cout << "Не получилось открыть файл!" << std::endl;
    }
        
    printRevertArr(fileArray, numElements);
    delete [] fileArray;
    return EXIT_SUCCESS;
}

void printRevertArr(unsigned* arr, int cols){
    for(unsigned* p{arr+cols-1}; p>=arr; p--){
        std::cout << *p << " ";
    }
}
