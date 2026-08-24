#include "stdafx.h"
#include "cDreieck.h"
#include <typeinfo>
#include <iostream>
using namespace std;
cDreieck::cDreieck(double a, double b) : dA_(a)
{
    dB_ = b;
    cout << ">> cDreieck\n";
}
cDreieck::~cDreieck(void)
{
    cout << ">> ~cDreieck\n";
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
