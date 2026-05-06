/**
 * @brief Задача 1. Вывод пирамиды на массиве
 * @note  https://github.com/netology-code/algocpp-homeworks/tree/main/5/01
 */
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <vector>

std::string utf8To1251(const std::string& utf8Str);
void print_pyramid(const int* arr, int size_arr);

/**
 * @brief класс пирамиды
 */
class Heap {
public:
	const int* data;
	const int size;
	const int root() {
		return data[0];
	}
	const int from_index(int index) {
		return data[index];
	}
	const int parent_index(int child_index) {
		return (child_index - 1) / 2;
	}
	Heap(const int* data, const int size) : data{ data }, size{ size } {};
};

/**
 * @brief вывод целочисленной пирамиды, реализованной на массиве
 * @param arr массив
 * @param size_arr логический размер
 */
void print_pyramid(const int* arr, int size_arr) {
	Heap heap(arr, size_arr);

	std::cout << 0 << " root " << heap.root() << std::endl;
	for (int i = 1; i < size_arr; i++) {
		int lvl{ 0 };	// уровень пирамиды
		int indx{ i };	// индекс для расчета уровня
		while(indx > 0) {
			indx = heap.parent_index(indx);
			lvl++;
		}

		std::cout << lvl;
		if (i % 2 == 0) {
			std::cout << " right(";
			std::cout << heap.from_index(heap.parent_index(i)) << ") ";
		}
		else {
			std::cout << " left(";
			std::cout << heap.from_index(heap.parent_index(i)) << ") ";
		}
		std::cout << heap.from_index(i) << std::endl;
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int arr1[]{ 1, 3, 6, 5, 9, 8 };
	int arr2[]{ 94, 67, 18, 44, 55, 12, 6, 42 };
	int arr3[]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
	int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
	int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
	int arr3_size = sizeof(arr3) / sizeof(arr3[0]);
	
	std::cout << utf8To1251("Исходный массив:");
	for (int num : arr1) 
		std::cout << " " << num;
	std::cout << utf8To1251("\nПирамида:\n");
	print_pyramid(arr1, arr1_size);

	std::cout << utf8To1251("Исходный массив:");
	for (int num : arr2)
		std::cout << " " << num;
	std::cout << utf8To1251("\nПирамида:\n");
	print_pyramid(arr2, arr2_size);

	std::cout << utf8To1251("Исходный массив:");
	for (int num : arr3)
		std::cout << " " << num;
	std::cout << utf8To1251("\nПирамида:\n");
	print_pyramid(arr3, arr3_size);

	return EXIT_SUCCESS;
}

//------------------------------------------------------------------------------
/**
 * @brief Вспомогательная функция для вывода массива.
 */
void print_array(const int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i];
		if (i < size - 1) std::cout << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief Конвертация строки из кодировки UTF-8 в Windows-1251.
 * @details Необходима для корректного вывода кириллических символов в консоль Windows,
 * которая по умолчанию работает с кодировкой CP-1251.
 * @param utf8Str Исходная строка в кодировке UTF-8.
 * @return std::string Результирующая строка в кодировке Windows-1251.
 * В случае ошибки возвращает пустую строку.
 */
std::string utf8To1251(const std::string& utf8Str) {
	int wsize = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);
	if (wsize == 0) return "";

	std::vector<wchar_t> wstr(wsize);
	MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, wstr.data(), wsize);

	int size = WideCharToMultiByte(1251, 0, wstr.data(), -1, NULL, 0, NULL, NULL);
	if (size == 0) return "";

	std::vector<char> str1251(size);
	WideCharToMultiByte(1251, 0, wstr.data(), -1, str1251.data(), size, NULL, NULL);

	return std::string(str1251.data(), size - 1); // -1 для удаления нулевого терминатора
}