// Auf1K5.cpp
#include "stdafx.h"
#include <iostream>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
using namespace std;
int main (void)
{
    int iInt1, iInt2;
    //=========================================
    CONST WCHAR * str = L"Auf1K5";
    printConsole(str);  
    //========================================= 
    cout << "Geben Sie zwei Integer-Variablen ein\n";
    cin >> iInt1; cin >> iInt2;
    if (iInt1>iInt2)
        cout << "Das Maximum von " << iInt1 << " und " << iInt2 << " ist: " << iInt1;
    else
        cout << "Das Maximum von " << iInt1 << " und " << iInt2 << " ist: " << iInt2;
    return 0;
}
