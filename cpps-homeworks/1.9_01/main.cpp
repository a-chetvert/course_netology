/**
 * @brief Задача 1. Вывод массива
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.9/01
 */
#include <iostream>

void printArray(int* arr, unsigned int numElements){
  for(int* p = arr; p < (arr + numElements); p++){
    std::cout << *p << " ";
  }
  std::cout << std::endl;
}

int main(int argc, char** argv)
{
  int x{6}, y{9};
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  unsigned int size1 = sizeof(array1) / sizeof(array1[0]);
  
  printArray(array1, size1);

  int array2[] = {6, 5, 4, 8};
  unsigned int size2 = sizeof(array2) / sizeof(array2[0]);
    
  printArray(array2, size2);

  int array3[] = {1, 4, 3, 7, 5};
  unsigned int size3 = sizeof(array3) / sizeof(array3[0]);
    
  printArray(array3, size3);

  return EXIT_SUCCESS;
}
