
#include <iostream>
#include <windows.h>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string utf8To1251(const string& utf8Str);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string name{ "" };
	cout << utf8To1251("Введите имя: ");
	cin >> name;
	cout << utf8To1251("Здравствуйте, ")<< name << "!" <<endl;
	return 0;
}

/**
 * @brief Конвертирует строку из кодировки UTF-8 в Windows-1251
 *
 * @param[in] utf8Str Строка в кодировке UTF-8 для конвертации
 * @return std::string Строка в кодировке Windows-1251
 * @retval Пустая строка В случае ошибки преобразования
 *
 * @details Функция выполняет двухэтапное преобразование кодировки:
 * 1. UTF-8 → UTF-16 (широкие символы)
 * 2. UTF-16 → Windows-1251
 */
std::string utf8To1251(const std::string& utf8Str) {
	int wsize = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);
	if (wsize == 0) return "";

	std::vector<wchar_t> wstr(wsize);
	MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, wstr.data(), wsize);

	int size = WideCharToMultiByte(1251, 0, wstr.data(), -1, NULL, 0, NULL, NULL);
	if (size == 0) return "";

	std::vector<char> str1251(size);
	WideCharToMultiByte(1251, 0, wstr.data(), -1, str1251.data(), size, NULL,
		NULL);

	return std::string(str1251.data(), size - 1);
}