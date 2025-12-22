/**
 * @brief Задача 1. Арифметические функции
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.6/01
 */
#include <iostream>

using namespace std;

int sum(int operandA, int operandB);
int diff(int operandA, int operandB);
int multiplication(int operandA, int operandB);
double division(int operandA, int operandB);

int main(int argc, char** argv)
{
	int a = 5, b = 10;

	int s = sum(a, b);
	int dif = diff(a, b);
	int mult = multiplication(a, b);
	double div = division(a, b);

	std::cout << a << " + " << b << " = " << s << std::endl;
	std::cout << a << " - " << b << " = " << dif << std::endl;
	std::cout << a << " * " << b << " = " << mult << std::endl;
	std::cout << a << " / " << b << " = " << div << std::endl;
	
	return 0;
}

int sum(int operandA, int operandB){
  return operandA + operandB;
}

int diff(int operandA, int operandB){
  return operandA - operandB;
}

int multiplication(int operandA, int operandB){
  return operandA * operandB;
}

double division(int operandA, int operandB){
  return static_cast<double>(operandA) / operandB;
}
