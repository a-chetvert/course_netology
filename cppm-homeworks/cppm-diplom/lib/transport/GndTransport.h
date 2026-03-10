#pragma once
#include "Transport.h"
class GndTransport :
    public Transport
{
protected:
    int timeBeforeRest; 

public:
    virtual double calcRestTime(int restCount) const = 0;

};

