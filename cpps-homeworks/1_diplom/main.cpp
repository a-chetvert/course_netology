/**
 * @brief Курсовой проект «Игра "Жизнь"»
 * @note  https://github.com/netology-code/cpps-diplom
 *
 * @warning 
 * - для выбора формата очистки поля заполнить макрос
 * CLEAR_AREA_STYLE
 * - код работает только в скомпилированном виде
 * работоспособности в терминале vscode получить
 * не удалось 
 * - скомпилированный файл exe называется "main.exee"
 * (для запуска переименовать на "main.exe")
 * 
 * @todo
 * - добавить доп проверки при чтении точек
 * - добавить функцию вывода для отладки *
 * @ask
 * - не работает system("cls"), ("clear")
 */

#ifdef _WIN32
#include <windows.h>  // для Ansi последовательности
#else
#include <unistd.h>  
#endif

#include <thread>   // для std::this_thread::sleep_for
#include <chrono>   // для time durations

#include <cstdlib>  // для system("clear"), system("cls")
#include <fstream>
#include <iostream>

/// @brief использование пауз
#define USE_PAUSE

/// @defgroup выбор формата очистки поля
#define CLEAR_BARE_ENTER 0  ///< @brief заполнение пустыми строками
#define CLEAR_CLS 1         ///< @brief использование функции system("cls")
#define CLEAR_CLS_BIG 2     ///< @brief использование функции system("cls")
#define CLEAR_CLEAR 3       ///< @brief использование функции system("clear")
#define CLEAR_ANSI 4        ///< @brief управляющая последовательность ANSI

/// @brief выбор формата очистки поля
#define CLEAR_AREA_STYLE CLEAR_CLS_BIG

/// @brief макрос для отладки
// #define DEBUG

struct tSizeArea {
  int rows;  // размер поля по вертикали
  int cols;  // размер поля по горизонтали
};

enum class state { ALL_OK, STAGNAITED, CELLS_DEAD };

// прототипы функций
void printTwoDimArray(int** arr, tSizeArea sizeArea);
void createArr(int**& arr, tSizeArea sizeArea);
void delArr(int**& arrToDel, tSizeArea sizeArea);
void readFile(int**& arr, tSizeArea& sizeArea);

void clearScreen();
void printArea(int** arr, tSizeArea sizeArea);
void printResult(int generation, int livingCells);
int countNeighbors(int**& arr, tSizeArea sizeArea, int y, int x);
void calcLiveCell(int**& arr, tSizeArea sizeArea, int& livingCells);
bool isStagnated(int**& arr1, int**& arr2, tSizeArea sizeArea);

int main() {
  int generation{1},   // номер поколения
      rows{0},         // размер поля по вертикали
      cols{0},         // размер поля по горизонтали
      livingCells{0},  // текущее количество живых клеток
      **nextArrCells{
          nullptr},         // массив позиций живых клеток следующее поколение
      **arrCells{nullptr},  // массив позиций живых клеток
      **prevArrCells{nullptr};  // массив предыдущих позиций живых клеток
  tSizeArea sizeArea{0, };
  state stateCells{state::ALL_OK};  // состояние клеток/поля

  readFile(arrCells, sizeArea);

  while (true) {
    calcLiveCell(arrCells, sizeArea, livingCells);
    printArea(arrCells, sizeArea);
    printResult(generation, livingCells);
    createArr(nextArrCells, sizeArea);
    for (int i = 0; i < sizeArea.rows; i++) {
      for (int j = 0; j < sizeArea.cols; j++) {
        int neighbors = countNeighbors(arrCells, sizeArea, i, j);

        if (arrCells[i][j] == 1) {  // Живая клетка
          if (neighbors == 2 || neighbors == 3) {
            nextArrCells[i][j] = 1;  // Остается живой
          } else {
            nextArrCells[i][j] = 0;  // Умирает
          }
        } else {  // Мертвая клетка
          if (neighbors == 3) {
            nextArrCells[i][j] = 1;  // Рождается
          } else {
            nextArrCells[i][j] = 0;  // Остается мертвой
          }
        }
      }
    }

    if (livingCells == 0) {
      stateCells = state::CELLS_DEAD;
      break;
    }

    if (isStagnated(arrCells, nextArrCells, sizeArea)) {
      generation++;
      printArea(arrCells, sizeArea);
      printResult(generation, livingCells);
      stateCells = state::STAGNAITED;
      break;
    }

    // очищаем первый массив
    delArr(arrCells, sizeArea);

    // запоминаем состояние
    arrCells = nextArrCells;

    generation++;

  #ifdef USE_PAUSE
    std::this_thread::sleep_for(std::chrono::seconds(2));
  #else
    system("pause");
  #endif

  }

  if (stateCells == state::STAGNAITED) {
    std::cout << "The world is stagnated. ";
  } else if (stateCells == state::CELLS_DEAD) {
    std::cout << "All cells are dead. ";
  }

  std::cout << "Game over\n";

  delArr(arrCells, sizeArea);
  delArr(nextArrCells, sizeArea);

  // ASK является ли кроссплатформенной?
  system("pause");

  return EXIT_SUCCESS;
}

