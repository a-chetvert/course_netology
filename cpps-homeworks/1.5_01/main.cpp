/**
 * @brief Задача 1. Вывод массива на экран
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.5/01
 */
#include <iostream>

using namespace std;

int main() {
  int num[]{123, 87, 42, 15, 99, 64, 31, 78, 53, 6};
  int size = sizeof(num) / sizeof(num[0]);
  for(int i = 0; i < size; i++){
    cout << num[i];
    if (i != size-1) 
      cout << ", ";
  }
  
  return EXIT_SUCCESS;
}
