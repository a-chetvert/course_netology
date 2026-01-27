/**
 * @brief Задача 3. Числа Фибоначчи
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.6/03
 */
#include <iostream>

using namespace std;

int fibonacci(int num);

int main(int argc, char** argv)
{
  int num{0};

  cout << "Введите число: ";
  cin >> num;
  cout << "Числа Фибоначчи:";
  
  for(int i=0; i<num; i++)
    cout << " " << fibonacci(i);
  
  return 0;
}

/**
 * @brief возвращает число Фибоначчи, имеющее переданный
 *  номер в последовательности
 * 
 * @param num номер элемента последовательности Фибоначчи
 */
int fibonacci(int num){
  if (num <= 1)
    return num;
  else
    return fibonacci(num-1) + fibonacci(num-2);
}