/**
 * @brief Выводит на экран содержимое двумерного массива типа int.
 *
 * @param[in] arr Указатель на двумерный массив для вывода.
 * @param[in] sizeArea Количество строк и столбцов в массиве.
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
 * @param[in,out] arrToDel Указатель на двумерный массив для освобождения.
 * @param[in] sizeArea Структура с количеством строк (первая размерность).
 */
void delArr(int**& arrToDel, tSizeArea sizeArea) {
  if (arrToDel != nullptr) {
    for (int i = 0; i < sizeArea.rows; i++) {
      delete[] arrToDel[i];
    }
    delete[] arrToDel;
    arrToDel = nullptr;
  }
}

/**
 * @brief Чтение начального состояния из файла "in.txt".
 * 
 * @param[in] arr Указатель на двумерный массив, куда записывать из файла.
 * @param[in] sizeArea ссылка на структуру с параметрами поля
 * 
 */
void readFile(int**& arr, tSizeArea& sizeArea) {
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

    createArr(arr, sizeArea);

    int x{0}, y{0};
    if (!fin.eof()) {
      while (true) {
        fin >> y >> x;
        arr[y][x] = 1;
        if (fin.eof()) {
          break;
        }
      }
    }

    fin.close();
  } else {
    std::cout << "Не получилось открыть файл!" << std::endl;
  }
}

/**
 * @brief функция, отображающая поле
 *
 * @param[in] arr Указатель на двумерный массив с клетками
 * @param[in] sizeArea ссылка на структуру с параметрами поля
 */
void printArea(int** arr, tSizeArea sizeArea) {
  clearScreen();

  for (int i{0}; i < sizeArea.rows; i++) {
    for (int j{0}; j < sizeArea.cols; j++) {
      std::cout << (arr[i][j] ? "* " : "- ");
    }
    std::cout << std::endl;
  }
}

/**
 * @brief очистка экрана перед выводом поля
 */
void clearScreen() {
#ifdef _WIN32
  #if CLEAR_AREA_STYLE == CLEAR_BARE_ENTER
    for (int i = 0; i < 50; i++) {
      std::cout << std::endl;
    }
  #elif CLEAR_AREA_STYLE == CLEAR_CLS
    std::system("cls");
  #elif CLEAR_AREA_STYLE == CLEAR_CLS_BIG
    std::system("CLS");
  #elif CLEAR_AREA_STYLE == CLEAR_CLEAR
    std::system("clear");
  #elif CLEAR_AREA_STYLE == CLEAR_ANSI
    std::cout << "\033[2J\033[1;1H" << std::endl;
  #endif
#else
  std::cout << "\x1B[2J\x1B[H"; //Альтернатива: (void)system("clear")
#endif
}

/**
 * @brief Выводит информацию о текущем поколении и количестве живых клеток.
 *
 * @param[in] generation Номер текущего поколения.
 * @param[in] livingCells Количество живых клеток в текущем поколении.
 */
void printResult(int generation, int livingCells) {
  std::cout << "Generation: " << generation << ". Alive cells: " << livingCells
            << std::endl;
}

/**
 * @brief Подсчёт количества живых соседей
 *
 * @param[in] arr Двумерный массив, представляющий игровое поле.
 *                Значение 1 соответствует живой клетке, 0 - мёртвой.
 * @param[in] sizeArea Структура, содержащая размеры игрового поля
 * @param[in] y Координата Y (номер строки) проверяемой клетки
 * @param[in] x Координата X (номер столбца) проверяемой клетки
 *
 * @return Количество живых соседей от 0 до 8. 
 */
