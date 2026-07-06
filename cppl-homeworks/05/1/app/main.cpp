/**
 * @brief Задача 1. Возведение в квадрат
 * @note  https://github.com/netology-code/cppl-homeworks/blob/main/05/01/
 */

#include <iostream>
#include <cstdlib>
#include <vector>

template <typename T> T squaring(const T a) {
  return a * a;
}

template <typename T> std::vector <T> squaring(std::vector <T> a) {
  std::vector <T> res(a.size());
  for (auto i{ 0 }; i < a.size(); i++) {
    res[i] = a[i] * a[i];
  }
  return res;
}

int main() {
  const int test_num = 4;
  const std::vector <int> test_vector = {-1, 4, 8};

  std::cout << "[IN]: " << test_num << std::endl;
  std::cout << "[OUT]: " << squaring<int>(test_num) << std::endl;
  std::cout << "[IN]: ";
  for (auto iter{ test_vector.cbegin() }; iter!= test_vector.cend(); ++iter) {
    std::cout << *iter;
    if((iter+1) != test_vector.cend())
      std::cout << ", ";
  }
  std::cout << "\n[OUT]: ";
  std::vector <int> res_vector = squaring(test_vector);
  for (auto iter{ res_vector.cbegin() }; iter != res_vector.cend(); ++iter) {
    std::cout << *iter;
    if ((iter + 1) != res_vector.cend())
      std::cout << ", ";
  }
  return EXIT_SUCCESS;
}