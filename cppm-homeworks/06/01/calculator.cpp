#include "calculator.h"
#include <iostream>
#include <cmath>

/// @brief сложение
/// @param x операнд
/// @param y операнд
/// @return сумма
int Calculator::addition(int x, int y) {
	return x + y;
}

/// @brief вычитание
/// @param x операнд
/// @param y операнд
/// @return сумма
int Calculator::subtraction(int x, int y) { 
	return x - y;
}

/// @brief умножение
/// @param x операнд
/// @param y операнд
/// @return произведение
int Calculator::multiplication(int x, int y)
{
	return x * y;
}

/// @brief деление
/// @param x делимое
/// @param y делитель
/// @return частное
int Calculator::division(int x, int y)
{
	return x / y;
}

/// @brief возведение в степень
/// @param x операнд
/// @param y операнд
/// @return число, результат возведения в степень
int Calculator::exponentiation(int x, int y)
{
	return std::pow(x,y);
}
