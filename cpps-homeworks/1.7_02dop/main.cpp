/**
 * @brief Задача 2. Обмен значениями
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.7/02
 */
#include <iostream>

/**
 * @brief Обмен значениями
 * @warning возможно переполнение!
 * 
 */
template <typename T>
void swap(T& argA, T& argB){
  argA += argB;
  argB = argA - argB;
  argA -= argB;
}

int main(int argc, char** argv)
{
	int a = 5, b = 8;

	std::cout << "a = " << a << ", b = " << b << std::endl;

	swap(a, b);

	std::cout << "a = " << a << ", b = " << b << std::endl;

  return EXIT_SUCCESS;
}
