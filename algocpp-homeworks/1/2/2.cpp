
#include <iostream>

int countMoreThenNum(int* arr, const int size, const int num) {
  int *begin{ arr };  // первый эл-т массива
  int* low{ arr };  
  int *high = arr + size - 1;
  int* startLeft;
  int tmp{ 0 }, index{0};
  while (low <= high) {
    int *mid = arr + (high - low) / 2;
    if (*mid <= num) {
      high = mid;
    }
      
  }

}

int main()
{
  int arr[] { 14, 16, 19, 32, 32, 32, 56, 69, 72 };
  const int size = sizeof(arr) / sizeof(arr[0]);

  int num;
  std::cout << "Введите точку отсчёта: ";
  std::cin >> num;

  std::cout << "Количество элементов в массиве больших, чем "
    << num << ": " << countMoreThenNum(arr, size, num) << std::endl;

  return EXIT_SUCCESS;
}
