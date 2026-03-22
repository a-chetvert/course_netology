#pragma once
#include "Transport.h"
#include "LibApi.h"

class  GndTransport :
    public Transport
{
protected:
    int timeBeforeRest; 

    virtual double calcRestTime(const int restCount) const = 0;
public:
    TRANSPORTRACE_API GndTransport(std::string name, int speed);
    TRANSPORTRACE_API virtual double calcTime(int distance) const;
    TRANSPORTRACE_API TransportType getType() const override;
};

