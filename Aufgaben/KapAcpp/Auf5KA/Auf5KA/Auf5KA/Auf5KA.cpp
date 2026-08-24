// Auf5KA.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
class cArea
{
public:
    cArea(void){}
    virtual ~cArea(void){}
    virtual double ermittleFlaeche (void)=0;                                      
};
class cDreieck : public cArea
{
public:
    cDreieck(double a, double b){ dA_ = a; dB_ = b;}
    ~cDreieck(void){}
    double ermittleFlaeche (void){ return dA_*dB_/2.0;}
protected:
    double dA_; double dB_;
};
class cRechteck : public cDreieck
{
public:
    cRechteck(double a, double b):cDreieck(a, b){}
    ~cRechteck(void){}
    double ermittleFlaeche (void){ return dA_*dB_;}
};
int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR str = L"Auf5KA";
    printConsole(str);
    //=========================================
    cDreieck drei (5, 7); 
    cRechteck rect (5, 7); 
    cArea *arr[2];
    cout << "Flaeche Dreieck  : "   << drei.ermittleFlaeche () << endl;
    cout << "Flaeche cRechteck: " << rect.ermittleFlaeche () << endl;
    arr[0] = &drei;
    arr[1] = &rect;
    double dGes = .0;
    for (int i=0; i<2; i++)
        dGes += (*arr[i]).ermittleFlaeche();
    cout << "Flaeche gesamt   : " << dGes << endl;
    return 0;
}