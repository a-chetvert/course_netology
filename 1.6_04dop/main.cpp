/**
 * @brief Задача 3. Числа Фибоначчи (Усложение*)
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.6/03
 */
#include <iostream>

using namespace std;

int fibonacci(int num);

int main(int argc, char** argv)
{
  int num{0};
  unsigned long long result{0}, prevPrev{0}, prev{0}, c{0};

  cout << "Введите число: ";
  cin >> num;
  cout << "Числа Фибоначчи:";
  
  for(int i=0; i<num; i++){
    if (i==0)
    {
      result = 0;
      cout << result << " ";
    }
    else if (i==1)
    {   
      result = 1;
      prev = 0;
      cout << result << " "; 
    }
    else{
      prevPrev = prev;
      prev = result; 
      result = prevPrev + prev;
      cout << result << " ";
    }
  }
  
  return 0;
}