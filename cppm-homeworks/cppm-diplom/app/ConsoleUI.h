#pragma once
#include <iostream>
#include <vector>
#include "Race.h"
#include "Transport.h"

void printMenu();
RaceType chooseRaceType();
double chooseDistance();
void registerTransports(Race& race, const std::vector<Transport*>& allTransport);
bool checkRace(const Race& race);