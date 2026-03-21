
#include "Transport.h"

#include "BootsAllTerrain.h"
#include "Broom.h"
#include "Camel.h"
#include "CamelFast.h"
#include "CarpetPlane.h"
#include "Centaur.h"
#include "Eagle.h"

/**
 * @brief Конструктор транспортного средства
 * @param[in] name Название транспорта
 * @param[in] speed Cкорость
 */
Transport::Transport(std::string name, int speed) : name(name), speed(speed) {};

/**
 * @brief метод, возвращающий имя транспорта
 * @return std::string содержащий имя транспорта
 */
const std::string Transport::getName() const { return name; }

/**
 * @brief функция-фабрика объектов класса Transport
 * @return вектор указателей на объекты
 */

 /**
  * @brief Фабричная функция для создания списка транспорта
  * @return Вектор указателей на объекты транспорта
  * @note Память, выделенная под объекты, должна быть 
  * освобождена вызовом delete для каждого элемента
  */
std::vector<Transport*> makeTransports() {
  std::vector<Transport*> transports;
  transports.push_back(new Camel());
  transports.push_back(new CamelFast());
  transports.push_back(new Centaur());
  transports.push_back(new BootsAllTerrain());
  transports.push_back(new Eagle());
  transports.push_back(new CarpetPlane());
  transports.push_back(new Broom());

  return transports;
}


TRANSPORTRACE_API void freeTransports(std::vector<Transport*> transportsToFree){
  for (auto oneTransport : transportsToFree)
    delete oneTransport;  
}
