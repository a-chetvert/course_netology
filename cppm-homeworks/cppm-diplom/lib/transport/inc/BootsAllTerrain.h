#pragma once
#include "GndTransport.h"
#include "LibApi.h"

class BootsAllTerrain :
    public GndTransport
{
protected:
  double calcRestTime(int restCount) const override;
public:
  TRANSPORTRACE_API BootsAllTerrain();
};
