#include "Camel.h"

#define NAME_CAMEL_RU "Верблюд"
#define NAME_CAMEL_EN "Camel"

// скорость верблюда
const int SPEED_CAMEL = 10;
// время движения до отдыха
const int TIME_BEFORE_REST_CAMEL = 30;

double Camel::calcRestTime(int restCount) const
{
    return 0.0;
}

Camel::Camel() : GndTransport(NAME_CAMEL_EN, SPEED_CAMEL)
{
  timeBeforeRest = TIME_BEFORE_REST_CAMEL;
}
