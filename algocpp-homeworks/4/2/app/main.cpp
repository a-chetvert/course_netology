/**
 * @brief Задача 2. Добавление в изменяемый динамический массив
 * @note  https://github.com/netology-code/algocpp-homeworks/tree/main/4/02
 */
#include <iostream>

 /**
  * @brief Структура динамического массива
  */
struct DynArr {
  int actual_size{};
  int logical_size{};
  int* arr;
};

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
  std::cout << "Динамический массив:";
  for (int i = 0; i < logical_size; i++) {
    std::cout << " " << arr[i];
  }
  for (int i = logical_size; i < actual_size; i++) {
    std::cout << " _";
  }
}

void append_to_dynamic_array(int var_to_app, int* arr, int logical_size, int actual_size) {
  if (actual_size > logical_size) {
    arr[logical_size++] = var_to_app;
  }
  else if (actual_size == logical_size) {
    new int[actual_size * 2];

  }
}



int main() {
  system("chcp 65001");

  DynArr dynArr{ 0,0, nullptr };
    
  std::cout << "Введите фактичеcкий размер массива: ";
  std::cin >> dynArr.actual_size;
  std::cout << "Введите логический размер массива: ";
  std::cin >> dynArr.logical_size;

  if (dynArr.logical_size > dynArr.actual_size)
  {
    std::cout << "Ошибка!Логический размер массива не может превышать фактический!";
    return EXIT_FAILURE;
  }

  dynArr.arr = new int[dynArr.actual_size];
  
  for (int i = 0; i < dynArr.logical_size; i++) {
    std::cout << "Введите arr[" << i << "]: ";
    std::cin >> dynArr.arr[i];
  }

  print_dynamic_array(dynArr.arr, dynArr.logical_size, dynArr.actual_size);

  delete[] dynArr.arr;
    
  return EXIT_SUCCESS;
}