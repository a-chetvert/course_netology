/**
 * @brief Задача 4. Обратный пузырёк
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.5/04
 */
#include <iostream>

#define ELEMENTS 10

using namespace std;

int main() {
  int num[]{10, 3, 4, 1, 8, 9, 7, 2, 6, 5},
  tmp{0}, j{ELEMENTS-1};

  cout << "Массив до сортировки: " << endl;

  for(int i : num){
    cout << i << " ";
  }
  cout << endl;

  do{
    for(int i=ELEMENTS-1; i>0; i--){
      if(num[i]<num[i-1]){
        tmp = num[i];
        num[i] = num[i-1];
        num[i-1] = tmp;
      }
    }
  }
  while(j--!=0);
  
  cout << "Массив после сортировки: " << endl;
  
  for(int i : num){
    cout << i << " ";
  }
  cout << endl;

  return EXIT_SUCCESS;
}
