/**
 * @brief Задача 1
 * @note  https://github.com/netology-code/cppl-homeworks/tree/main/03/01
 */

#include <iostream>
#include <exception>
#include <string>

class smart_array {
private:
  int* arr;
  int count_filled;
  int size;
public:
  smart_array(int count): count_filled(0), size(count) {
    arr = new int[count] {};
  };
  smart_array(const smart_array&) = delete;
  smart_array& operator=(const smart_array&) = delete;
  ~smart_array() {
    delete [] arr;
  };

  void add_element(int element) {
    // если число заполненных элементов 
    // совпадает с размером массива
    if (count_filled == size) {
      throw std::exception("\nThe memory is full");
    }
    arr[count_filled] = element;
    count_filled++;
  };

  int get_element(int element) {
    if (element > size-1 || element < 0) {
      std::string tmp = "Unable to get a " + std::to_string(element + 1) +
        " element.The array has a size of " + std::to_string(size);
      
      throw std::out_of_range(tmp);
    }
    return arr[element];
  };

};

int main() {
  try {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);
    arr.add_element(14);
    arr.add_element(15);

    std::cout << arr.get_element(i) << std::endl;
  }
  catch (const std::exception& ex) {
    std::cout << ex.what() << std::endl;
  }

  return EXIT_SUCCESS;
}