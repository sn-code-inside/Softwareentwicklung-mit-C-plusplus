#include "cDreieck.h"
#include <typeinfo>
cDreieck::cDreieck(double a, double b) : dA_(a)
{
    dB_ = b;
}
cDreieck::~cDreieck(void)
{
}
double cDreieck::ermittleFlaeche (void)
{
    return dA_*dB_/2.0;
}
const char* cDreieck::getClassName (void)
{
    const type_info * p2T = &typeid (*this);
    return p2T->name();
}