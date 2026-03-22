#include "Race.h"
#include <algorithm>

bool Race::isSuitableType(Transport* transport) const
{
  switch (type) {
  case RaceType::all:
    return true;
  case RaceType::air:
    return (transport->getType() == TransportType::AIR);
  case RaceType::gnd:
    return (transport->getType() == TransportType::GND);
  default:
    return false;
  }
}

Race::Race(double distance, RaceType type)
  : distance(distance), type(type) {
}

void Race::start()
{
  for (const auto& oneTs : registeredTs) {
    raceResult.push_back({ oneTs->getName(), oneTs->calcTime(distance) });
  }

  std::sort(raceResult.begin(), raceResult.end(),
    [](const RaceResult& a, const RaceResult& b) {
      return a.time < b.time;
    });
}

std::vector<RaceResult> Race::getResult() const
{
  return raceResult;
};

double Race::getDistance() const {
  return distance;
}

RaceType Race::getRaceType() const {
  return type;
}

bool Race::registerTransport(Transport* transport) {
  //TODO
  if (isSuitableType(transport) && !isAlreadyRegistered(transport)) {
    registeredTs.push_back(transport);
    return true;
  }
  else 
    return false;
}

bool Race::isAlreadyRegistered(Transport* transport) const {
  // Получаем имя проверяемого транспорта
  std::string transportName = transport->getName();

  // Перебираем всех зарегистрированных участников
  for (const auto& registeredTransport : registeredTs) {
    // Сравниваем по имени
    if (registeredTransport->getName() == transportName) {
      return true; // Транспорт с таким именем уже зарегистрирован
    }
  }
  return false; // Транспорт не найден в списке участников
}

int Race::getCntRacers() const
{
  return static_cast<int>(registeredTs.size());
}

/**
 * @brief Может ли гонка начаться
 */
bool Race::canStart() const
{
  if (getCntRacers() < 2)
    return false;
  else
    return true;
}

/**
 * @brief Получает имена всех участников гонки
 *
 * Функция проходит по списку зарегистрированных транспортных средств
 * и собирает их имена в вектор строк.
 */
std::vector<std::string> Race::getNameRacers() const
{
  std::vector<std::string> resultNameVector;
  for (auto oneTransport : registeredTs) {
    resultNameVector.push_back(oneTransport->getName());
  }

  return resultNameVector;
}
