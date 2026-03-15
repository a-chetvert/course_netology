#include "Race.h"

void Race::start() {

}


const std::string NAME_BROOM_EN = "Broom";

/**
*
*/
bool Race::isSuitableType(Transport* transport) const
{
  switch (type) {
  case RaceType::all:
    return true;
  case RaceType::air:
    return !(transport->isGnd()); 
  case RaceType::gnd:
    return transport->isGnd();
  default:
    return false;
  }
}

Race::Race(double distance, RaceType type)
  : distance(distance), type(type) {

};

double Race::getDistance() const {
  return distance;
}

RaceType Race::getRaceType() const {
  return type;
}

bool Race::registerTransport(Transport* transport) {
  //TODO
  if (isSuitableType(transport) && 0)
    return true;
  else 
    return false;
}

bool Race::isAlreadyRegistered(Transport* transport) {
  //TODO
  return false;
}
