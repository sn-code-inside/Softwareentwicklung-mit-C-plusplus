// P015K5_Semi.cpp
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
    int iCount;                                 //1                                                      
    //=========================================
    CONST WCHAR * str = L"P015K5_Semi";
    printConsole(str);
    //========================================= 
    for (iCount=0; iCount<3; iCount++);         //2
        cout << "iCount: " << iCount << endl;

    if (iCount>4);                              //3
        cout << "iCount: " << iCount << endl;

    while (iCount>0);                           //4 
    {
        iCount--;
        cout << "iCount: " << iCount << endl;
    }
    return 0;                                       
}