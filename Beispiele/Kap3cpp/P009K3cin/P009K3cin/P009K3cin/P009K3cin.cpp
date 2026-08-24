// P009K3cin 
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
    CONST WCHAR * str = L"P009K3cin";
    printConsole (str);
    //========================================= 
    int iTest = 0;                                          //1
    char cStr[3] = "ab";                                    //2
    cout << "iTest vor Stringeinagbe : " << iTest << endl;  //3
    cout << "cStr vor Stringeinagbe  : " << cStr  << endl;  //4
    cin >> cStr;                                            //5
    cout << "iTest nach Stringeinagbe: " << iTest << endl;  //6
    cout << "cStr nach Stringeinagbe : " << cStr  << endl;  //7
    return 0;
}

