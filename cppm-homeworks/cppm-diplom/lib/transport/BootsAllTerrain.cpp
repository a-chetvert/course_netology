#include "BootsAllTerrain.h"

// имя BootsAllTerrain
const char* NAME_BOOTS_RU = "Ботинки-вездеходы";
// скорость ботинок
const int SPEED_BOOTS = 6;
// время движения до отдыха
const int TIME_BEFORE_REST_BOOTS = 60;
// время первого отдыха
const int TIME_1ST_REST_BOOTS = 10;
// время последующих отдыхов
const int TIME_OTH_REST_BOOTS = 5;

double BootsAllTerrain::calcRestTime(int restCount) const
{
  double time{ 0 };
  // если не требуется отдых
  if (restCount == 0)
    return 0.0;
  else {
    time = TIME_1ST_REST_BOOTS;
    if (restCount > 1) {
      time += (restCount - 1) * TIME_OTH_REST_BOOTS;
    }
    return time;
  }
}

BootsAllTerrain::BootsAllTerrain()
  : GndTransport(NAME_BOOTS_RU, SPEED_BOOTS)
{
  timeBeforeRest = TIME_BEFORE_REST_BOOTS;
}
