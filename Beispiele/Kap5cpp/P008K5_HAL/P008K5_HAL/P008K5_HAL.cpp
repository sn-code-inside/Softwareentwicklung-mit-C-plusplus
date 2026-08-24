// P008K5_HAL.cpp
#include "stdafx.h"
#include <iostream>                                     //1
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
    int iZeile;                                         //2
    int iSpalte;                                        //3
    //=============================================
    CONST WCHAR * str = L"P008K5_HAL_0";
    printConsole(str);
    //============================================= 
    for (iZeile = 1; iZeile<0x10; iZeile++)             //4
    {
        for (iSpalte=0; iSpalte<0x10; iSpalte++)        //5
        {
            cout << hex << iZeile*0x10+iSpalte << " "   //6
                 << (char)(iZeile*0x10+iSpalte)<< "|";  //7
        }
        cout << endl;
    }
    return 0;                                           //8
}