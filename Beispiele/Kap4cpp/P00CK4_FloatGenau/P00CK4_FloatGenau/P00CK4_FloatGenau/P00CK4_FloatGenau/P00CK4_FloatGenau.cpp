// P00CK4_FloatGenau.cpp
#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================   
union uFloat                                                    //1
{
    float fValue;                                               //2
    unsigned int ui4FValue;                                     //3
};
int main(void)
{
    uFloat fMyFloat;                                            //4
    CONST WCHAR * str = L"P00CK4_FloatGenau";
    fMyFloat.fValue = -1.1f;                                    //5
    //=========================================

    printConsole(str);
    //========================================= 
    cout << "fMyFloat.fValue   : " << fMyFloat.fValue    << endl;//6
    cout << hex << setiosflags (ios::uppercase|ios::showbase|ios::showpos);
    cout << "fMyFloat.ui4FValue: " << fMyFloat.ui4FValue << endl;//7
    fMyFloat.ui4FValue = 0x3FE00000;                            //8
    cout << endl;
    cout << "fMyFloat.fValue   : " << fMyFloat.fValue    << endl;//9
    cout << "fMyFloat.ui4FValue: " << fMyFloat.ui4FValue << endl;//10
    return 0;
}

