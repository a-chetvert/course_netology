#include "GndTransport.h"

GndTransport::GndTransport(std::string name, int speed)
	: Transport(name, speed)
{
}

double GndTransport::calcTime(double distance) const
{
  /// @brief время в пути без остановок
  double timeWithoutRest = distance / speed; 

  //int countRest = static_cast<int>(timeWithoutRest) / timeBeforeRest;
  
  int countRest = static_cast<int>(timeWithoutRest) / timeBeforeRest;
  if ((static_cast<int>(timeWithoutRest) % timeBeforeRest) == 0)
      countRest--;
  double time = calcRestTime(countRest) + timeWithoutRest;
  return time;
}

TransportType GndTransport::getType() const
{
  return TransportType::GND;
};
