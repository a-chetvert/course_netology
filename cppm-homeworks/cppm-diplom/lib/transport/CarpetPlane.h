#pragma once
#include "AirTransport.h"
#include "LibApi.h"

class  CarpetPlane :
    public AirTransport
{
  double getDistanceReduction(int distance) const override;
public:
  TRANSPORTRACE_API CarpetPlane();
  //double calcTime(int distance) const override;

};

