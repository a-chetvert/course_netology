#pragma once
#include "AirTransport.h"
#include "LibApi.h"

class  Broom :
    public AirTransport
{
protected:
  double reduction;
  double getDistanceReduction(double distance) const override;
public:
  TRANSPORTRACE_API Broom();
};

