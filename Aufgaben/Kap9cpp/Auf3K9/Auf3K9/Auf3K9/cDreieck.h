#pragma once
class cDreieck
{
public:
    cDreieck(double, double);
    ~cDreieck(void);
    double ermittleFlaeche (void);
private:
    double dA_; double dB_;
};

