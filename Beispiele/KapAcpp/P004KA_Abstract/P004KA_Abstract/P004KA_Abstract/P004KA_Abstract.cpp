// P004KA_Abstract.cpp
#include "stdafx.h"
#include <iostream>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <math.h>
//#include <corecrt_math_defines.h>
using namespace std;
#include <limits>
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
    virtual double ermittleFlaeche (void)=0;                                      //1
    virtual const char* getClassName (void){const type_info * p2T = &typeid (*this);
                                      return p2T->name();}
};
class cDreieck : public cArea
{
public:
    cDreieck(double a, double b){ dA_ = a; dB_ = b; cout << ">> cDreieck\n";}
    ~cDreieck(void){cout << ">> ~cDreieck\n";}
    double ermittleFlaeche (void){ return dA_*dB_/2.0;}
    const char* getClassName (void){return cArea::getClassName();}
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
class cKreis  : public cArea
{
public:
    cKreis(double r){dR_ = r; cout << ">> cKreis\n";}
    ~cKreis(void){cout << ">> ~cKreis\n";}
    double ermittleFlaeche (void){return M_PI*dR_*dR_;}
    const char* getClassName (void){return cArea::getClassName();}
private:
    double dR_;
};
#define MAX_AREA    3
int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR str = L"P004KA_Abstract";
    printConsole(str);
    //=========================================
    cArea *area [MAX_AREA];                                                          //2
    area[0] = new cDreieck (2,3);                                                    //3
    area[1] = new cRechteck (2,3);                                                   //4
    area[2] = new cKreis (2);                                                        //5

    for (int i=0; i<MAX_AREA; i++)
    {
        cout << "Flaeche von " << area[i]->getClassName() << ": " 
             << area[i]->ermittleFlaeche() << endl;                                  //6
        delete area[i];                                                              //7
    }
    //cArea areaAbs;                                                                 //8
    return 0;
}
