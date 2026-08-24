// Auf3K9.cpp
#include "stdafx.h"
#include <iostream>
#include "cQuadrat.h"
using namespace std;
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
    LPCTSTR str = L"Auf3K9";
    printConsole(str);
    //=========================================
    double dA = 1.0; double dB = 2.0;
    cDreieck drei (dA, dB);
    cRechteck recht (dA, dB);
    cQuadrat quadr (dA);
    cout << "Flaeche Dreieck : " << drei.ermittleFlaeche() << endl ;
    cout << "Flaeche Rechteck: " << recht.ermittleFlaeche() << endl;
    cout << "Flaeche Quadrat : " << quadr.ermittleFlaeche() << endl;

    return 0;
}