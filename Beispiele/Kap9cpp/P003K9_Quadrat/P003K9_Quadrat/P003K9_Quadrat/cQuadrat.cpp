#include "stdafx.h"
#include "cQuadrat.h"
#include <iostream>
using namespace std;
cQuadrat::cQuadrat(double a) : cRechteck (a, a) {
    cout << ">> Konstruktor cQuadrat\n";
}
cQuadrat::~cQuadrat(void) {
    cout << ">> Destruktur ~cQuadrat\n";       
}
double cQuadrat::getFlaecheKleinQ (double dX)  {
    return dA_*dA_ - 2*dA_*dX + 2*dX*dX;        //CPP1
}

double cQuadrat::getFlaeche(void) {
    return getFlaecheR();
}