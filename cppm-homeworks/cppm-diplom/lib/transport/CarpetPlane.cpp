#include "CarpetPlane.h"

const char* NAME_CARPET_PLANE_RU = "Ковёр-самолёт";
// скорость ковра самолёта
const int SPEED_CARPET_PLANE = 10;

// Границы расстояний
const int SHORT_DISTANCE_LIMIT = 1000;   // До 1000 - без сокращения
const int MEDIUM_DISTANCE_LIMIT = 5000;  // До 5000 - 3%
const int LONG_DISTANCE_LIMIT = 10000;   // До 10000 - 10%

// Коэф. сокращения дистанции
const double MEDIUM_DISTANCE_DISCOUNT = 0.03; // 3%
const double LONG_DISTANCE_DISCOUNT = 0.10;   // 10%
const double VERY_LONG_DISTANCE_DISCOUNT = 0.05; // 5%

double CarpetPlane::getDistanceReduction(int distance) const
{
  if (distance < SHORT_DISTANCE_LIMIT) {
    return 0.0;
  }
  else if (distance < MEDIUM_DISTANCE_LIMIT) {
    return MEDIUM_DISTANCE_DISCOUNT;
  }
  else if (distance < LONG_DISTANCE_LIMIT) {
    return LONG_DISTANCE_DISCOUNT;
  }
  else {
    return VERY_LONG_DISTANCE_DISCOUNT;
  }
}

CarpetPlane::CarpetPlane() : AirTransport(NAME_CARPET_PLANE_RU, SPEED_CARPET_PLANE)
{

}
