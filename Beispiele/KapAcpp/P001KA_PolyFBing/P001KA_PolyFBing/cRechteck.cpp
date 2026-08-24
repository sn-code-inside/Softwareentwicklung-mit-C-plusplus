#include "cRechteck.h"
#include <typeinfo>
#include <iostream>
using namespace std;
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
const char* cRechteck::getClassName (void)
{
    const type_info * p2T = &typeid (*this);
    return p2T->name();
}