#pragma once
class cDreieck
{
public:
    cDreieck(double, double);
    ~cDreieck(void);
    virtual double ermittleFlaeche (void);
    const char* getClassName (void);
private:
    double dA_; double dB_;
};

