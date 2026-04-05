/**
 * @brief Задача 2. Поиск в массиве
 * @note  https://github.com/netology-code/algocpp-homeworks/tree/main/1/02
 */
#include <iostream>

/**
 * @brief Находит количество элементов в отсортированном массиве,
 *        которые строго больше заданного числа
 * @param arr отсортированный массив целых чисел
 * @param size количество элементов в массиве
 * @param num точка отсчет
 * @return количество элементов в массиве, которые больше num
 */
int countMoreThenNum(int* arr, const int size, const int num) {
  int low{ 0 };
  int high{ size - 1 };
  int result{ size };
  
  while (low <= high) {
    int mid = (low + high) / 2;  // индекс среднего эл-та

    if (arr[mid] > num)
    {
      high = mid - 1;
      result = mid;
    }
    else 
      low = mid + 1;
  }
  return size - result;
}

int main()
{
  int arr[] { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
  const int size = sizeof(arr) / sizeof(arr[0]);

  int num;
  std::cout << "\nВведите точку отсчёта: ";
  std::cin >> num;

  std::cout << "Количество элементов в массиве больших, чем "
    << num << ": " << countMoreThenNum(arr, size, num) << std::endl;

  return EXIT_SUCCESS;
}
