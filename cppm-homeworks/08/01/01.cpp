/**
 * @brief Задача 1. Простое исключение
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/08/01
 */
#include <windows.h>
#include <iostream>
#include <string>

int function(std::string str, int forbidden_length);

int main() {
	 SetConsoleCP(1251);
	 SetConsoleOutputCP(1251);
	int forbidden_length{0};
	int length{ 0 };
	std::string str{""};
	std::cout << "Введите запретную длину: ";
	std::cin >> forbidden_length;

	while (true) {
		std::cout << "Введите слово: ";
		std::cin >> str;
		try {
			length = function(str, forbidden_length);
		}
		catch (...) {
			std::cout << "Вы ввели слово запретной длины! До свидания" << std::endl;
			return EXIT_FAILURE;
		}
		std::cout << "Длина слова \"" << str <<"\" равна " << length << std::endl;
	}
	return EXIT_SUCCESS;
}

/**
 * @brief Вычисляет длину строки с проверкой на запрещенную длину и переполнение
 * 
 * @param[in] str Строка для вычисления длины
 * @param[in] forbidden_length Запрещенная длина строки
 * 
 * @return Длина строки как целое число
 */
int function(std::string str, int forbidden_length) {
	int lenght = static_cast<int>(str.length()); 
	if (lenght == forbidden_length) {
		throw "bad_length";
	}
	else return lenght;
}