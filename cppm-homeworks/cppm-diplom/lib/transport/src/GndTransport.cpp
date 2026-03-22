#include "GndTransport.h"

GndTransport::GndTransport(std::string name, int speed)
	: Transport(name, speed)
{
}

double GndTransport::calcTime(int distance) const
{
  /// @brief время в пути без остановок
  double timeWithoutRest = static_cast<double>(distance) / speed; 

  int countRest = static_cast<int>(timeWithoutRest) / timeBeforeRest;
  double time = calcRestTime(countRest) + timeWithoutRest;
  return time;
}

TransportType GndTransport::getType() const
{
  return TransportType::GND;
};
