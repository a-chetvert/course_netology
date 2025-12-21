/**
 * @brief Задача 3. Двумерный массив
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.5/03
 */
#include <iostream>

#define ROWS 3
#define COLUMNS 6

using namespace std;

int main() {
  int num[ROWS][COLUMNS]{
            {1, 12, 3, 14, 5, 16},
            {7, 18, 9, 20, 11, 2},
            {13, 4, 15, 6, 17, 8}
          };
  int min{num[0][0]}, max{num[0][0]}, minRow{0}, 
  minColumn{0}, maxRow{0}, maxColumn{0};

  cout << "Массив: " << endl;

  for(auto &sub: num){
    for(int i : sub){
      cout << i << " ";
    }
    cout << endl;
  }

  for(int i=0; i<ROWS; i++){
    for(int j=0; j<COLUMNS; j++){
      if(num[i][j] < min){
        min = num[i][j];
        minRow = i;
        minColumn = j;
      }
    }
  }
  cout << "\nИндекс минимального элемента: ";
  cout << minRow << " " << minColumn;
  
  for(int i=0; i<ROWS; i++){
    for(int j=0; j<COLUMNS; j++){
      if(num[i][j] > max){
        max = num[i][j];
        maxRow = i;
        maxColumn = j;
      }
    }
  }
  cout << "\nИндекс максимального элемента: ";
  cout << maxRow << " " << maxColumn;

  return EXIT_SUCCESS;
}
