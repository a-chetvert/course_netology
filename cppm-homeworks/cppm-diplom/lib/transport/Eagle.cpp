#include "Eagle.h"

#define NAME_EAGLE_RU "Орёл"
#define NAME_EAGLE_EN "Eagle"
#define SPEED_EAGLE 8
#define REDUCTION_EAGLE 0.06

double Eagle::getDistanceReduction(int distance) const
{
	return reduction;
}

Eagle::Eagle() : AirTransport(NAME_EAGLE_EN, SPEED_EAGLE)
{
	reduction = REDUCTION_EAGLE;
}

