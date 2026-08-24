// P002KA_PolySBing2.cpp
#include "stdafx.h"
#include <iostream>
#include <typeinfo>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
class cDreieck
{
public:
    cDreieck(double a, double b){ dA_ = a; dB_ = b; cout << ">> cDreieck\n";}
    virtual ~cDreieck(void){cout << ">> ~cDreieck\n";}
    double ermittleFlaeche (void){ return dA_*dB_/2.0;}
    const char* getClassName (void){const type_info * p2T = &typeid (*this);
                                    return p2T->name();}
private:
    double dA_; double dB_;
};
class cRechteck : public cDreieck
{
public:
    cRechteck(double a, double b): cDreieck (a, b) {cout << ">> cRechteck\n";}
    ~cRechteck(void){cout << ">> ~cRechteck\n";}
    double ermittleFlaeche (void){return 2*cDreieck::ermittleFlaeche();}
    const char* getClassName (void){return cDreieck::getClassName();}
};



int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR str = L"P002KA_PolySBing2";
    printConsole(str);
    //=========================================
    cDreieck *drei= new cRechteck (2,3);  
    cout << "Name   : " << drei->getClassName () << endl;                    
    cout << "Flaeche: " << drei->ermittleFlaeche () << endl << endl;
    delete drei;
}

