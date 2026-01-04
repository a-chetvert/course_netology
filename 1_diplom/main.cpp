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
 * - проверку на наличие клеток в файле (если их нет - вывести пустоеполе)
 *
 * @ask
 * - не работает system("cls") и ("clear")
 */
#include <unistd.h>  // для sleep()

#include <cstdlib>  // для system("clear"), system("cls")
#include <fstream>
#include <iostream>

/// @brief макрос для отладки
// #define DEBUG

/// @defgroup выбор формата очистки поля
#define CLEAR_BARE_ENTER 0  ///< @brief заполнение пустыми строками
#define CLEAR_CLS 0         ///< @brief использование функции system("cls")
#define CLEAR_CLEAR 0       ///< @brief использование функции system("clear")
#define CLEAR_ANSI 0        ///< @brief управляющая последовательность ANSI

/// @brief выбор формата очистки поля
#define CLEAR_AREA_STYLE CLEAR_BARE_ENTER

// прототипы функций
void print_two_dim_array(unsigned** arr, unsigned rows, unsigned cols);
void delArr(unsigned**& arrToDel, unsigned numRow);
void readState(unsigned**& arr, unsigned& inRows, unsigned& inCols,
               unsigned& count);
void clearScreen();
void printArea(unsigned**& arr, unsigned rows, unsigned cols,
               unsigned numPoints);
void printResult(unsigned generation, unsigned livingCells);
unsigned countNeighbors(unsigned**& arr, unsigned* point, unsigned rows,
                        unsigned cols);
// void updateArea();

int main() {
  unsigned generation{1},           // номер поколения
      rows{0},                      // размер поля по вертикали
      cols{0},                      // размер поля по горизонтали
      livingCells{0},               // текущее количество живых клеток
      prevLivingCells{0},           // предыдущее количество живых клеток
      **arrLiveCells{nullptr},      // массив позиций живых клеток
      **prevArrLiveCells{nullptr};  // массив предыдущих позиций живых клеток

  readState(arrLiveCells, rows, cols, livingCells);
#ifdef DEBUG
  std::cout << "Debug: Считанный массив " << std::endl;
  print_two_dim_array(arrLiveCells, points, 2);
#endif
  printArea(arrLiveCells, rows, cols, livingCells);
  printResult(generation, livingCells);

  for (size_t i = 0; i < livingCells; i++) {
    std::cout << "\n"
              << i << " point neigh is "
              << countNeighbors(arrLiveCells, arrLiveCells[i], rows, cols)
              << "\n"
              << std::endl;
  }

  delArr(arrLiveCells, livingCells);
  std::cout << std::endl;
  system("pause");
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

// #include <windows.h> // для Ansi последовательности

/**
 * @brief функция, отображающая поле
 *
 * @todo разобраться с очисткой терминала при отображении
 */
void printArea(unsigned**& arr, unsigned rows, unsigned cols,
               unsigned numPoints) {
  clearScreen();

#ifdef DEBUG
  std::cout << "rows " << rows << std::endl;
  std::cout << "cols " << cols << std::endl;
#endif

  for (unsigned i{0}; i < rows; i++) {
    for (unsigned j{0}; j < cols; j++) {
      bool flag{0};
      for (unsigned k{0}; k < numPoints; k++) {
        if (arr[k][0] == i && arr[k][1] == j) {
          std::cout << "* ";
          flag = 1;
        }
      }
      if (flag == 0) std::cout << "- ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief очистка экрана перед выводом поля
 */
void clearScreen() {
#if CLEAR_AREA_STYLE == CLEAR_BARE_ENTER
  for (int i = 0; i < 50; i++) {
    std::cout << std::endl;
  }
#elif CLEAR_AREA_STYLE == CLEAR_CLS
  std::system("cls");
#elif CLEAR_AREA_STYLE == CLEAR_CLEAR
  std::system("clear");
#elif CLEAR_AREA_STYLE == CLEAR_ANSI
  std::cout << "\033[2J\033[1;1H" << std::endl;
#endif
}

/**
 * @brief Выводит информацию о текущем поколении и количестве живых клеток.
 *
 * @param[in] generation Номер текущего поколения.
 * @param[in] livingCells Количество живых клеток в текущем поколении.
 */
void printResult(unsigned generation, unsigned livingCells) {
  std::cout << "Generation: " << generation << ". Alive cells: " << livingCells;
}

/**
 * @brief Подсчёт количества живых соседей
 *
 * @param[in] arr указатель на массив, содержащий координаты живых клеток
 * @param[in] point указатель на массив, содержащий координаты живой клетки
 * @return количество живых соседей
 */
unsigned countNeighbors(unsigned**& arr, unsigned* point, unsigned rows,
                        unsigned cols) {
  unsigned count{0};
  /*
  if(point[0] == 0){
    if (point[1] == 0)
    {

  }

}
else if(point[0] == (rows-1)){

}
else if(point[1] == 0){

}
else if(point[1] == (cols-1)){

}
*/
  std::cout << "\npoint X" << point[1] << std::endl;
  std::cout << "point Y" << point[0] << std::endl;

  if ((point[0] > 0 || point[0] < (rows - 1)) &&
      (point[1] > 0 || point[1] < (cols - 1))) {
    std::cout << "\nURAAA HARD GRID!" << std::endl;
    if ((point[0] == 0 || point[0] == (rows - 1)) ||
        (point[1] == 0 || point[1] == (cols - 1))) {
      std::cout << "\nWEAK GRID!" << std::endl;
    }
  }

  return 0;
};

// void updateArea(){};