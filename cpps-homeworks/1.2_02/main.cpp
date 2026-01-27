//варианты решения для кодировок
 #define VARIANT_CP        //< @brief как в презентации
// #define VARIANT_LOCALE_0  //< @brief как в презентации
 //#define VARIANT_LOCALE_1
// #define VARIANT_LOCALE_2

#include <iostream>
#include <Windows.h>
#ifdef VARIANT_LOCALE_0 || VARIANT_LOCALE_1 || VARIANT_LOCALE_2
  #include <locale>
  #endif

using namespace std;

int main() {
string sex;

#ifdef VARIANT_CP
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
#endif  
#ifdef VARIANT_LOCALE_0  
  setlocale(LC_CTYPE, "rus"); // как в презентации
#endif  
#ifdef VARIANT_LOCALE_1
  setlocale(LC_ALL, "ru_RU.UTF-8");
#endif
#ifdef VARIANT_LOCALE_2
  setlocale(LC_ALL, "Russian");
#endif
    
  cout << "Введите пол:" << endl;
  cin >> sex;
  cout << "Ваш пол:\n" << sex << endl;

  return 0;
}
