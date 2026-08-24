// Auf3K5.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <ctime>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
#define MAX_BUFF 128
int main (void)
{
    int  iNumb;
    time_t tCurrTime;
    struct tm tLocalTime;
    char strDateTime[MAX_BUFF];
    //=========================================
    CONST WCHAR * str = L"Auf3K5";
    printConsole(str);
    //========================================= 
    cout << "Geben Sie eine Zahl (iNumb) ein (1<=iNumb<=3).\n"
         << "Sichern Sie Datum und Uhrzeit der Eingabe auf der Konsole.\n";
    cout << "=== Start Eingabe ===================\nEingabe: ";
    cin >> iNumb;
    cout << "=== Ende Eingabe ====================\n";
    tCurrTime = time (NULL);
    localtime_s (&tLocalTime, &tCurrTime );
    strftime (strDateTime, MAX_BUFF, "%d.%m.%Y %H:%M:%S", &tLocalTime);
    switch (iNumb)
    {
        case 1: case 2: case 3:
        {
            cout << "Es wurde die Zahl " << iNumb << " eingegeben.\n";
            cout << "Die Zahl " << iNumb << " wurde am " << strDateTime << " eingegeben\n";
        }
        break;
        default:
        {
            cout << "Fehler: Es wurde die Zahl " << iNumb << " eingegeben.\n";
            cout << "Die fehlerhafte Eingabe erfolgte am: " << strDateTime << endl;
        }
    }
    return 0;
}