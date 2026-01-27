/**
 * @brief Задание 4*. Сравнить числа
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.3/04
 */
#include <iostream>

#define abs(x) ((x)>=0 ? (x) : (-x))

using namespace std;

int main() {
  int num[2]{0,};
  string unit[]{"ноль", "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять", "десять", "одиннадцать", "двенадцать", "тринадцать", 
    "четырнадцать", "пятнадцать", "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать"};
  string tens[]{"двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят", "семьдесят", "восемьдесят", "девяносто"};
    
  cout << "Введите целое число: ";
  cin >> num[0];

  cout << "Введите целое число: ";
  cin >> num[1];
  cout << endl;

  if(abs(num[0])>=100 || abs(num[1])>=100)
    cout << "Ошибка! Одно из чисел вне диапазона!";
  else{

    if(num[0]<0)
      cout << "минус ";

    if (abs(num[0])<=19)
    {
      cout << unit[abs(num[0])];
    }
    else{
      //минус 2, т.к. масив начинается с "двадцать"
      cout << tens[abs(num[0]) / 10 - 2] << " ";
      cout << unit[abs(num[0]) % 10];
    }

    if(num[0] == num[1]) 
      cout << " равно ";
    else if (num[0] > num[1]) 
      cout << " больше чем ";
    else
      cout << " меньше чем ";
    
    if(num[1]<0)
      cout << "минус ";

    if (abs(num[1])<=19)
    {
      cout << unit[abs(num[1])];
    }
    else{
      cout << tens[abs(num[1]) / 10 - 2] << " ";
      cout << unit[abs(num[1]) % 10];
    }
  }
  
  return EXIT_SUCCESS;
}
