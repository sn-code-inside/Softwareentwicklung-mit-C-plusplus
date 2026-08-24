#include "cQuadrat.h"
#include <typeinfo>
#include <iostream>
using namespace std;
cQuadrat::cQuadrat(double a) : cRechteck (a, a)
{
}
cQuadrat::~cQuadrat(void)
{
}
const char* cQuadrat::getClassName (void)
{
    const type_info * p2T = &typeid (*this);
    return p2T->name();
}