/**
 * @brief Задача 1. Вывод пирамиды на массиве
 * @note  https://github.com/netology-code/algocpp-homeworks/tree/main/4/03
 */
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <vector>
#include "encConv.h"

void print_pyramid(int* arr, int arr_size);
void print_arr(int* arr, int arr_size);




void print_el(int* arr, int index);

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int arr1[]{1, 3, 6, 5, 9, 8 };
  int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
  int arr2[]{94, 67, 18, 44, 55, 12, 6, 42};
  int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
  int arr3[]{16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
  int arr3_size = sizeof(arr3) / sizeof(arr3[0]);

  print_arr(arr1, arr1_size);

  return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
/**
 * @brief вывод целочисленной пирамиды
 * @param arr массив
 * @param arr_size размер массива
 * @param actual_size фактический размер
 */
void print_pyramid(int* arr, int arr_size) {
  std::cout << utf8To1251("Пирамида:");

}
/**
 * @brief вывод исходного массива
 * @param arr массив
 * @param arr_size размер массива
 * @param actual_size фактический размер
 */
void print_arr(int* arr, int arr_size) {
  std::cout << utf8To1251("Исходный массив: ");
  for (int i = 0; i < arr_size; i++) {
    print_el(arr, i);
  }
  std::cout << "\n";
}
/**
 * @brief вывод переменной
 * @param arr массив
 * @param arr_size размер массива
 * @param index индекс
 */
void print_el(int* arr, int index) {
  std::cout<< *(arr + index) << " ";
}
