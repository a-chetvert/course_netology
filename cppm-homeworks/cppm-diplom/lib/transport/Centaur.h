#pragma once
#include "GndTransport.h"
#include "LibApi.h"

class Centaur :
    public GndTransport
{
  double calcRestTime(int restCount) const override;
public:
  TRANSPORTRACE_API Centaur();
};
