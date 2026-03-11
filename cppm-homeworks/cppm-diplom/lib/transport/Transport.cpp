#include "Transport.h"

Transport::Transport(std::string name, int speed) : name(name), speed(speed) {};

const std::string Transport::getName() const
{
	return name;
}

