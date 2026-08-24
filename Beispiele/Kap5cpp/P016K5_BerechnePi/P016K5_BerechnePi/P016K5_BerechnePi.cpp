// P016K5_BerechnePi.cpp

#include <cmath >
#include <iostream>
#include <iomanip>
using namespace std;
//=============================================    
#include <Windows.h>   
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
//=============================================
double getSiPlus1_ShortFormula (double dSi)                         //1
{
    double dSiPlus1 = .0;
    dSiPlus1 = sqrt(2.-sqrt(4.-dSi*dSi));
    return dSiPlus1;
}

int main(void)
{
    double dBckPi = 3.;                                             //2
    double dPi    = 3.;                                             //3
    int    iEdges = 12;                                             //4
    double dSi    = 1.;                                             //5

    //=========================================
    CONST WCHAR* str = L"P016K5_BerechnePi";
    printConsole(str);
    //========================================= 

    do {
        cout.width(13);                                             //6
        dBckPi = dPi;
        cout << iEdges << "-Eck:  ";                                //7
        dSi = getSiPlus1_ShortFormula(dSi);                         //8
        dPi = (double)iEdges * dSi / 2.;                            //9
        cout << setprecision(10) << dSi << "\t\t" << dPi << endl;   //10
        iEdges = 2 * iEdges;                                        //11
    } while(dPi - dBckPi > 1.0E-7);                                 //12
    return 0;
}

