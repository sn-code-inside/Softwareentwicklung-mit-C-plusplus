// Auf2K9.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include "wuerfel.h"
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================

int main(void)
{
    //=========================================
    LPCTSTR str = L"Auf2K9";
    printConsole(str);
    //=========================================
    double dA = 1.0; double dB = 2.0; double dC = 3.0;
    CQuader quad (dA, dB, dC);
    cout << "Volumen Quader      : " << quad.ermittleVolumen() << endl;    
    cout << "Obereflaeche Quader : " << quad.ermittleOberflaeche() << endl <<endl;

    CWuerfel wuerf (2.0);
    cout << "Volumen Wuerfel     : " << wuerf.ermittleVolumen() << endl;    
    cout << "Obereflaeche Wuerfel: " << wuerf.ermittleOberflaeche() << endl;
    return 0;
}