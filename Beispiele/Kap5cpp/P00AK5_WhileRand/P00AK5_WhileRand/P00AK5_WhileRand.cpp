// P00AK5_WhileRand.cpp
#include "stdafx.h"
#include <conio.h>                                      //1
#include <iostream>                                     //2  
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
    unsigned short int iRand;                           //3
    //=============================================
    CONST WCHAR * str = L"P00AK5_WhileRand";
    printConsole(str);
    //============================================= 
    iRand = 1;                                          //4

    while (!_kbhit())                                   //5
    {
        iRand++;                                        //6
        if  (iRand==7)                                  //7
            iRand=1;                                    //8
        cout<<"\r"<<iRand;                              //9
    }
    cout<<"\nEs wurde eine "<<iRand<<" gew\x81rfelt.\n";//10
    return 0;                                       
}