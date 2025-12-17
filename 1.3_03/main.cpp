/**
 * @brief Задание 3*. Гороскоп.
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.3/03
 * @warning при использовании в VSCODE
 * cin не принимает кириллицу без setlocale()* 
 */
#include <iostream>

#define VSCODE 
#ifdef VSCODE
  #include <Windows.h>
#endif

using namespace std;

int main() {

#ifdef VSCODE
  //SetConsoleOutputCP(1251);
  setlocale(LC_ALL, "rus");
#endif    

  char sex {0};
  int age {0};
  string zodiac;
  bool isWaterSign{false};

  cout << "Введите пол: ";
  cin >> sex;
  
  cout << "\nsex: " << sex << endl;


  wcout << "Введите знак зодиака: ";
  cin >> zodiac;
  
  cout << "\nzodiac: " << zodiac << endl;

  wcout << "Введите возраст: ";
  cin >> age;

  cout << "\nage: " << age << endl;




/*   cout << "Введите второе число: ";
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

  cout << "\nРезультат: " << max << " " << midd << " " << min; */

  return 0;
}
