#include "stdafx.h"
#include "cRechteck.h"                          //CPP1
#include <iostream>
using namespace std;

cRechteck::cRechteck(double a, double b)        //CPP2       
{
    dA_ = a;                                    //CPP3
    dB_ = b;
    cout << ">> Konstruktor cRechteck\n";       
}

cRechteck::~cRechteck(void)
{
    cout << ">> Destruktur ~cRechteck\n";       //CPP4
}

double cRechteck::getFlaeche (void)             //CPP5
{
    return dA_*dB_;
}
double cRechteck::getUmfang (void)              //CPP6
{
    return 2.0*(dA_ + dB_);
}
