/**
 * @brief Транспортное средство
 * @details Базовый класс для всех типов транспорта
 */

#pragma once
#include <string>
#include <vector>
#include "LibApi.h"

/**
 * @brief Типы транспорта
 */
enum class TransportType {
  GND,  ///< Наземный транспорт 
  AIR   ///< Воздушный транспорт
};

/**
 * @brief Базовый класс транспортного средства
 */
class Transport
{
protected:
	std::string name;
	int speed;

public:
	TRANSPORTRACE_API Transport(std::string name, int speed);
	TRANSPORTRACE_API const std::string getName() const;
  TRANSPORTRACE_API virtual TransportType getType() const = 0;
  TRANSPORTRACE_API virtual double calcTime(double distance) const = 0;
};

TRANSPORTRACE_API std::vector<Transport*> makeTransports();
TRANSPORTRACE_API void freeTransports(std::vector<Transport*> transportsToFree);
