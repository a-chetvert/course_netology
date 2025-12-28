/**
 * @brief Задача 3. Пользовательский массив в файл
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.12/03
 */

#include <iostream>
#include <fstream>

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

    std::ofstream fout ("out.txt");
    fout << numElements << endl;
    for(int i = numElements-1; i >= 0; i--){
        fout << dynamicArray[i] << " ";
    }
    fout.close();

    delete [] dynamicArray;

    return EXIT_SUCCESS;
}
