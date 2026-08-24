// P005K9_xString.cpp
#include "stdafx.h"
#include "xString.h"                                            //1
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
    LPCTSTR str = L"P005K9_xString";
    printConsole(str);
    //========================================= 
    xString str1("Hallo ");                                     //2
    xString str2("Peter!");                                     //3
    cout << str1.getString() << endl;
    cout << str2.getString() << endl;                           //4
    
    xString strRes = str1 + str2;                               //5
    //xString strRes = str1.addStr (str2);                       
    cout << strRes.getString() << endl;                         //6
    return 0;
}                                                               


