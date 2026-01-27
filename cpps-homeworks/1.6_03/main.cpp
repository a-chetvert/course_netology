/**
 * @brief Задача 2. Устранение дублирования
 * @note  https://github.com/netology-code/cpps-homeworks/tree/main/1.6/02
 */
#include <iostream>

void raiseTo(int base, int index);

int main(int argc, char** argv)
{
  int value = 5, power = 2;

  raiseTo(value, power);

  value = 3;
  power = 3;

  raiseTo(value, power);

  value = 4;
  power = 4;

  raiseTo(value, power);

  return 0;
}

/**
 * @brief возведение числа в степень
 * 
 * @param base основание
 * @param index степень
 */
void raiseTo(int base, int index){
  int result{1};
  for (int i = 0; i < index; i++)
  {
    result *= base;
  }
  std::cout << base << " в степени " << index << " = " << result << std::endl;
}