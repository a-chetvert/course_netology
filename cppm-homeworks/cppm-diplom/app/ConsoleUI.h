#pragma once
#include <iostream>
#include <vector>
#include "Race.h"
#include "Transport.h"  // заголовок, который включает все конкретные классы

void printMenu();
RaceType chooseRaceType();
double chooseDistance();
void registerTransports(Race& race, const std::vector<Transport*>& allTransport);
bool checkRace(Race& race);