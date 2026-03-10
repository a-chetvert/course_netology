#pragma once
#include "AirTransport.h"

class Eagle :
  public AirTransport
{
protected:
  double reduction;
  // ASK здесь аргумент distance бесполезен
  // как лучше сделать?
  double getDistanceReduction(int distance) const override;
public:
  Eagle();
  double calcTime(int distance) const override;
};
