/**
 * @brief Задание 1. Таблица истинности.
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.3/01
 */
#include <iostream>

using namespace std;

int main() {

  cout << "Оператор: ||" << endl;
  cout << "true\ttrue\t" << ((true || true) ? "true" : "false") << endl;
  cout << "false\ttrue\t" << ((false || true) ? "true" : "false") << endl;
  cout << "true\tfalse\t" << ((true || false) ? "true" : "false") << endl;
  cout << "false\tfalse\t" << ((false || false) ? "true" : "false") << endl;

  cout << endl;

  cout << "Оператор: &&" << endl;
  cout << "true\ttrue\t" << ((true && true) ? "true" : "false") << endl;
  cout << "false\ttrue\t" << ((false && true) ? "true" : "false") << endl;
  cout << "true\tfalse\t" << ((true && false) ? "true" : "false") << endl;
  cout << "false\tfalse\t" << ((false && false) ? "true" : "false") << endl;

  return 0;
}
