#include "GndTransport.h"

GndTransport::GndTransport(std::string name, int speed)
	: Transport(name, speed)
{
}
double GndTransport::calcTime(int distance) const
{
	return 0.0;
}
;
