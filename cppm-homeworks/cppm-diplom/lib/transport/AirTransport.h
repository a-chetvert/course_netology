#pragma once
#include "Transport.h"

class AirTransport :
  public Transport
{
protected:
  virtual double getDistanceReduction(int distance) const = 0;
public:
  AirTransport(std::string name, int speed);
  virtual double calcTime(int distance) const;
};
