// Auf1K7.cpp
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
int main (void)
{                                       
    //=========================================
    CONST WCHAR * str = L"Auf1K7";
    printConsole(str);
    //========================================= 
    try {
        int iRes = 0;
        float fRes = .0f;
        for (int iIdx=3; iIdx>-1; iIdx--)
        {
            fRes = 3.0f/(float)(iIdx);
            cout << "fRes: " << fRes << endl;
            iRes = 3/iIdx;
            cout << "iRes: " << iRes << endl;
        }
    }
    catch (...)
    {
        cout << "Fehler im main-Programm\n";
    }
    return 0;
}