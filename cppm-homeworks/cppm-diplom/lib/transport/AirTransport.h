#pragma once
#include "Transport.h"
#include "LibApi.h"

class AirTransport :
  public Transport
{
protected:
  TRANSPORTRACE_API virtual double getDistanceReduction(int distance) const = 0;
public:
  TRANSPORTRACE_API AirTransport(std::string name, int speed);
  TRANSPORTRACE_API virtual double calcTime(int distance) const;
};
