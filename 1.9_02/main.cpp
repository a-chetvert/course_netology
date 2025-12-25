/**
 * @brief Задача 2. Снова swap
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.9/02
 */
#include <iostream>

template <typename T> 
void swap(T* argA, T* argB){
  T tmp = *argA;
  *argA = *argB;
  *argB = tmp;
}

int main(int argc, char** argv)
{
  int a{5}, b{8};
  std::cout << "a = " << a << ", b = " << b << std::endl;
  swap(&a, &b);
  std::cout << "a = " << a << ", b = " << b << std::endl;

  return EXIT_SUCCESS;
}
