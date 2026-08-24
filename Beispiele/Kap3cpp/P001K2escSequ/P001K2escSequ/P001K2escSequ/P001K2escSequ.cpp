// P001K3escSequ.cpp

#include "stdafx.h"
#include <iostream>             //1
using namespace std;            //2
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
    CONST WCHAR * str = L"P001K3escSequ"; 
    printConsole (str);
    //=========================================     
    cout << "1";                //3
    cout << "\r";               //4
    cout << "\n";               //5
    cout << "!\t!";             //6
    cout << "\n!01234567";      //7
    cout << "\b\b\b\b\b\b\b\b"; //8
    return 0;
}

