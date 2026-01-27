/**
 * @brief Задача 2. Максимум и минимум
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.5/02
 */
#include <iostream>

using namespace std;

int main() {
  int num[]{87, 123, 42, 15, 99, 64, 31, 78, 53, 6};
  int min{num[0]}, max{num[0]};

  cout << "Массив: ";
  for(int i : num){
    cout << i << " ";
  }

  cout << "\nМинимальный элемент: ";
  for(int i : num){
    if (i<min)
      min = i;
  }
  cout << min;
  
  cout << "\nМаксимальный элемент: ";
  for(int i : num){
    if (i>max)
      max = i;
  }
  cout << max;

  return EXIT_SUCCESS;
}
