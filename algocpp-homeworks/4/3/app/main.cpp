/**
 * @brief Задача 1. Вывод пирамиды на массиве
 * @note  https://github.com/netology-code/algocpp-homeworks/tree/main/5/01
 */
#include <iostream>
#include <windows.h>
#include "encConv.h"

void print_dynamic_array(int* arr, int logical_size, int actual_size);

/**
 * @brief Структура динамического массива
 */
struct DynArr {
  int actual_size{};
  int logical_size{};
  int* arr;
};

/**
 * @brief удаление головного элемента массива
 * @param arr массив
 * @param logical_size логический размер
 * @param actual_size фактический размер
 */
void remove_dynamic_array_head(int*& arr, int& logical_size, int& actual_size) {
  if (logical_size == 1) {
    delete[] arr;
    arr = nullptr;
    logical_size = 0;
    actual_size = 0;
  }
  else if ((logical_size - 1) > actual_size / 3) {
    for (int i = 0; i < logical_size - 1; i++)
      arr[i] = arr[i + 1];
    logical_size--;
  }
  else if ((logical_size - 1) <= actual_size / 3) {
    int tmpArrSize = logical_size - 1;
    int* tmpArr = new int[tmpArrSize];
    for (int i = 0; i < tmpArrSize; i++) {
      tmpArr[i] = arr[i + 1];
    }
    delete[] arr;
    arr = tmpArr;
    logical_size--;
    actual_size /= 3;
  }
}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  DynArr dynArr{ 0,0, nullptr };

  std::cout << utf8To1251("Введите фактичеcкий размер массива: ");
  std::cin >> dynArr.actual_size;
  std::cout << utf8To1251("Введите логический размер массива: ");
  std::cin >> dynArr.logical_size;

  if (dynArr.logical_size > dynArr.actual_size)
  {
    std::cout << utf8To1251("Ошибка!Логический размер массива не может превышать фактический!");
    return EXIT_FAILURE;
  }

  dynArr.arr = new int[dynArr.actual_size];

  for (int i = 0; i < dynArr.logical_size; i++) {
    std::cout << utf8To1251("Введите arr[") << i << "]: ";
    std::cin >> dynArr.arr[i];
  }

  std::cout << utf8To1251("Динамический ");
  print_dynamic_array(dynArr.arr, dynArr.logical_size, dynArr.actual_size);

  while (true) {
    std::string answer;
    std::cout << utf8To1251("\nУдалить первый элемент? ");
    std::cin.ignore(); // очистить буфер после предыдущего ввода чисел
    std::cin >> answer;
    if (answer == utf8To1251("да") || answer == utf8To1251("да ") || answer == utf8To1251("Да") || answer == ("Да ")) {
      if (dynArr.logical_size > 0 && dynArr.actual_size > 0) {
        remove_dynamic_array_head(dynArr.arr, dynArr.logical_size, dynArr.actual_size);
        std::cout << utf8To1251("Динамический ");
        if (dynArr.logical_size == 0)
          std::cout << utf8To1251("массив: _");
        else
          print_dynamic_array(dynArr.arr, dynArr.logical_size, dynArr.actual_size);
      }
      else {
        std::cout << utf8To1251("Невозможно удалить первый элемент, ");
        std::cout << utf8To1251("так как массив пустой.До свидания!");
        break;
      }
    }
    else if (answer == utf8To1251("нет") || answer == utf8To1251("нет ") || answer == utf8To1251("Нет") || answer == utf8To1251("Нет ")) {
      break;
    }
  }
  
  if (dynArr.logical_size > 0){ 
    std::cout << utf8To1251("Спасибо! Ваш динамический ");
    print_dynamic_array(dynArr.arr, dynArr.logical_size, dynArr.actual_size);
  }

  delete[] dynArr.arr;

  return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
/**
 * @brief печать динамического массива
 * @param arr массив
 * @param logical_size логический размер
 * @param actual_size фактический размер
 */
void print_dynamic_array(int* arr, int logical_size, int actual_size) {
  std::cout << utf8To1251("массив:");
  for (int i = 0; i < logical_size; i++) {
    std::cout << " " << arr[i];
  }
  for (int i = logical_size; i < actual_size; i++) {
    std::cout << " _";
  }
}
