/**
 * @brief Задача 2. Обмен значениями
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.7/02
 */
#include <iostream>

template <typename T>
void swap(T& argA, T& argB){
  T tmpArg = argA;
  argA = argB;
  argB = tmpArg;
}

int main(int argc, char** argv)
{
	int a = 5, b = 8;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

  return EXIT_SUCCESS;
}
