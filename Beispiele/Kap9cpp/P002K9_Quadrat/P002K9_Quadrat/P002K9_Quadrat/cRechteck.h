#pragma once                            //H1
class cRechteck
{
public:
    cRechteck(double, double);          //H2
    ~cRechteck(void);
    double getFlaeche (void);
    double getUmfang (void);

private:
    double dA_;                         //H3
    double dB_;
};

