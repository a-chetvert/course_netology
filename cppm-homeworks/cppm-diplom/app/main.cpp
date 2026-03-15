#include <iostream>
#include "Transport.h"
#include "Camel.h"
#include "Race.h"

int main()
{
  RaceType raceType{ 0 };
  int tmp{ 0 };
  double distance;

  std::cout << "Добро пожаловать в гоночный симулятор!\n";

  while (true)
  {
    while (true)
    {
      std::cout << "1. Гонка для наземного транспорта\n2. Гонка для воздушного транспорта \
        \n3. Гонка для наземного и воздушного транспорта\nВыберите тип гонки: ";
      std::cin >> tmp;
      if (tmp > 0 && tmp <= 3) {
        raceType = static_cast<RaceType>(tmp);
        break;
      }
      else {
        std::cout << "\nНеверный номер! Введите 1, 2 или 3.\n";
      }
    }

    while (true) {
      std::cout << "\nУкажите длину дистанции (должна быть положительна): ";
      std::cin >> distance;
      if (distance > 0) {
        break;
      }
      else {
        std::cout << "\nДлина не положительна. Попробуйте снова:";
      }
    }

    Race race(distance, raceType);

    while (true)
    {
      std::cout << "\nДолжно быть зарегистрировано хотя бы 2 транспортных средства\n \
        1. Зарегистрировать транспорт\n \
        Выберите действие: ";
      int action;
      std::cin >> action;
      if (action == 1) break;
    }

    std::cout << "\nГонка для ";
    switch (race.getRaceType()) {
    case RaceType::all:
      std::cout << "наземного и воздушного";
      break;
    case RaceType::air:
      std::cout << "воздушного";
      break;
    case RaceType::gnd:
      std::cout << "наземного";
      break;
    }
    std::cout << " транспорта. Расстояние: " << race.getDistance() << std::endl;


    // Повтор или выход
    std::cout << "\n1. Провести ещё одну гонку\n2. Выйти\nВыберите действие: ";
    int choice;
    std::cin >> choice;
    if (choice == 2)
    {
      break;
    }
  }


}
