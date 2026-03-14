#pragma once
#include "RaceType.h"
#include "Transport.h"
#include "LibApi.h"

#define COUNT_TYPES_TRANSPORT 7

class Race
{
protected:
  double distance;
  RaceType type;
  Transport* pTS[COUNT_TYPES_TRANSPORT];
public:
  TRANSPORTRACE_API Race(double distance, RaceType type);
  TRANSPORTRACE_API void start();

};

