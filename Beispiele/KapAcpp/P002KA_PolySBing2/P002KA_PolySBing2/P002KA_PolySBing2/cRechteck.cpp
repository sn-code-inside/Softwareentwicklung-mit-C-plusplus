#include "stdafx.h"
#include "cRechteck.h"
#include <typeinfo>
#include <iostream>
using namespace std;
cRechteck::cRechteck(double a, double b) : cDreieck (a, b)
{
    cout << ">> cRechteck\n";
}
cRechteck::~cRechteck(void)
{
    cout << ">> ~cRechteck\n";
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
