#include "stdafx.h"
#include "cQuadrat.h"
#include <iostream>
using namespace std;
cQuadrat::cQuadrat(double a) : cRechteck (a, a)
{
    cout << ">> Konstruktor cQuadrat\n";    
}
cQuadrat::~cQuadrat(void)
{
    cout << ">> Destruktur ~cQuadrat\n";       
}
