#include "Centaur.h"

#define NAME_CENTAUR_RU "Кентавр"
#define NAME_CENTAUR_EN "Centaur"

// скорость кентавра
const int SPEED_CENTAUR = 15;
// время движения до отдыха
const int TIME_BEFORE_REST_CENTAUR = 8;
const int TIME_REST_CENTAUR = 2;

double Centaur::calcRestTime(int restCount) const
{
  double time = restCount * TIME_REST_CENTAUR;
  return time;
}

Centaur::Centaur() : GndTransport(NAME_CENTAUR_EN, SPEED_CENTAUR)
{
  timeBeforeRest = TIME_BEFORE_REST_CENTAUR;
}
