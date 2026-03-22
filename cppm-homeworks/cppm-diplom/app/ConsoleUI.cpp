#include "ConsoleUI.h" 

void printMenu() {
  std::cout << "1. Гонка для наземного транспорта\n"
    << "2. Гонка для воздушного транспорта\n"
    << "3. Гонка для наземного и воздушного транспорта\n";
}

RaceType chooseRaceType() {
  int choice{ 0 };
  while (choice < 1 || choice > 3)
  {
    std::cout << "Выберите тип гонки: ";
    std::cin >> choice;
    if (choice < 1 || choice > 3)
      std::cout << "\nНеверный номер! Введите 1, 2 или 3.\n";
  };
  return static_cast<RaceType>(choice);
}

double chooseDistance() {
  double dist;
  do {
    std::cout << "\nУкажите длину дистанции (должна быть положительна): ";
    std::cin >> dist;
    if (dist <= 0)
      std::cout << "\nДлина не положительна. Попробуйте снова:";
  } while (dist <= 0);
  return dist;
}

void registerTransports(Race& race, const std::vector<Transport*>& allTransport) {

  int action{ 0 }; ///<для ввода решений и номера ТС

  do {
    std::cout << "\nДолжно быть зарегистрировано хотя бы "
      << "2 транспортных средства\n"
      << "1. Зарегистрировать транспорт\n"
      << "Выберите действие: ";
    std::cin >> action;
    if (action != 1)
      std::cout << "Введенного действия не существует.\n";
  } while (action != 1);

  do {
    // вывод информации об участниках
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

    
    if (race.getCntRacers()) {
      std::cout << "Зарегистрированные транспортные средства: ";
      std::vector<std::string> namesTs = race.getNameRacers();

      int index{ race.getCntRacers() };
      for (auto oneName : namesTs) {
        std::cout << oneName;
        if(index-- != 1)
          std::cout << ", ";
      }
      std::cout << "\n";
    }

    // показать список доступного транспорта
    int index{ 1 };
    for (auto oneTransport : allTransport) {
      std::cout << index++ << ". ";
      std::cout << oneTransport->getName() << std::endl;
    }

    std::cout << "0. Закончить регистрацию";

    std::cout << "\nВыберите транспорт или 0 для окончания процесса регистрации: ";

    // ввод решения
    std::cin >> action;

    if (action >= 1 && action <= static_cast<int>(allTransport.size())) {
      if (race.registerTransport(allTransport[action - 1])) {
        std::cout << "Успешно зарегистрированный транспорт: "
          << allTransport[action - 1]->getName() << "\n";
      }
      else {
        std::cout << "Ошибка: неподходящий тип или уже зарегистрирован.\n";
      }
    }
    else {
      std::cout << "Неверный номер.\n";
    }


  } while (action != 0);
}

bool checkRace(Race& race){
// Проверка возможности проведения гонки
  if (!race.canStart()) {
    std::cout << "Недостаточно участников для гонки. Попробуйте снова.\n";
    return false;
  }
  else return true;
}