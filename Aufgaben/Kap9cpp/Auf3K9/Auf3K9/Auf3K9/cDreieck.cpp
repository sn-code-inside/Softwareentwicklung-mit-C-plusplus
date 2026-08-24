#include "stdafx.h"
#include "cDreieck.h"
cDreieck::cDreieck(double a, double b)
{
    dA_ = a; dB_ = b;
}
cDreieck::~cDreieck(void)
{
}
double cDreieck::ermittleFlaeche (void)
{
    return dA_*dB_/2.0;
}
