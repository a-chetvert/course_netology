#pragma once
#include "GndTransport.h"
class BootsAllTerrain :
    public GndTransport
{
protected:
  double calcRestTime(int restCount) const override;
public:
  TRANSPORTRACE_API BootsAllTerrain();
};
