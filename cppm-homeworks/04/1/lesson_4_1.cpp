/**
 * @brief Задача 1. Адреса
 * @note  https://github.com/netology-code/cppm-homeworks/tree/main/04/01
 */
#include <windows.h>

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Address {
 private:
  std::string city;
  std::string street;
  int home;
  int flat;

 public:
  Address(std::string city, std::string street, int home, int flat);
  std::string getOutputAddress();
};

std::string utf8To1251(const std::string& utf8Str);
std::string cp1251ToUtf8(const std::string& cp1251Str);

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  int numAddresses{0};
  Address** addresses{nullptr};

  // открываем файл для чтения
  std::ifstream fin("in.txt");
  if (fin.is_open()) {
    fin >> numAddresses;
    addresses = new Address*[numAddresses];
    for (int i = 0; i < numAddresses; i++) {
      std::string city{""};
      std::string street{""};
      int home{0};
      int flat{0};
      
      fin >> city;
      fin >> street;
      fin >> home;
      fin >> flat;
            
      addresses[i] = new Address(city, street, home, flat);
    }
    fin.close();
  } else {
    std::cout << utf8To1251("Не получилось открыть файл!") << std::endl;
  }

  // открываем файл для записи
  std::ofstream fout("out.txt");
  if (fout.is_open()) {
      fout << numAddresses;
      fout << "\n";
      for (int i = numAddresses-1; i >=0; i--) {
          fout << addresses[i]->getOutputAddress();
      }
      fout.close();
  }
  else {
      std::cout << utf8To1251("Не получилось открыть файл!") << std::endl;
  }

  return EXIT_SUCCESS;
}

Address::Address(std::string city, std::string street, int home, int flat) {
  this->city = city;
  this->street = street;
  this->home = home;
  this->flat = flat;
}

std::string Address::getOutputAddress() {
    return city + ", " + street + ", " + std::to_string(home) + ", " + std::to_string(flat) + "\n";
}

/**
 * @brief Конвертирует строку из кодировки UTF-8 в Windows-1251
 *
 * @param[in] utf8Str Строка в кодировке UTF-8 для конвертации
 * @return std::string Строка в кодировке Windows-1251
 * @retval Пустая строка В случае ошибки преобразования
 *
 * @details Функция выполняет двухэтапное преобразование кодировки:
 * 1. UTF-8 → UTF-16 (широкие символы)
 * 2. UTF-16 → Windows-1251
 */
std::string utf8To1251(const std::string& utf8Str) {
  int wsize = MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, NULL, 0);
  if (wsize == 0) return "";

  std::vector<wchar_t> wstr(wsize);
  MultiByteToWideChar(CP_UTF8, 0, utf8Str.c_str(), -1, wstr.data(), wsize);

  int size = WideCharToMultiByte(1251, 0, wstr.data(), -1, NULL, 0, NULL, NULL);
  if (size == 0) return "";

  std::vector<char> str1251(size);
  WideCharToMultiByte(1251, 0, wstr.data(), -1, str1251.data(), size, NULL,
                      NULL);

  return std::string(str1251.data(), size - 1);
}
