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
void createArr(int**& arr, tSizeArea sizeArea);
void delArr(int**& arrToDel, tSizeArea sizeArea);
void readFile(int**& arr, tSizeArea& sizeArea);

void clearScreen();
void printArea(int** arr, tSizeArea sizeArea);
void printResult(int generation, int livingCells);
int countNeighbors(int**& arr, int* point, tSizeArea sizeArea);
// void updateArea();

int main() {
  int generation{1},       // номер поколения
      rows{0},             // размер поля по вертикали
      cols{0},             // размер поля по горизонтали
      livingCells{0},      // текущее количество живых клеток
      prevLivingCells{0},  // предыдущее количество живых клеток
      **nextArrCells{
          nullptr},         // массив позиций живых клеток следующее поколение
      **arrCells{nullptr},  // массив позиций живых клеток
      **prevArrCells{nullptr};  // массив предыдущих позиций живых клеток
  tSizeArea sizeArea{
      0,
  };
  readFile(arrCells, sizeArea);

#ifdef DEBUG
  std::cout << "Debug: Считанный массив " << std::endl;
  printTwoDimArray(arrCells, sizeArea);
#endif

  printArea(arrCells, sizeArea);

  createArr(nextArrCells, sizeArea);

  // запоминаем состояние
  prevArrCells = arrCells;

  // очищаем первый массив
  delArr(arrCells, sizeArea);

  // инициализируем
  createArr(arrCells, sizeArea);

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
 * переписать
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

    // заменить функцией
    createArr(arr, sizeArea);
    /*
    arr = new int*[sizeArea.rows];
    for (int i = 0; i < sizeArea.rows; i++) {
      arr[i] = new int[sizeArea.cols]{
          0,
      };
    }
      */

    int x{0}, y{0};
    while (fin >> y >> x) {
#ifdef DEBUG
      std::cout << "x " << x << ", y " << y << std::endl;
#endif
      if (fin.eof()) {
        break;
      }
      arr[y][x] = 1;
    }
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
void printArea(int** arr, tSizeArea sizeArea) {
  clearScreen();

  for (int i{0}; i < sizeArea.rows; i++) {
    for (int j{0}; j < sizeArea.cols; j++) {
      std::cout << (arr[i][j] ? "* " : "- ");
    }
    std::cout << std::endl;
  }
}

// #include <windows.h> // для Ansi последовательности

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

 * @return количество живых соседей
 */
int countNeighbors(int**& arr, tSizeArea sizeArea, int x, int y) {
  int count{0};


  if (y == 0 && x == 0)
  {
    std::cout << "UPS y == 0 && x == 0\n" << std::endl;
  }
  else if (y == (sizeArea.rows-1) && x == (sizeArea.cols-1)){
    std::cout << "y == (sizeArea.rows-1) && x == (sizeArea.cols-1)\n" << std::endl;
  }
  else if (y == 0 && x == (sizeArea.cols-1)){
    std::cout << "y == 0 && x == (sizeArea.cols-1)\n" << std::endl;
  }
  else if (y == (sizeArea.rows-1) && x == 0){
    std::cout << "(y == (sizeArea.rows-1) && x == 0)\n" << std::endl;
  }
  else if (y == 0){
    std::cout << "y == 0\n" << std::endl;
  }
  else if (x == 0){

    std::cout << "x == 0\n" << std::endl;
  }
  else if (y == sizeArea.rows-1){
    std::cout << "y == sizeArea.rows-1\n" << std::endl;
  }
  else if (x == sizeArea.cols-1){
    std::cout << "x == sizeArea.cols-1\n" << std::endl;
  }
  else {
    if(arr[y-1][x-1]) count++;
    if(arr[y-1][x]) count++;
    if(arr[y-1][x+1]) count++;
    
    if(arr[y][x+1]) count++;
    if(arr[y][x-1]) count++;

    if(arr[y+1][x-1]) count++;
    if(arr[y+1][x]) count++;
    if(arr[y+1][x+1]) count++;
  }
  return count;
};

void createArr(int**& arr, tSizeArea sizeArea) {
  arr = new int*[sizeArea.rows];
  for (int i = 0; i < sizeArea.rows; i++) {
    arr[i] = new int[sizeArea.cols]{
        0,
    };
  }
}
// int** createArr(int rows)