// P007K4_Unions
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
    union tUnion                                 //1
    {
        float fZahl;                             //2
        int iZahl;                               //3
    };
    tUnion myUnion;                              //4
    //=========================================
    CONST WCHAR * str = L"P007K4_Unions";
    printConsole(str);
    //=========================================  
    myUnion.iZahl = 1077936128;                  //5
    cout << "iZahl  : " << myUnion.iZahl << endl;//6
    cout << "fZahl  : " << myUnion.fZahl << endl;//7
    myUnion.iZahl-=4194304;                      //8
    cout << "iZahl  : " << myUnion.iZahl << endl;//9
    cout << "fZahl  : " << myUnion.fZahl << endl;//10
    return 0;
}