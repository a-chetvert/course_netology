#pragma once
#include "AirTransport.h"
class Broom :
    public AirTransport
{
protected:
  double reduction;
  double getDistanceReduction(int distance) const override;
public:
  Broom();
};

