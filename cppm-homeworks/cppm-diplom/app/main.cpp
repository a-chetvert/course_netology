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
  int typeChoice{ 0 };
  double distance;

  Camel camel;
  CamelFast camelFast;
  Centaur centaur;
  BootsAllTerrain boots;
  Eagle eagle;
  CarpetPlane carpet;
  Broom broom;

  std::vector<Transport*> allTransport = {
    &boots, &broom, &camel, &centaur, &eagle, &camelFast, &carpet
  };

  int action{0}; ///< действие (1 - регистрация ТС)

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
}
