// P005K5_for.cpp
#include "stdafx.h"
#include <iostream>              //1
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
    int i;                      //2
    //=============================================
    CONST WCHAR * str = L"P005K5_for";
    printConsole(str);
    //============================================= 
    for (i=0; i<3; i++)         //3  
        cout << i << "\n";      //4
    return 0;
}