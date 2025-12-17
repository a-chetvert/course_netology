/**
 * @brief Задание 2. Упорядочить числа.
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.3/02
 */
#include <iostream>

using namespace std;

int main() {
  int num[3] = {0,   };
  int min{0}, max{0}, midd{0};

  cout << "Введите первое число: ";
  cin >> num[0];
  cout << "Введите второе число: ";
  cin >> num[1];
  cout << "Введите третье число: ";
  cin >> num[2];

  max = (num[0] >= num[1]) ? ((num[0] >= num[2]) ? num[0] : num[2])
                           : ((num[1] >= num[2]) ? num[1] : num[2]);

  min = (num[0] <= num[1]) ? ((num[0] <= num[2])   ? num[0]
                              : (num[1] <= num[2]) ? num[1]
                                                   : num[2])
                           : ((num[1] <= num[2]) ? num[1] : num[0]);

  midd = num[0] + num[1] + num[2] - min - max;

  cout << "\nРезультат: " << max << " " << midd << " " << min;

  return 0;
}
