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
  std::cout << "массив:";
  for (int i = 0; i < logical_size; i++) {
    std::cout << " " << arr[i];
  }
  for (int i = logical_size; i < actual_size; i++) {
    std::cout << " _";
  }
}

/**
 * @brief Добавляет элемент в конец динамического массив с расширением
 * @param var_to_app элемент для добавления
 * @param arr динамический массив
 * @param logical_size логический размер
 * @param actual_size фактический размер
 */
void append_to_dynamic_array(const int var_to_app, int*& arr, int& logical_size, int& actual_size) {
  if (logical_size < actual_size) {
    arr[logical_size] = var_to_app;
    logical_size++;
  }
  else if (actual_size == logical_size) {
    int new_actual_size = actual_size * 2;
    int* arrTmp = new int[new_actual_size];
    for (int i = 0; i < actual_size; i++) {
      arrTmp[i] = arr[i];
    }
    arrTmp[logical_size] = var_to_app;
    delete[] arr;
    arr = arrTmp;
    logical_size++;
    actual_size = new_actual_size;
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

  std::cout << "Динамический ";
  print_dynamic_array(dynArr.arr, dynArr.logical_size, dynArr.actual_size);

  int element_for_app{ 1 };
  while (element_for_app) {
    std::cout << "\nВведите элемент для добавления: ";
    std::cin >> element_for_app;
    if (element_for_app == 0) {
      break;
    }
    append_to_dynamic_array(element_for_app, dynArr.arr, dynArr.logical_size, dynArr.actual_size);
    std::cout << "Динамический ";
    print_dynamic_array(dynArr.arr, dynArr.logical_size, dynArr.actual_size);
  }

  std::cout << "Спасибо! Ваш ";
  print_dynamic_array(dynArr.arr, dynArr.logical_size, dynArr.actual_size);

  delete[] dynArr.arr;
    
  return EXIT_SUCCESS;
}