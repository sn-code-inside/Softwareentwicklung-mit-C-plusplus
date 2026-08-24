// P004K5_switch.cpp 
#include "stdafx.h"
#include <iostream>                                                 //1   
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
    char cChr;                                                       //2
    int iIdx;
    //=============================================
    CONST WCHAR * str = L"P004K5_switch";
    printConsole(str);
    //============================================= 
    for (iIdx = 0; iIdx<4; iIdx++)                                  //3
    {
        cin >> cChr;                                                //4
        switch (cChr)                                               //5
        {
            case 'a':                                               //6
            case 0x41:                                              //7
                cout << "Es wurde " << cChr << " eingegeben.\n";    //8
                break;                                              //9
            case 'b':                                               //10
                cout << "Es wurde " << cChr << " eingegeben.\n";   
                break;
            default:                                                //11
                cout << "Es wurde " << cChr << " eingegeben.\n"; 
                break;                                              //12
        }
    }
    return 0 ;
}