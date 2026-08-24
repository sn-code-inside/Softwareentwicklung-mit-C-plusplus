// Auf2K5.cpp
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
    int iInt1, iInt2;
        //=========================================
    CONST WCHAR * str = L"Auf2K5";
    printConsole(str);  
    //========================================= 
    cout << "Geben Sie zwei Integer-Variablen ein\n";
    cin >> iInt1; cin >> iInt2;
    cout << "Das Maximum von " << iInt1 << " und " << iInt2 
         << " ist: " << (iInt1>iInt2?iInt1:iInt2);
    return 0;
}