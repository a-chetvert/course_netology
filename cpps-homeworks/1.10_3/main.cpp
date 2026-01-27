/**
 * @brief Задача 3. Динамическая таблица умножения
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.10/03
 */

#include <iostream>

using namespace std;

int** create_two_dim_array(int rows, int cols);
void fill_two_dim_array(int** arr, int rows, int cols);
void print_two_dim_array(int** arr, int rows, int cols);
void delete_two_dim_array(int** arr, int rows, int cols);

int main() {
    
    int numElements{0}, numRow{0}, numCols{0}, **dim_array{nullptr};
    
    cout << "Введите количество строк: ";
    cin >> numRow;

    cout << "Введите количество столбцов: ";
    cin >> numCols;

    dim_array = create_two_dim_array(numRow, numCols);

    cout << "Таблица умножения:" << endl;

    fill_two_dim_array(dim_array, numRow, numCols);
    print_two_dim_array(dim_array, numRow, numCols);
    delete_two_dim_array(dim_array, numRow, numCols);

    return EXIT_SUCCESS;
}

int** create_two_dim_array(int rows, int cols){
    int** two_dim_array{new int*[rows]{}};
    for(int i=0; i<rows; i++){
        two_dim_array[i] = new int[cols]{};
    }
    return two_dim_array;
}

void fill_two_dim_array(int **dim_array, int rows, int cols){
    unsigned row_num = 1;
    for(int** p{dim_array}; p<dim_array+rows; p++){
        unsigned coll_num = 1;
        for (int* q{*p}; q < *p+cols; q++)
        {
            *q = row_num * coll_num++; 
        }
        row_num ++;
    }
}
void print_two_dim_array(int **dim_array, int rows, int cols){
    for(int** p{dim_array}; p<dim_array+rows; p++){
        for(int* p_in{*p}; p_in<*p+cols; p_in++){
            cout << *p_in << " ";
        }
        cout << endl;
    }
}

void delete_two_dim_array(int **dim_array, int rows, int cols){
    for (int i{0}; i<rows; i++){
        delete[] dim_array[i];
    }
    delete[] dim_array;
}
