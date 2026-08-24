// Auf3K3.cpp
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
    CONST WCHAR * str = L"Auf3K3";
    printConsole(str);
    //=========================================     
    short int siTest;
    cin >> siTest; 
    cout << char(siTest) << endl; 
	return 0;
}

