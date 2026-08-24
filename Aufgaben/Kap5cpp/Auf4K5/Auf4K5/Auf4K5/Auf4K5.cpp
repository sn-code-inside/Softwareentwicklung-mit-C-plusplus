// Auf4K5.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <ctime>
#include <Windows.h>   
//=============================================                             
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
#define MAX_ZAHL    10000
int main(void)
{
    double dMikroS;                     //dMikroS: Microsekunden
    int iExist;                         //iExist: Test für "high resolution counter"
    int iCount, iSum;                   //Variablen für den "kleinen Gauss"
    LARGE_INTEGER ticksPerSecond;       //Variablen für Zeitmessungen
    LARGE_INTEGER tick1, tick2; double dDTime;
    // Holt die "high resolution counter"-Genauigkeit
    //=========================================
    CONST WCHAR * str = L"Auf4K5";
    printConsole(str);
    //========================================= 
    iExist = QueryPerformanceFrequency(&ticksPerSecond);
    if (iExist==0)
        return 0;                       //Programm terminiert falls
                                        //"high resolution counter" nicht existiert.
    // Holt die aktuellen ticks
    QueryPerformanceCounter(&tick1);
    iSum=0;                             //Der "Kleine Gauss" als for-Schleife
    for(iCount=1; iCount<=MAX_ZAHL; iCount++)
        iSum+=iCount;
    QueryPerformanceCounter(&tick2);
    dDTime = (1E6)*(double) (tick2.QuadPart - tick1.QuadPart);
    dMikroS = dDTime/(double)ticksPerSecond.QuadPart;
    cout << "Zeitdauer (kleiner Gau\xe1) der for-Schleife : " << dMikroS << " /us\n";
    cout << "Die Summe der Zahlen von 1 - 10000 ist    : " << iSum << endl;
    // Holt die aktuellen ticks
    QueryPerformanceCounter(&tick1);
    iSum=(MAX_ZAHL+1)*(MAX_ZAHL/2);     //Der "Kleine Gauss" als Formel
    QueryPerformanceCounter(&tick2);
    dDTime = (1E6)*(double) (tick2.QuadPart - tick1.QuadPart);
    dMikroS = dDTime/(double)ticksPerSecond.QuadPart;
    cout << "Zeitdauer (kleiner Gau\xe1) der Formel       : " << dMikroS << " /us\n";
    cout << "Die Summe der Zahlen von 1 - 10000 ist    : " << iSum << endl;
    return 0;
}