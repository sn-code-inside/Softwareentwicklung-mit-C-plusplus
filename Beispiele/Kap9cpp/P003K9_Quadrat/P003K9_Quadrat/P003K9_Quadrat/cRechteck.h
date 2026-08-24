#pragma once                          
class cRechteck
{
public:
    cRechteck(double, double);        
    ~cRechteck(void);
    double getFlaecheR (void);
    double getUmfang (void);

protected:
    double dA_;                         //H1
    double dB_;
};

