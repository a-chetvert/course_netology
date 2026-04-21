/**
 * @brief Задача 1. Вывод изменяемого динамического массива
 * @note  https://github.com/netology-code/algocpp-homeworks/tree/main/4/01
 */
#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {

}

int main() {
  system("chcp 65001");

  int actual_size{ 0 };
  int logical_size{ 0 };


  //int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
  //int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
  
  std::cout << "Введите фактичеcкий размер массива: ";
  std::cin >> actual_size;
  std::cout << "Введите логический размер массива: ";
  std::cin >> logical_size;

  
  return EXIT_SUCCESS;
}