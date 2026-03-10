#include "Broom.h"

const std::string NAME_BROOM_RU = "Метла";
const std::string NAME_BROOM_EN = "Broom";

// скорость метлы
const int SPEED_BROOM = 20;
const double REDUCTION_BROOM = 0.01;

double Broom::getDistanceReduction(int distance) const
{
  return (distance / 1000) * reduction;
}

Broom::Broom() : AirTransport(NAME_BROOM_EN, SPEED_BROOM)
{
  reduction = REDUCTION_BROOM;
}
