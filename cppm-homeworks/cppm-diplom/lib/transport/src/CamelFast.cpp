#include "CamelFast.h"

const char* NAME_CAMEL_FAST_RU = "Верблюд-быстроход";
// скорость верблюда
const int SPEED_CAMEL_FAST = 40;
// время движения до отдыха
const int TIME_BEFORE_REST_CAMEL_FAST = 10;

double CamelFast::calcRestTime(int restCount) const
{
  if (restCount <= 0) return 0.0;
  double time = 5.0; // первый отдых
  if (restCount >= 2)
    time += 6.5;   // второй отдых
  if (restCount > 2)
    time += (restCount - 2) * 8.0;
  return time;
}

CamelFast::CamelFast() : GndTransport(NAME_CAMEL_FAST_RU, SPEED_CAMEL_FAST)
{
  timeBeforeRest = TIME_BEFORE_REST_CAMEL_FAST;
}
