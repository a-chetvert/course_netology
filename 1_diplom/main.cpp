/**
 * @brief Курсовой проект «Игра "Жизнь"»
 * @note  https://github.com/netology-code/cpps-diplom
 *
 * @todo
 * - добавить доп проверки при чтении точек
 * - проверить работу на нечетном количестве точек
 * - разбить readState() на несколько функций (слишком большая функция)
 * - подтянуть адекватный clang-format
 * - добавить функцию вывода для отладки
 */
#include <unistd.h>  // для sleep()

#include <cstdlib>  // для system("clear")
#include <fstream>
#include <iostream>

/// @brief макрос для отладки
 #define DEBUG

// прототипы функций
void print_two_dim_array(unsigned** arr, unsigned rows, unsigned cols);
void delArr(unsigned**& arrToDel, unsigned numRow);
void readState(unsigned**& arr, unsigned& inRows, unsigned& inCols,
               unsigned& count);
void printArea(unsigned**& arr, unsigned rows, unsigned cols);

int main() {
  unsigned rows{0}, cols{0}, points{0};
  unsigned** localArr{nullptr};
  readState(localArr, rows, cols, points);

#ifdef DEBUG
  std::cout << "Debug: Считанный массив " << std::endl;
  print_two_dim_array(localArr, points, 2);
#endif
  printArea(localArr, rows, cols);
  delArr(localArr, points);

  return EXIT_SUCCESS;
}

/**
 * @brief Выводит на экран содержимое двумерного массива типа unsigned.
 *
 * @param[in] dim_array Указатель на двумерный массив для вывода.
 * @param[in] rows Количество строк в массиве. Должно быть ≥ 0.
 * @param[in] cols Количество столбцов в массиве. Должно быть ≥ 0.
 *
 * @warning Не выполняет проверку указателей на nullptr. При передаче
 *          некорректных указателей возможно неопределенное поведение.
 */
void print_two_dim_array(unsigned** dim_array, unsigned rows, unsigned cols) {
  for (unsigned** p{dim_array}; p < dim_array + rows; p++) {
    for (unsigned* p_in{*p}; p_in < *p + cols; p_in++) {
      std::cout << *p_in << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Освобождает память, выделенную под двумерный массив типа unsigned.
 *
 * После выполнения указатель arrToDel устанавливается в неопределенное
 * состояние (не nullptr).
 *
 * @param[in,out] arrToDel Указатель на двумерный массив для освобождения.
 * @param[in] numRow Количество строк (первая размерность) в массиве.
 */
void delArr(unsigned**& arrToDel, unsigned numRow) {
  if (arrToDel != nullptr) {
    for (unsigned i = 0; i < numRow; i++) {
      delete[] arrToDel[i];
    }
    delete[] arrToDel;
    arrToDel = nullptr;
  }
}

/**
 * @brief Чтение начального состояния из файла "in.txt".
 *
 * @param[out] arr Указатель на двумерный массив для хранения координат живых
 * клеток. Размерность: [count][2], где [i][0] - x, [i][1] - y.
 * @param[out] inRows Количество строк игрового поля.
 * @param[out] inCols Количество столбцов игрового поля.
 * @param[out] count Количество живых клеток.
 *
 * @note
 * Функция считывает размеры поля и координаты живых клеток из текстового файла.
 * Формат файла:
 *   - Первая строка, первое поле: количество строк поля (inRows)
 *   - Первая строка, второе поле: количество столбцов поля (inCols)
 *   - Последующие строки: пары координат (x, y) живых клеток
 */
void readState(unsigned**& arr, unsigned& inRows, unsigned& inCols,
               unsigned& count) {
  std::string s;
  std::ifstream fin("in.txt");
  if (fin.is_open()) {
#ifdef DEBUG
    std::cout << "file is open" << std::endl;
#endif
    fin >> inRows;
    fin >> inCols;

#ifdef DEBUG
    std::cout << "inRows " << inRows << std::endl;
    std::cout << "inCols " << inCols << std::endl;
#endif

    count = 0;
    unsigned x, y;
    // Считываем оставшиеся пары чисел
    while (fin >> x >> y) {
      count++;
    }

#ifdef DEBUG
    std::cout << "count " << count << std::endl;
#endif
    fin.clear();   // сбрасываем флаг конца файла
    fin.seekg(0);  // возвращаемся в начало файла

    arr = new unsigned*[count]{0};
    for (unsigned i{}; i < count; i++) {
      arr[i] = new unsigned[2]{};
    }

    unsigned i{0};
    unsigned tmp{0};
    fin >> tmp;  // пропуск inRows
    fin >> tmp;  // пропуск inCols
    while (i < count) {
      fin >> arr[i][0];
      fin >> arr[i][1];
      i++;
    }
#ifdef DEBUG
    print_two_dim_array(arr, count, 2);
#endif
    fin.close();
  } else {
    std::cout << "Не получилось открыть файл!" << std::endl;
  }
}

/**
 * @brief функция, отображающая поле
 * 
 * @todo разобраться с очисткой терминала при отображении
 */
void printArea(unsigned**& arr, unsigned rows, unsigned cols) {
       
#ifdef DEBUG
    std::cout << "rows " << rows << std::endl;
    std::cout << "cols " << cols << std::endl;
#endif

  for (unsigned i{0}; i < rows; i++) {
    for (unsigned j{0}; j < cols; j++) {
      std::cout << "- ";
    }
    std::cout << std::endl;
  }
}