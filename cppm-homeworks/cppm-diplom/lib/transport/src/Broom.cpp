#include "Broom.h"

const char* NAME_BROOM_RU = "Метла";
// скорость метлы
const int SPEED_BROOM = 20;
const double REDUCTION_BROOM = 0.01;

double Broom::getDistanceReduction(double distance) const
{
  return static_cast<int>(distance / 1000) * reduction;
}

Broom::Broom() : AirTransport(NAME_BROOM_RU, SPEED_BROOM)
{
  reduction = REDUCTION_BROOM;
}
