#pragma once
#include "AirTransport.h"



class CarpetPlane :
    public AirTransport
{
  double getDistanceReduction(int distance) const override;
public:
  CarpetPlane();
  //double calcTime(int distance) const override;

};

