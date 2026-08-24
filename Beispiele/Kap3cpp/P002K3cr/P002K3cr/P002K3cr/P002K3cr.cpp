// P002K3cr.cpp

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
    CONST WCHAR * str = L"P002K3cr";
    printConsole (str);
    //========================================= 
    cout << 1000;   //1
    cout << "\r";   //2
    cout << 999;    //3
    return 0;
}