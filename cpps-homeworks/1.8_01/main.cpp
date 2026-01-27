/**
 * @brief Задача 1. Считающая функция
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.8/01
 */
#include <iostream>

using namespace std;

void counting_function(void){
  static unsigned int count{0};
  cout << "Количество вызовов функции counting_function(): " << ++count << endl;
}

int main(int argc, char** argv)
{
    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }

    return EXIT_SUCCESS;
}
