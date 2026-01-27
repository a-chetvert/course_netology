/**
 * @brief Задача 1. Ввод массива с консоли
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.10/01
 */

#include <iostream>

using namespace std;

int main() {
    int numElements{0};
    
    cout << "Введите размер массива: ";
    cin >> numElements;

    int *dynamicArray = new int [numElements] ;

    for (size_t i = 0; i < numElements; i++)
    {
        cout << "arr[" << i << "] = ";
        cin >> dynamicArray[i];
    }

    cout << "Введённый массив: ";

    for (size_t i = 0; i < numElements; i++)
    {
        cout << dynamicArray[i] << " ";
    }
    
    delete [] dynamicArray;

    return EXIT_SUCCESS;
}
