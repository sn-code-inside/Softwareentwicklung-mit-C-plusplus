// Auf9K4.cpp 
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <cmath>
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
    CONST WCHAR * str = L"Auf9K4";
    printConsole(str);
    //========================================= 
    union uFloatInt
    {
        float fValue;
        int iValue;
    } uFI;
    uFI.fValue = -1.75f; 

    for (int i=31; i>=0; i--)
    {
        if ( (uFI.iValue) & ((int)pow (2,i)) )
            cout << "I";
        else
            cout << "0";
        if (i%8==0)
            cout << " "; 
    }
    return 0;
}