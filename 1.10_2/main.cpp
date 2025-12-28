/**
 * @brief Задача 2. Создатель массивов
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.10/02
 */

#include <iostream>

using namespace std;

double *create_array(int size){
    double *newArr = new double [size]();
    return newArr;
}

int main() {
    
    int numElements{0};
    
    cout << "Введите размер массива: ";
    cin >> numElements;

    double *double_array = create_array(numElements);
    
    cout << "Массив: ";

    for (size_t i = 0; i < numElements; i++)
    {
        cout << double_array[i] << " ";
    }
    
    delete [] double_array;

    return EXIT_SUCCESS;
}
