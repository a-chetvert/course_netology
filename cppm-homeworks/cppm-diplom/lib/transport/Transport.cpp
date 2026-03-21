#include <vector>
#include "Transport.h"
#include "Camel.h"
#include "CamelFast.h"
#include "Centaur.h"
#include "BootsAllTerrain.h"
#include "Eagle.h"
#include "CarpetPlane.h"
#include "Broom.h"

/**
 * @brief Конструктор транспортного средства
 * @param[in] name Название транспорта
 * @param[in] speed Cкорость
 */
Transport::Transport(std::string name, int speed)
  : name(name), speed(speed) { };

const std::string Transport::getName() const
{
	return name;
}

Transport** makeTransports(size_t& total_transports)
{
	total_transports = 7; //максимальное число транспортов
	Transport** trans_arr = new Transport * [total_transports];
	trans_arr[0] = new Camel(); 
	trans_arr[1] = new CamelFast();
  trans_arr[2] = new Centaur();
  trans_arr[3] = new BootsAllTerrain();
  trans_arr[4] = new Eagle();
  trans_arr[5] = new CarpetPlane();
  trans_arr[6] = new Broom();

	return trans_arr;
}

//std::vector<Transport*> makeTransports(size_t& total_transports)
//{
//  std::vector<Transport*> transports;
//	total_transports = 7; //максимальное число транспортов
//	Transport** trans_arr = new Transport * [total_transports];
//	trans_arr[0] = new Camel(); 
//	trans_arr[1] = new CamelFast();
//  trans_arr[2] = new Centaur();
//  trans_arr[3] = new BootsAllTerrain();
//  trans_arr[4] = new Eagle();
//  trans_arr[5] = new CarpetPlane();
//  trans_arr[6] = new Broom();
//
//	return trans_arr;
//}