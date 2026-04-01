#include <iostream>
#include <vector>
#include "Transport.h"  
#include "Race.h"
#include "ConsoleUI.h"

int main()
{
  RaceType raceType{ RaceType::all };
  double distance{0};

  // количество видов транспорта
  size_t totalTransports{ 0 };

  //вызываем фабрику для создания списка обьектов
  std::vector<Transport*> allTransport = makeTransports();

  std::cout << "Добро пожаловать в гоночный симулятор!\n";

  while (true)
  {
    printMenu();
    // Выбор типа гонки
    raceType = chooseRaceType();

    // Ввод дистанции
    distance = chooseDistance();
    Race race(distance, raceType);

    while (true) {
      // Регистрация транспорта
      registerTransports(race, allTransport);

      // Проверка возможности проведения гонки
      if (checkRace(race))
        break;
      else
        continue;
    }

    race.start();

    std::cout << "Результаты гонки:\n";
    int index{ 1 };

    std::vector<RaceResult> resultToPrint = race.getResult();
    for (const auto& oneTs : resultToPrint) {
      std::cout << "\n" << index++ << ". " << oneTs.transportName
        << ". Время: " << oneTs.time;
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
  freeTransports(allTransport);

  return EXIT_SUCCESS;
}
