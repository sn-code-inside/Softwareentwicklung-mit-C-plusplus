// P00BK5_WhileRand2.cpp
#include "stdafx.h"
#include <conio.h>                              //1 
#include <cstdlib>                              //2
#include <iostream>                             //3
using namespace std;
#include <ctime>                                //4              
#include <Windows.h>                            //5
//=============================================    
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
int main (void)
{                   
    int iRand;                                  //6
    time_t t;                                   //7
    //=============================================
    CONST WCHAR * str = L"P00BK5_WhileRand2";
    printConsole(str);
    //============================================= 
    t = time(NULL);                             //8
    srand( (unsigned)t );                       //9
    while(! _kbhit() )                          //10
    {
        iRand = rand();                         //11
        iRand &=0x7;                            //12
        if ( (iRand==7) || (iRand==0) )         //13
            continue;                           //14
        cout << iRand << "   ";                 //15  
        Sleep (100);                            //16
    }
    return 0;                                   //17                            
}