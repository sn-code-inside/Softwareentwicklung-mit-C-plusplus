#include "stdafx.h"
#include "Quader.h"


CQuader::CQuader(double a, double b, double c)
{
    dA_ = a; dB_ = b; dC_ = c;
}


CQuader::~CQuader(void)
{
}

double CQuader::ermittleVolumen (void)
{
    return dA_*dB_*dC_;
}

double CQuader::ermittleOberflaeche (void)
{
    return 2*(dA_*dB_) + 2*(dA_*dC_) + 2*(dB_*dC_);
}
