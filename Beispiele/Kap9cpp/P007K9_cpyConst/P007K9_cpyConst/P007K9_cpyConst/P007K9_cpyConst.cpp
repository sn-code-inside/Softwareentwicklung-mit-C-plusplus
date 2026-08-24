// P007K9_cpyConst.cpp
#include "stdafx.h"
#include "xString.h"                                            
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
    LPCTSTR str = L"P007K9_cpyConst";
    printConsole(str);
    //========================================= 
    xString str1("Hallo ");                     //1                         
    xString str2 = str1;                        //2
    xString str3;                               //3
    str3 = str1;                                //4
    str3+="3";                                  //5
    str2+="2";
    str1+="1";
    cout << str1.getString() << endl;           //6
    cout << str2.getString() << endl; 
    cout << str3.getString() << endl;   
    
    return 0;
}                                               //7                                                      


