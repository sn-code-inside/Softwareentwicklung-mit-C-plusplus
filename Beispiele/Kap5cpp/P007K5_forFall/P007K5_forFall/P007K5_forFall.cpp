// P007K5_forFall.cpp
#include "stdafx.h"
#include <iostream>                 //1
#include <Windows.h>                //2
//=============================================
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
int main (void)
{
    int i=0;                        //3
    //=============================================
    CONST WCHAR * str = L"P007K5_forFall";
    printConsole(str);
    //============================================= 
    for (i=0; i<5; i++);            //4 Fehler: ; nach for-Schleife
        std::cout << i << "\n";     //5

    for (;;)                        //6
    {
        std::cout << "\r       ";   //7
        Sleep (250);                //8
        std::cout << "\rendless";   //9
        Sleep (250);
    }
    return 0;                       //10
}