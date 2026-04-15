/**
 * @brief Задача 1. Сортировка слиянием
 * @note  https://github.com/netology-code/algocpp-homeworks/blob/main/3/01/readme.md
 */
#include <iostream>

 /**
  * @brief Слияние двух отсортированных половин массива
  * @param arr исходный массив
  * @param left индекс начала левой половины
  * @param mid индекс конца левой половины (середина)
  * @param right индекс конца правой половины
  */
void merge(int* arr, int left, int mid, int right) {
  // Вычисляем размеры временных подмассивов
  int sizeLeft = mid - left + 1;
  int sizeRight = right - mid;

  // Память под объединяемые массивы
  int* leftArr = new int[sizeLeft];
  int* rightArr = new int[sizeRight];

  for (int i = 0; i < sizeLeft; i++)
    leftArr[i] = arr[left + i];
  for (int i = 0; i < sizeRight; i++)
    rightArr[i] = arr[mid + 1 + i ];

  int i{ 0 }, j{ 0 }; // Индексы для обхода подмассивов и основного массива
  int k = left; // Начинаем заполнять основной массив с позиции left

  // сравнение элементов и заполнение arr
  while (i < sizeLeft && j < sizeRight) {
    if (leftArr[i] <= rightArr[j])
    {
      arr[k] = leftArr[i];
      i++;
    }
    else
    {
      arr[k] = rightArr[j];
      j++;
    }
    k++;
  }

  while (i < sizeLeft) {
    arr[k] = leftArr[i];
    i++;
    k++;
  }
  while (j < sizeRight) {
    arr[k] = rightArr[j];
    j++;
    k++;
  }

  delete[] leftArr;
  delete[] rightArr;
}

void merge_sort_recursive(int* arr, int begin, int end) {

  if (begin >= end)
    return;

  int mid = begin + (end - begin) / 2;

  merge_sort_recursive(arr, begin, mid);
  merge_sort_recursive(arr, mid + 1, end);

  merge(arr, begin, mid, end);
}

void merge_sort(int* arr, int size) {
  // Вызываем внутреннюю рекурсивную функцию с полными границами массива
  merge_sort_recursive(arr, 0, size - 1);
}

void print_arr(int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << " ";
  }
}

int main() {
  system("chcp 65001");

  // Первый массив: 10 чисел
  int arr1[] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
  int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
  //// Второй массив: 15 чисел
  //int arr2[] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
  //int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
  //// Третий массив: 18 чисел
  //int arr3[] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
  //int arr3_size = sizeof(arr3) / sizeof(arr3[0]);

  int arr4[] = { 3, 4, 6, 10, 12, 1, 2, 5, 7, 8 };
  int arr4_size = sizeof(arr4) / sizeof(arr4[0]);

  std::cout << "Исходный массив: ";
  print_arr(arr4, arr4_size);
  merge_sort(arr4, arr4_size);
  std::cout << "\nОтсортированный массив: ";
  print_arr(arr4, arr4_size);

  return EXIT_SUCCESS;
}