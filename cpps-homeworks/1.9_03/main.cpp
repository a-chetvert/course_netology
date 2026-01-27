/**
 * @brief Задача 3. Переворот массива
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.9/03
 */
#include <iostream>

#define IS_MASS_EVEN 1

template <typename T> void swap(T* argA, T* argB);
void printArray(int* arr, unsigned int numElements);
void reverse(int * arr, unsigned int numElements);

int main(int argc, char** argv)
{
  int x{6}, y{9};

#if IS_MASS_EVEN
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8};
#else 
  int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
#endif

  unsigned int size1 = sizeof(array1) / sizeof(array1[0]);
  
  printArray(array1, size1);
  reverse(array1, size1);
  printArray(array1, size1);

  return EXIT_SUCCESS;
}

template <typename T> 
void swap(T* argA, T* argB){
  if(argA!=argB){
    T tmp = *argA;
    *argA = *argB;
    *argB = tmp;
  }
}

void printArray(int* arr, unsigned int numElements){
  for(int* p = arr; p < (arr + numElements); p++){
    std::cout << *p << " ";
  }
  std::cout << std::endl;
}

void reverse(int * arr, unsigned int numElements){
  int *pFromStart{arr}, *pFromEnd{arr+numElements-1};
    for(int i = 0; i<(numElements/2); i++){
      swap(pFromStart,pFromEnd);
      pFromStart++;
      pFromEnd--;
    }
}
