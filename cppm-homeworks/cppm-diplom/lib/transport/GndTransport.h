#pragma once
#include "Transport.h"
class GndTransport :
    public Transport
{
protected:
    int timeBeforeRest; 

    virtual double calcRestTime(int restCount) const = 0;
public:
    GndTransport(std::string name, int speed);
    virtual double calcTime(int distance) const;
};

