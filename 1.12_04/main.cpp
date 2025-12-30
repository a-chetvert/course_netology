/**
 * @brief Задача 4. Считывание двумерного массива из файла
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.12/04
 */

#include <iostream>
#include <fstream>

int** create_two_dim_array(int rows, int cols);
void revert_print_two_dim_array(int** arr, int rows, int cols);

int main() {
    int numRow{0}, numCols{0};
    int** arrFromFile{nullptr};

    std::string s;
    std::ifstream fin("in.txt");
    if(fin.is_open())
    {
        fin >> numRow;
        fin >> numCols;
        
        arrFromFile = create_two_dim_array(numRow, numCols);
        
        for(int i = 0; i<numRow; i++){
            for (int j = 0; j < numCols; j++)
            {
                fin >> arrFromFile[i][j];
            }
            
        }
        fin.close();
    }
    else
    {
    std::cout << "Не получилось открыть файл!" << std::endl;
    }

    revert_print_two_dim_array(arrFromFile, numRow, numCols);
    
    for(int i = 0; i<numRow; i++){
        delete [] arrFromFile[i];
    }
    delete [] arrFromFile;
    return EXIT_SUCCESS;
}

int** create_two_dim_array(int rows, int cols){
    int** two_dim_array{new int*[rows]{}};
    for(int i=0; i<rows; i++){
        two_dim_array[i] = new int[cols]{};
    }
    return two_dim_array;
}

void revert_print_two_dim_array(int **dim_array, int rows, int cols){
    for(int** p{dim_array}; p<dim_array+rows; p++){
        for(int* p_in{*p+cols-1}; p_in>=*p; p_in--){
            std::cout << *p_in << " ";
        }
        std::cout << std::endl;
    }
}
