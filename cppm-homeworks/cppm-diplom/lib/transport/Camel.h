#pragma once
#include "GndTransport.h"
class Camel :
    public GndTransport
{
  double calcRestTime(int restCount) const override;
public:
  Camel();
};

