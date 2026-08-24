// Auf1KA.cpp: 
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
    cArea(void){cout << ">> cArea\n";}
    virtual ~cArea(void){cout << ">> ~cArea\n";}
    virtual double ermittleFlaeche (void)=0;                                      
};
class cDreieck : public cArea
{
public:
    cDreieck(double a, double b){ dA_ = a; dB_ = b; cout << ">> cDreieck\n";}
    ~cDreieck(void){cout << ">> ~cDreieck\n";}
    double ermittleFlaeche (void){ return dA_*dB_/2.0;}
private:
    double dA_; double dB_;
};

int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR str = L"Auf1KA";
    printConsole(str);
    //=========================================
    //cArea area; 
    //cout << "Flaeche Flaeche: " <<  area.ermittleFlaeche() << endl;
    cDreieck drei (5, 7); 
    cout << "Flaeche Dreieck: " << drei.ermittleFlaeche () << endl;
    return 0;
}
