#include "stdafx.h"
#include "cRechteck.h"                          
#include <iostream>
using namespace std;
cRechteck::cRechteck(double a, double b)              
{
    dA_ = a;                                    
    dB_ = b;
    cout << ">> Konstruktor cRechteck\n";       
}
cRechteck::~cRechteck(void)
{
    cout << ">> Destruktur ~cRechteck\n";       
}
double cRechteck::getFlaecheR (void)             
{
    return dA_*dB_;
}
double cRechteck::getUmfang (void)              
{
    return 2.0*(dA_ + dB_);
}
