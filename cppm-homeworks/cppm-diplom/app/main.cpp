#include <iostream>
#include <vector>
#include "Transport.h"
#include "Camel.h"
#include "CamelFast.h"
#include "Race.h"
#include "Centaur.h"
#include "BootsAllTerrain.h"
#include "Eagle.h"
#include "CarpetPlane.h"
#include "Broom.h"
#include "ConsoleUI.h"

int main()
{
  RaceType raceType{ 0 };
  double distance;

  // количество видов транспорта
  size_t totalTransports{ 0 };
  //вызываем фабрику для создания списка обьектов
  Transport** transportsAll = makeTransports(totalTransports);

  // Создаем вектор для удобства работы с UI
  std::vector<Transport*> allTransport;
  for (size_t i = 0; i < totalTransports; ++i) {
    allTransport.push_back(transportsAll[i]);
  }

  std::cout << "Добро пожаловать в гоночный симулятор!\n";

  while (true)
  {
    printMenu();
    // Выбор типа гонки
    raceType = chooseRaceType();

    // Ввод дистанции
    distance = chooseDistance();
    Race race(distance, raceType);
    
    // Регистрация транспорта
    registerTransports(race, allTransport);

    // Проверка возможности проведения гонки
    if (!race.canStart()) {
      std::cout << "Недостаточно участников для гонки. Попробуйте снова.\n";
      continue;
    }

    race.start();

    std::cout << "Результаты гонки:\n";
    int index{ 1 };
    std::vector <std::string> result2print = race.getResult();
    for (const auto& oneTs : result2print) {
      std::cout << "\n" << index++ << ". " << oneTs;
    }

    std::cout << "\n";

    // Повтор или выход
    std::cout << "\n1. Провести ещё одну гонку\n2. Выйти\nВыберите действие: ";
    int choice;
    std::cin >> choice;
    if (choice == 2)
    {
      break;
    }
  }

  //освобождаем память
  for (int i = 0; i < totalTransports; i++)
  {
    delete transportsAll[i];
  }
  delete[] transportsAll;
  return EXIT_SUCCESS;
}
