/**
 * @brief Задача 3. Таблица умножения для числа
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.4/03
 */
#include <iostream>

using namespace std;

int main() {
  int num{0}, product{0};
  cout << "Введите целое число:"<< endl;
  cin >> num;
  for(int i = 1; i<=10; i++){
    cout << num << " x " << i << " = " << num * i  << endl;
  }
  
  return EXIT_SUCCESS;
}
