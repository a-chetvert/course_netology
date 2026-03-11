#include "CamelFast.h"

#define NAME_CAMEL_FAST_RU "Верблюд-быстроход"
#define NAME_CAMEL_FAST_EN "Camel fast"

// скорость верблюда
const int SPEED_CAMEL_FAST = 40;
// время движения до отдыха
const int TIME_BEFORE_REST_CAMEL_FAST = 10;

double CamelFast::calcRestTime(int restCount) const
{
  //TODO ПЕРЕДЕЛАЙ!!!
  double time{ 0 };
  // если не требуется отдых
  if (restCount == 0)
    return 0.0;
  else {
    time = 5;
    if (restCount > 1) {
      time += 6.5;
      if (restCount > 2)
      time += (restCount - 2) * 8;
      return time;
    }
  }
}

CamelFast::CamelFast() : GndTransport(NAME_CAMEL_FAST_EN, SPEED_CAMEL_FAST)
{
  timeBeforeRest = TIME_BEFORE_REST_CAMEL_FAST;
}
