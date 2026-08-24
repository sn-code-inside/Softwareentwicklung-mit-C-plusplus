// P006K9_xString.cpp
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
    LPCTSTR str = L"P006K9_xString";
    printConsole(str);
    //========================================= 
    xString str1("Hallo ");                                     
    xString str2("Peter!");                                     
    cout << str1.getString() << endl;
    cout << str2.getString() << endl;                           
    
    xString strRes = str1 + str2;                               
    //xString strRes = str1.addStr (str2);                      
    cout << strRes.getString() << endl;                         

    //xString strSubRes = strRes - str2;                            //1
    //cout << strSubRes.getString () << endl;                       //2
    strRes-=(str2.getString());                                     //3
    cout << strRes.getString () << endl;                            //4
    return 0;
}                                                               


