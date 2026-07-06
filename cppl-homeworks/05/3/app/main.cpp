/**
 * @brief Задача 3. Счётчик чисел
 * @note  https://github.com/netology-code/cppl-homeworks/blob/main/05/03/
 */

#include <iostream>
#include <cstdlib>

class Functor {
private:
  int sum = 0;
  int count = 0;

public:
  Functor() : sum(0), count(0) {};

  void operator()(int value){
    if (value % 3 == 0) {
      sum += value;
      count++;
    }
  }

  int get_sum() const{
    return sum;
  }

  int get_count() const{
    return count;
  }

};

int main() {
  int arr[]{ 4, 1, 3, 6, 25, 54};
  Functor f;

  std::cout << "[IN]: ";
  for (auto i : arr) {
    std::cout << i << " ";
    f(i);
  }

  std::cout << "\n[OUT]: get_sum() = " << f.get_sum() << "\n";
  std::cout << "[OUT]: get_count() = " << f.get_count();

  return EXIT_SUCCESS;
}