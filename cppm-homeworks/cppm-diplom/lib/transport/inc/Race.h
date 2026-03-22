#pragma once
#include "RaceType.h"
#include "Transport.h"
#include "LibApi.h"
#include <iostream>
#include <vector>

const int COUNT_TYPES_TRANSPORT = 7;

struct RaceResult {
  std::string transportName;
  double time;
};

class Race
{
protected:
  double distance;
  RaceType type;
  std::vector<Transport*> registeredTs; ///< массив указателей на транспортные средства
  std::vector<RaceResult> raceResult;
  bool isSuitableType(Transport* transport) const;

public:
  TRANSPORTRACE_API Race(double distance, RaceType type);
  TRANSPORTRACE_API double getDistance() const;
  TRANSPORTRACE_API RaceType getRaceType() const;
  TRANSPORTRACE_API bool registerTransport(Transport* transport);
  TRANSPORTRACE_API bool isAlreadyRegistered(Transport* transport) const;
  TRANSPORTRACE_API int getCntRacers() const;
  TRANSPORTRACE_API bool canStart() const;
  TRANSPORTRACE_API std::vector<std::string> getNameRacers() const;
  TRANSPORTRACE_API void start();
  TRANSPORTRACE_API std::vector<RaceResult> getResult() const;
};

