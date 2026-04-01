#include "Eagle.h"

const char* NAME_EAGLE_RU = "Орёл";
const int  SPEED_EAGLE{ 8 };
const double REDUCTION_EAGLE{ 0.06 };

double Eagle::getDistanceReduction(double distance) const
{
	(void) distance;
	return reduction;
}

Eagle::Eagle() : AirTransport(NAME_EAGLE_RU, SPEED_EAGLE)
{
	reduction = REDUCTION_EAGLE;
}

