/**
 * @brief Задача 2. Макрос SUB
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/07/02
 */
#include <iostream>

#define SUB(a, b) ((a)-(b))
 
int main() {
	int a = 6;
	int b = 5;
	int c = 2;
	std::cout << SUB(a, b) << std::endl;
	std::cout << SUB(a, b) * c << std::endl;
	std::cout << SUB(a, b + c) * c << std::endl;

    return EXIT_SUCCESS;
}
