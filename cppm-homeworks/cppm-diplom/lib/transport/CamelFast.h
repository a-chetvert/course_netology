#pragma once
#include "GndTransport.h"
#include "LibApi.h"

class CamelFast :
  public GndTransport
{
  double calcRestTime(int restCount) const override;
public:
  TRANSPORTRACE_API CamelFast();
};

