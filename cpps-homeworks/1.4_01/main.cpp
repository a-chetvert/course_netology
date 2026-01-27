/**
 * @brief Задача 1. Сумматор
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.4/01
 */
#include <iostream>

using namespace std;

int main() {
  int num{0}, total{0};
    
  do{
    cout << "Введите целое число или число '0', чтобы закончить:" << endl;
    cin >> num;
    total += num;
  }
  while(num);
  
  cout << "Сумма: " << total;
  
  return EXIT_SUCCESS;
}
