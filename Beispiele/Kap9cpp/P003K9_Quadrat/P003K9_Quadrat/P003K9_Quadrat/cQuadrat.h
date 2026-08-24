#pragma once
#include "crechteck.h"
class cQuadrat : private cRechteck
{
public:
    cQuadrat(double);
    ~cQuadrat(void);
    double getFlaecheKleinQ (double);   //H1
    double getFlaeche(void);    
};

