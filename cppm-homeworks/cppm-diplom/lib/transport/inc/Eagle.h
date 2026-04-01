#pragma once
#include "AirTransport.h"
#include "LibApi.h"

class Eagle :
  public AirTransport
{
protected:
  double reduction;
  // ASK здесь аргумент distance бесполезен
  // как лучше сделать?
  double getDistanceReduction(double distance) const override;
public:
  TRANSPORTRACE_API Eagle();
};
