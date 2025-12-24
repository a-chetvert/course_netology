/**
 * @brief Задача 1. Адреса переменных
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.7/01
 */
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
  short varShort{0};
  int varInt{0};
  long varLong{0};
  long long varLongLong{0};
  float varFloat{0};
  double varDouble{0};
  long double varLongDbl{0};
  bool varBool{0};

  cout << "short: " <<  varShort << " " << &varShort << " " << sizeof(varShort) << endl;
  cout << "int: " << varInt  << " " << &varInt << " " << sizeof(varInt) << endl;
  cout << "long: " <<  varLong << " " << &varLong << " " << sizeof(varLong) << endl;
  cout << "long long: " << varLongLong << " " << &varLongLong << " " << sizeof(varLongLong) << endl;
  cout << "float: " << varFloat << " " << &varFloat << " " << sizeof(varFloat) << endl;
  cout << "double: " << varDouble << " " << &varDouble << " " << sizeof(varDouble) << endl;
  cout << "long double: " << varLongDbl << " " << &varLongDbl << " " << sizeof(varLongDbl) << endl;
  cout << "bool: " << varBool  << " " << &varBool << " " << sizeof(varBool);

  return EXIT_SUCCESS;
}
