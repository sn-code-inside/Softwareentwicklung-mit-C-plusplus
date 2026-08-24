#pragma once
#include "cdreieck.h"
class cRechteck :
    public cDreieck
{
public:
    cRechteck(double, double);
    ~cRechteck(void);
    double ermittleFlaeche (void);
};

