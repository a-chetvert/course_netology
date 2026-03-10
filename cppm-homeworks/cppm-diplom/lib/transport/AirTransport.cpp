#include "AirTransport.h"


AirTransport::AirTransport(std::string name, int speed)
	: Transport(name, speed)
{
}
double AirTransport::calcTime(int distance) const
{
  double time = distance * (1 - getDistanceReduction(distance)) / speed;
  return time;
}
;
