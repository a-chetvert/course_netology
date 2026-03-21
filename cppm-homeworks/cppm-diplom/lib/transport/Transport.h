/**
 * @brief Транспортное средство
 * @details Базовый класс для всех типов транспорта
 */

#pragma once
#include <string>
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
  TRANSPORTRACE_API virtual double calcTime(int distance) const = 0;
};

//TODO переделать комментарий!
//Фабричная функция для создания списка доступных транспортов
//На выходе массив транспорт и размер массива
//перед выходом из программы необходимо самому очистить память
TRANSPORTRACE_API Transport** makeTransports(size_t& total_transports);
