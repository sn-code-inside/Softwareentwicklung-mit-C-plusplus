#include "stdafx.h"
#include "cRechteck.h"
cRechteck::cRechteck(double a, double b) : cDreieck (a, b)
{
}
cRechteck::~cRechteck(void)
{
}
double cRechteck::ermittleFlaeche (void)
{
    return 2*cDreieck::ermittleFlaeche();
}