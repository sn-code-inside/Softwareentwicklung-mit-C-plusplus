// Auf3K7.cpp : 
#include "stdafx.h"
#include <iostream>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
void test(void)
{
    cout << "Funktion test\n";
    throw 1;
}
//=============================================                                                                                  
int main (void)
{                                       
    //=========================================
    CONST WCHAR * str = L"Auf3K7";
    printConsole(str);
    //========================================= 
    try {
        test();
    }
    catch (int i)
    {
        cout << "Fehler: " << i << endl;
    }
    catch (...)
    {
        cout << "Fehler im main-Programm\n";
    }
    return 0;
}