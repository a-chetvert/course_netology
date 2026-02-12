/**
 * @brief Задача 1. Простое исключение
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/08/01
 */
#include <windows.h>
#include <iostream>
#include <string>
#include <exception>

// расскомментировать для использования SetConsole..()
//#define USE_SET_CONSOLE

#define DECISION_SIMPLE 0
#define DECISION_DOMAIN 1
// выбор типа решения
#define DECISION_TYPE DECISION_SIMPLE

#if DECISION_TYPE == DECISION_SIMPLE
class MyException : public std::exception {
public:
	const char* what() const override {
		return "Вы ввели слово запретной длины! До свидания";
	}
};
#endif

int function(std::string str, int forbidden_length);

int main() {
#ifdef USE_SET_CONSOLE
	 SetConsoleCP(1251);
	 SetConsoleOutputCP(1251);
#endif 

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
		catch (const std::exception& e) {
			std::cout << e.what() << std::endl;
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
#if DECISION_TYPE == DECISION_SIMPLE
		throw MyException();
#endif
#if DECISION_TYPE == DECISION_DOMAIN
		throw std::domain_error("Вы ввели слово запретной длины! До свидания");
#endif

	}
	else return lenght;
}