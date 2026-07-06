/**
 * @brief Задача 2. Таблица
 * @note  https://github.com/netology-code/cppl-homeworks/blob/main/05/02/
 */

#include <iostream>
#include <cstdlib>

// структура для логического размера
struct LSize {
  int rows;
  int cols;
};

template <typename T> 
class table{
  private:
    T** tab;
    int cols;
    int rows;
  public:
    table(int a, int b) : rows{ a }, cols{ b } {
      tab = new T* [rows];
      for (int i = 0; i < rows; i++) {
        tab[i] = new T[cols];
      }
    };

    ~table(){
      for (int i = 0; i < rows; i++) {
        delete tab[i];
      }
      delete[] tab;
    }

    T* operator[] (int row) {
      return tab[row];
    }

    LSize Size() const {
      LSize tmp;
      tmp.rows = rows;
      tmp.cols = cols;
      return tmp;
    }

    //физический размер таблицы
    int SizePhys() const {
      return rows * cols;
    }
};

int main() {
  auto test = table<int>(2, 3);
  test[0][0] = 4;
  std::cout << test[0][0]; // выводит 4

  LSize tmp = test.Size();
  std::cout << "\nЛогический размер: строк - " << tmp.rows << ", столбцов - " << tmp.cols;
  std::cout << "\nФизический размер: " << test.SizePhys();

  return EXIT_SUCCESS;
}