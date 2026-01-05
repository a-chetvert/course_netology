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

struct tSizeArea {
  int rows;  // размер поля по вертикали
  int cols;  // размер поля по горизонтали
};

// прототипы функций
void printTwoDimArray(int** arr, tSizeArea sizeArea);
void delArr(int**& arrToDel, int numRow);
void readState(int**& arr, tSizeArea& sizeArea, int& count);

void clearScreen();
void printArea(int**& arr, tSizeArea sizeArea, int numPoints);
void printResult(int generation, int livingCells);
int countNeighbors(int**& arr, int* point, tSizeArea sizeArea);
// void updateArea();

int main() {
  int generation{1},                // номер поколения
      rows{0},                      // размер поля по вертикали
      cols{0},                      // размер поля по горизонтали
      livingCells{0},               // текущее количество живых клеток
      prevLivingCells{0},           // предыдущее количество живых клеток
      **arrLiveCells{nullptr},      // массив позиций живых клеток
      **prevArrLiveCells{nullptr};  // массив предыдущих позиций живых клеток
  tSizeArea sizeArea{
      0,
  };
  readState(arrLiveCells, sizeArea, livingCells);
#ifdef DEBUG
  std::cout << "Debug: Считанный массив " << std::endl;
  printTwoDimArray(arrLiveCells, points, 2);
#endif
  printArea(arrLiveCells, sizeArea, livingCells);
  printResult(generation, livingCells);

  for (size_t i = 0; i < livingCells; i++) {
    std::cout << "\n"
              << i << " point neigh is "
              << countNeighbors(arrLiveCells, arrLiveCells[i], sizeArea)
              << "\n"
              << std::endl;
  }

  delArr(arrLiveCells, livingCells);
  std::cout << std::endl;
  system("pause");
  return EXIT_SUCCESS;
}

/**
 * @brief Выводит на экран содержимое двумерного массива типа int.
 *
 * @param[in] arr Указатель на двумерный массив для вывода.
 * @param[in] sizeArea Количество строк и столбцов в массиве. 
 *
 * @warning Не выполняет проверку указателей на nullptr. При передаче
 *          некорректных указателей возможно неопределенное поведение.
 */
void printTwoDimArray(int** arr, tSizeArea sizeArea) {
  for (int** p{arr}; p < arr + sizeArea.rows; p++) {
    for (int* p_in{*p}; p_in < *p + sizeArea.cols; p_in++) {
      std::cout << *p_in << " ";
    }
    std::cout << std::endl;
  }
}

/**
 * @brief Освобождает память, выделенную под двумерный массив типа int.
 *
 * После выполнения указатель arrToDel устанавливается в неопределенное
 * состояние (не nullptr).
 *
 * @param[in,out] arrToDel Указатель на двумерный массив для освобождения.
 * @param[in] numRow Количество строк (первая размерность) в массиве.
 */
void delArr(int**& arrToDel, int numRow) {
  if (arrToDel != nullptr) {
    for (int i = 0; i < numRow; i++) {
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
 * @param[in] sizeArea Количество строк и столбцов в массиве. 
 * @param[out] count Количество живых клеток.
 *
 * @note
 * Функция считывает размеры поля и координаты живых клеток из текстового файла.
 * Формат файла:
 *   - Первая строка, первое поле: количество строк поля (inRows)
 *   - Первая строка, второе поле: количество столбцов поля (inCols)
 *   - Последующие строки: пары координат (x, y) живых клеток
 */
void readState(int**& arr, tSizeArea& sizeArea, int& count) {
  std::string s;
  std::ifstream fin("in.txt");
  if (fin.is_open()) {
#ifdef DEBUG
    std::cout << "file is open" << std::endl;
#endif
    fin >> sizeArea.rows;
    fin >> sizeArea.cols;

#ifdef DEBUG
    std::cout << "sizeArea.rows " << sizeArea.rows << std::endl;
    std::cout << "sizeArea.cols " << sizeArea.cols << std::endl;
#endif

    count = 0;
    int x, y;
    // Считываем оставшиеся пары чисел
    while (fin >> x >> y) {
      count++;
    }

#ifdef DEBUG
    std::cout << "count " << count << std::endl;
#endif
    fin.clear();   // сбрасываем флаг конца файла
    fin.seekg(0);  // возвращаемся в начало файла

    arr = new int*[count]{0};
    for (int i{}; i < count; i++) {
      arr[i] = new int[2]{};
    }

    int i{0};
    int tmp{0};
    fin >> tmp;  // пропуск inRows
    fin >> tmp;  // пропуск inCols
    while (i < count) {
      fin >> arr[i][0];
      fin >> arr[i][1];
      i++;
    }
#ifdef DEBUG
    printTwoDimArray(arr, count, 2);
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
void printArea(int**& arr, tSizeArea sizeArea, int numPoints) {
  clearScreen();

#ifdef DEBUG
  std::cout << "rows " << rows << std::endl;
  std::cout << "cols " << cols << std::endl;
#endif

  for (int i{0}; i < sizeArea.rows; i++) {
    for (int j{0}; j < sizeArea.cols; j++) {
      bool flag{0};
      for (int k{0}; k < numPoints; k++) {
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
void printResult(int generation, int livingCells) {
  std::cout << "Generation: " << generation << ". Alive cells: " << livingCells;
}

/**
 * @brief Подсчёт количества живых соседей
 *
 * @param[in] arr указатель на массив, содержащий координаты живых клеток
 * @param[in] point указатель на массив, содержащий координаты живой клетки
 * @return количество живых соседей
 */
int countNeighbors(int**& arr, int* point, tSizeArea sizeArea) {
  int count{0};
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

  if ((point[0] == 0 || point[0] == (sizeArea.rows - 1)) ||
      (point[1] == 0 || point[1] == (sizeArea.cols - 1))) {
    std::cout << "\nedge poin!" << std::endl;
  }
  /*
  if ((point[0] > 0 || point[0] < (rows - 1)) &&
      (point[1] > 0 || point[1] < (cols - 1))) {
    std::cout << "\nURAAA HARD GRID!" << std::endl;

  }*/

  return 0;
};

// int** createArr(int rows)