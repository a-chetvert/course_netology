/**
 * @brief Повторение слова.
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.2/02
 * 
 * @warning при использовании в VSCODE
 * cin не принимает кириллицу без setlocale()
 */
#include <iostream>

//#define VSCODE 
#ifdef VSCODE
  #include <Windows.h>
#endif

using namespace std;

int main() {
  string word;

#ifdef VSCODE  
  setlocale(LC_CTYPE, "rus");
#endif  

  cout << "Введите слово:" << endl;
  cin >> word;
  cout << "Вы ввели:\n" << word << endl;

  return 0;
}
