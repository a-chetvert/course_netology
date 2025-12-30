/**
 * @brief Курсовой проект «Игра "Жизнь"»
 * @note  https://github.com/netology-code/cpps-diplom
 */

#include <iostream>
#include <fstream>

#define DEBUG
void print_two_dim_array(unsigned** arr, unsigned rows, unsigned cols);

void readState(unsigned** arr, unsigned &inRows, unsigned &inCols, unsigned &count){
    std::string s;
    std::ifstream fin("in.txt");
    if(fin.is_open())
    {
#ifdef DEBUG         
        std::cout << "file is open" << std::endl;
#endif        
        fin >> inRows;
        fin >> inCols;

#ifdef DEBUG         
    std::cout << "inRows " << inRows << std::endl;
    std::cout << "inCols " << inCols << std::endl;    
#endif        

        count = 1; // число элементов
        unsigned tmp{0};
        while(!fin.eof()){
            fin >> tmp;
            count++;
        }
        count /= 2;
#ifdef DEBUG         
    std::cout << "count " << count << std::endl;
#endif              
        fin.clear();   // сбрасываем флаг конца файла
        fin.seekg(0); // возвращаемся в начало файла      
        
        arr = new unsigned*[count]{0};
        for (unsigned i{}; i <= count; i++)
        {
            arr[i] = new unsigned[2]{};
        }

        unsigned i{0};
        while (i<=count)
        {
            fin >> arr[i][0];
            fin >> arr[i++][1];
        } 
#ifdef DEBUG                 
        print_two_dim_array(arr, count, 2);
#endif            
        fin.close();
    }
    else
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
    }
}

int main() {
    unsigned rows{0}, cols{0}, points{0};
    unsigned** localArr{nullptr};
    readState(localArr, rows, cols, points);
    std::cout << "Считанный массив " << std::endl;
    print_two_dim_array(localArr, points, 2);


    return EXIT_SUCCESS;
}

void print_two_dim_array(unsigned **dim_array, unsigned rows, unsigned cols){
    for(unsigned** p{dim_array}; p<dim_array+rows; p++){
        for(unsigned* p_in{*p}; p_in<*p+cols; p_in++){
            std::cout << *p_in << " ";
        }
        std::cout << std::endl;
    }
}
