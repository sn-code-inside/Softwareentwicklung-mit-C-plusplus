// P007K3coutHDO.cpp

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
int main(void)
{
    //=========================================
    CONST WCHAR * str = L"P007K3coutHDO";
    printConsole (str);
    //========================================= 
    cout << "Wir geben 16 und 32 in hexadezimaler, "        //1
         << "dezimaler und oktaler Form aus:\n";
    cout << "hex: " << hex << 16 << " " << 32 << endl       //2
         << "dec: " << dec << 16 << " " << 32 << endl       //3
         << "oct: " << oct << 16 << " " << 32 << endl;      //4
    return 0;
}

