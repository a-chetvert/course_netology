/**
 * @brief Задача 2. «Путешествие» по пирамиде
 * @note  https://github.com/netology-code/algocpp-homeworks/tree/main/5/02
 */
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <vector>
#include <cstdlib>

std::string utf8To1251(const std::string& utf8Str);
void print_array(const int* arr, const int size);

/**
 * @brief класс пирамиды
 */
class Heap {
public:
  const int* data;
  int size;

  const int root() {
    return data[0];
  }
  const int from_index(int index) {
    return data[index];
  }

  const int left_index(int parent_index) {
    int children_index = 2 * parent_index + 1;
    if (children_index >= size) {
      throw std::out_of_range(utf8To1251("Ошибка! Отсутствует левый потомок"));
    }
    return children_index;
  }
  const int right_index(int parent_index) {
    int children_index = 2 * parent_index + 2;
    if (children_index >= size) {
      throw std::out_of_range(utf8To1251("Ошибка! Отсутствует правый потомок"));
    }
    return children_index;
  }

  const int parent_index(int child_index) {
    int parent_ind = (child_index - 1) / 2;
    if (parent_ind < 0) {
      throw std::out_of_range(utf8To1251("Ошибка! Отсутствует родитель"));
    }
    return parent_ind;
  }

  Heap(const int* data, int size) : data{ data }, size{ size } {};
};

/**
 * @brief вывод целочисленной пирамиды, реализованной на массиве
 * @param arr массив
 * @param size_arr логический размер
 */
void print_pyramid(const int* arr, const int size_arr) {
  Heap heap(arr, size_arr);

  std::cout << 0 << " root " << heap.root() << std::endl;
  for (int i = 1; i < size_arr; i++) {
    int lvl{ 0 };	// уровень пирамиды
    int indx{ i };	// индекс для расчета уровня
    while (indx > 0) {
      indx = heap.parent_index(indx);
      lvl++;
    }

    std::cout << lvl;
    if (i % 2 == 0) {
      std::cout << " right(";
      std::cout << heap.from_index(heap.parent_index(i)) << ") ";
    }
    else {
      std::cout << " left(";
      std::cout << heap.from_index(heap.parent_index(i)) << ") ";
    }
    std::cout << heap.from_index(i) << std::endl;
  }
}

/**
 * @brief вывод целочисленной пирамиды, реализованной на массиве
 * @param arr массив
 * @param size_arr логический размер
 */
void print_element_pyramid(const int* arr, const int size_arr, const int element_index) {
  Heap heap(arr, size_arr);
  if (element_index == 0)
    std::cout << 0 << " root " << heap.root() << std::endl;
  else {
    int lvl{ 0 };	// уровень пирамиды
    int indx{ element_index };	// индекс для расчета уровня
    while (indx > 0) {
      indx = heap.parent_index(indx);
      lvl++;
    }
    std::cout << lvl;
    if (element_index % 2 == 0) {
      std::cout << " right(";
      std::cout << heap.from_index(heap.parent_index(element_index)) << ") ";
    }
    else {
      std::cout << " left(";
      std::cout << heap.from_index(heap.parent_index(element_index)) << ") ";
    }
    std::cout << heap.from_index(element_index) << std::endl;
  }
}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  const int arr1[]{ 1, 3, 6, 5, 9, 8 };
  const int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
  std::string answer;

  std::cout << utf8To1251("Исходный массив:");
  print_array(arr1, arr1_size);
  std::cout << utf8To1251("Пирамида:\n");
  print_pyramid(arr1, arr1_size);
  Heap heap(arr1, arr1_size);

  int index_now{ 0 };
  do {
    std::cout << utf8To1251("Вы находитесь здесь: ");
    print_element_pyramid(arr1, arr1_size, index_now);
    std::cout << utf8To1251("Введите команду: ");
    std::getline(std::cin, answer);

    if (answer == "exit") {
      break;
    }

    try {
      if (answer == "right") {
        index_now = heap.right_index(index_now);
        std::cout << "Ok\n";
      }
      else if (answer == "left") {
        index_now = heap.left_index(index_now);
        std::cout << "Ok\n";
      }
      else if (answer == "up") {
        index_now = heap.parent_index(index_now);
        std::cout << "Ok\n";
      }
      else {
        std::cout << "oth";
      }
    }
    catch (const std::out_of_range& e) {
      std::cout << e.what() << std::endl;
    }
  } while (1);

  return EXIT_SUCCESS;
}
//------------------------------------------------------------------------------

/**
 * @brief Вспомогательная функция для вывода массива.
 */
void print_array(const int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i];
    if (i < size - 1) std::cout << " ";
  }
  std::cout << std::endl;
}

/**
 * @brief Конвертация строки из кодировки UTF-8 в Windows-1251.
 * @details Необходима для корректного вывода кириллических символов в консоль Windows,
 * которая по умолчанию работает с кодировкой CP-1251.
 * @param utf8Str Исходная строка в кодировке UTF-8.
 * @return std::string Результирующая строка в кодировке Windows-1251.
 * В случае ошибки возвращает пустую строку.
 */
std::string utf8To1251(const std::string& utf8Str) {
  int wsize = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);
  if (wsize == 0) return "";

  std::vector<wchar_t> wstr(wsize);
  MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, wstr.data(), wsize);

  int size = WideCharToMultiByte(1251, 0, wstr.data(), -1, NULL, 0, NULL, NULL);
  if (size == 0) return "";

  std::vector<char> str1251(size);
  WideCharToMultiByte(1251, 0, wstr.data(), -1, str1251.data(), size, NULL, NULL);

  return std::string(str1251.data(), size - 1); // -1 для удаления нулевого терминатора
}