int countNeighbors(int**& arr, tSizeArea sizeArea, int y, int x) {
  int count{0};

  if (y == 0 && x == 0) {
    if (arr[y + 1][x]) count++;
    if (arr[y + 1][x + 1]) count++;
    if (arr[y][x + 1]) count++;
  } else if (y == (sizeArea.rows - 1) && x == (sizeArea.cols - 1)) {
    if (arr[y - 1][x]) count++;
    if (arr[y - 1][x - 1]) count++;
    if (arr[y][x - 1]) count++;
  } else if (y == 0 && x == (sizeArea.cols - 1)) {
    if (arr[y + 1][x]) count++;
    if (arr[y + 1][x - 1]) count++;
    if (arr[y][x - 1]) count++;
  } else if (y == (sizeArea.rows - 1) && x == 0) {
    if (arr[y - 1][x]) count++;
    if (arr[y - 1][x + 1]) count++;
    if (arr[y][x + 1]) count++;
  } else if (y == 0) {
    if (arr[y][x - 1]) count++;
    if (arr[y][x + 1]) count++;
    if (arr[y + 1][x - 1]) count++;
    if (arr[y + 1][x]) count++;
    if (arr[y + 1][x + 1]) count++;
  } else if (x == 0) {
    if (arr[y - 1][x]) count++;
    if (arr[y + 1][x]) count++;
    if (arr[y - 1][x + 1]) count++;
    if (arr[y][x + 1]) count++;
    if (arr[y + 1][x + 1]) count++;
  } else if (y == sizeArea.rows - 1) {
    if (arr[y][x - 1]) count++;
    if (arr[y][x + 1]) count++;
    if (arr[y - 1][x - 1]) count++;
    if (arr[y - 1][x]) count++;
    if (arr[y - 1][x + 1]) count++;
  } else if (x == sizeArea.cols - 1) {
    if (arr[y - 1][x]) count++;
    if (arr[y + 1][x]) count++;
    if (arr[y - 1][x - 1]) count++;
    if (arr[y][x - 1]) count++;
    if (arr[y + 1][x - 1]) count++;
  } else if (x > 0 && x < (sizeArea.cols - 1) && y > 0 &&
             y < (sizeArea.rows - 1)) {
    if (arr[y - 1][x - 1]) count++;
    if (arr[y - 1][x]) count++;
    if (arr[y - 1][x + 1]) count++;

    if (arr[y][x + 1]) count++;
    if (arr[y][x - 1]) count++;

    if (arr[y + 1][x - 1]) count++;
    if (arr[y + 1][x]) count++;
    if (arr[y + 1][x + 1]) count++;
  }
  return count;
};

/**
 * @brief Динамически создаёт двумерный массив заданного размера 
 * и инициализирует его нулями
 *
 * @param[out] arr Ссылка на указатель, который будет установлен на созданный массив.
 * @param[in] sizeArea Структура, содержащая размеры создаваемого массива.
 */
void createArr(int**& arr, tSizeArea sizeArea) {
  arr = new int*[sizeArea.rows];
  for (int i = 0; i < sizeArea.rows; i++) {
    arr[i] = new int[sizeArea.cols]{
        0,
    };
  }
}

/**
 * @brief Подсчитывает количество живых клеток на игровом поле
 *
 * Функция проходит по всем элементам двумерного массива и подсчитывает
 * количество ячеек со значением 1, которые представляют живые клетки.
 *
 * @param[in] arr Двумерный массив, представляющий игровое поле.
 *                Значение 1 соответствует живой клетке, 0 - мёртвой.
 * @param[in] sizeArea Структура, содержащая размеры игрового поля.
 * @param[out] livingCells Ссылка на переменную, в которую будет записано
 *                         общее количество живых клеток на поле.
 */
void calcLiveCell(int**& arr, tSizeArea sizeArea, int& livingCells) {
  livingCells = 0;
  for (int i{0}; i < sizeArea.rows; i++) {
    for (int j{0}; j < sizeArea.cols; j++) {
      if (arr[i][j] == 1) livingCells++;
    }
  }
}

/**
 * @brief Проверяет, идентичны ли два игровых поля
 *
 * Функция сравнивает два двумерных массива поэлементно и определяет,
 * содержат ли они одинаковые состояния. Используется для обнаружения
 * стагнации (стабилизации) в игре "Жизнь", когда состояние поля
 * перестаёт изменяться.
 *
 * @param[in] arr1 Указатель на первый двумерный массив (текущее состояние).
 * @param[in] arr2 Указатель на второй двумерный массив (предыдущее состояние).
 * @param[in] sizeArea Структура, содержащая размеры сравниваемых массивов.
 *                     Оба массива должны иметь одинаковые размеры.
 *
 * @return true - если все соответствующие элементы массивов равны
 *         false - если обнаружено хотя бы одно различие
 */
bool isStagnated(int**& arr1, int**& arr2, tSizeArea sizeArea) {
  for (int i{0}; i < sizeArea.rows; i++) {
    for (int j{0}; j < sizeArea.cols; j++) {
      if (arr1[i][j] != arr2[i][j]) return 0;
    }
  }
  return 1;
}