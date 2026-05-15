/**
 * @brief Задача 3*. Поиск циклов
 * @note  https://github.com/netology-code/algocpp-homeworks/tree/main/7/03
 */
#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <vector>
#include <fstream>
#include <queue>

 /// @brief макрос для отладки
 //#define DEBUG

#define VISITED 1
#define NOT_VISITED 0

void readFile(int**& arr, int& sizeGraph);
void printGraphArray(int** arr, int sizeGraph);
void delArr(int**& arrToDel, int& sizeGraph);

std::string utf8To1251(const std::string& utf8Str);

int dfs(int**& graph, int vertex, int*& visited, int sizeGraph, int prev) {
  std::cout << " " << vertex + 1;
  visited[vertex] = VISITED;
  for (int i = 0; i < sizeGraph; i++)
    // если является смежной вершиной
    if (graph[vertex][i]) {
      // если смежная вершина не посещалась
      if (visited[i] == NOT_VISITED)
        dfs(graph, i, visited, sizeGraph, vertex);
      // вершина не равна предыдущей
      else if (i != prev) {
        return 1;
      }
    }
}

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int dim{ 0 }; /// размер массива
  int** graph{ nullptr }; ///указатель на граф в форме массива
  int* result{ nullptr }; ///для хранения данных о посещённых вершинах
  int index{ 0 };

  readFile(graph, dim);

#ifdef DEBUG
  printGraphArray(graph, dim);
#endif

  result = new int [dim] {0, };

  std::cout << utf8To1251("Порядок обхода вершин:");

  for (int i = 0; i < dim; i++) {
    // если вершина не посещалась
    if (result[i] == NOT_VISITED)
      dfs(graph, i, result, dim, 0);
  }

  delete[] result;
  delArr(graph, dim);

  return EXIT_SUCCESS;
}

/**
 * @brief Выводит на экран содержимое двумерного массива типа int.
 *
 * @param[in] arr Указатель на двумерный массив для вывода.
 * @param[in] sizeArea Количество строк и столбцов в массиве.
 */
void printGraphArray(int** arr, int sizeGraph) {
  for (int** p{ arr }; p < arr + sizeGraph; p++) {
    for (int* p_in{ *p }; p_in < *p + sizeGraph; p_in++) {
      std::cout << *p_in << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Динамически создаёт двумерный массив заданного размера
 * и инициализирует его нулями
 *
 * @param[out] arr Ссылка на указатель, который будет установлен на созданный массив.
 * @param[in] sizeArea Структура, содержащая размеры создаваемого массива.
 */
void createArr(int**& arr, int sizeGraph) {
  arr = new int* [sizeGraph];
  for (int i = 0; i < sizeGraph; i++) {
    arr[i] = new int[sizeGraph] {0, };
  }
}

/**
 * @brief Чтение начального состояния из файла "in.txt".
 * @param arr Указатель на двумерный массив, куда записывать из файла.
 * @param sizeGraph размер графа
 */
void readFile(int**& arr, int& sizeGraph) {
  std::string s;
  std::ifstream fin("in.txt");
  if (fin.is_open()) {
#ifdef DEBUG
    std::cout << "file is open" << std::endl;
#endif
    fin >> sizeGraph;

#ifdef DEBUG
    std::cout << "sizeGraph " << sizeGraph << std::endl;
#endif

    createArr(arr, sizeGraph);

    if (!fin.eof()) {
      while (true) {
        for (int i = 0; i < sizeGraph; i++) {
          for (int j = 0; j < sizeGraph; j++) {
            fin >> arr[i][j];
          }
        }
        if (fin.eof()) {
          break;
        }
      }
    }

    fin.close();
  }
  else {
    std::cout << utf8To1251("Не получилось открыть файл!") << std::endl;
  }
}

/**
 * @brief Освобождает память, выделенную под двумерный массив типа int.
 * @param arrToDel Указатель на двумерный массив для освобождения
 * @param sizeGraph размер массива для графа
 */
void delArr(int**& arrToDel, int& sizeGraph) {
  if (arrToDel != nullptr) {
    for (int i = 0; i < sizeGraph; i++) {
      delete[] arrToDel[i];
    }
    delete[] arrToDel;
    arrToDel = nullptr;
  }
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
