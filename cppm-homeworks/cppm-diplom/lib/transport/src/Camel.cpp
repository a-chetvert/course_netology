#include "Camel.h"

const char* NAME_CAMEL_RU = "Верблюд";
// скорость верблюда
const int SPEED_CAMEL = 10;
// время движения до отдыха
const int TIME_BEFORE_REST_CAMEL = 30;
// время первого отдыха
const int TIME_1ST_REST_CAMEL = 5;
// время последующих отдыхов
const int TIME_OTH_REST_CAMEL = 8;

double Camel::calcRestTime(int restCount) const
{
  double time{0};
  // если не требуется отдых
  if(restCount == 0)
    return 0.0;
  
  time = TIME_1ST_REST_CAMEL;
  if (restCount > 1) {
    time += (restCount - 1) * TIME_OTH_REST_CAMEL;
  }
  return time;
}

Camel::Camel() 
  : GndTransport(NAME_CAMEL_RU, SPEED_CAMEL)
{
  timeBeforeRest = TIME_BEFORE_REST_CAMEL;
}
