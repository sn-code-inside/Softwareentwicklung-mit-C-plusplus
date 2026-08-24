#pragma once
class CQuader
{
public:
    CQuader(double, double, double);
    ~CQuader(void);
    double ermittleVolumen (void);
    double ermittleOberflaeche (void);
private:
    double dA_;
    double dB_;
    double dC_;
};

