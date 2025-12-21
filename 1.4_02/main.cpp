/**
 * @brief Задача 2. Сумма цифр числа
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.4/02
 */
#include <iostream>

using namespace std;

int main() {
  int num{0}, total{0};
  cout << "Введите целое число:"<< endl;
  cin >> num;
  while(num){
    total += num % 10;
    num /= 10;
  }
  cout << "Сумма цифр: " << total;
  
  return EXIT_SUCCESS;
}
