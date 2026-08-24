// P006KB_String.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string.h>                                       //1
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
    {
    LPCTSTR str = L"P006KB_String";
    printConsole(str);
    }
    //=========================================
    string str1("Hallo ");                              //2                       
    string str2("Peter!"); 
    string strRes;
    cout << str1 << endl;
    cout << str2 << endl << endl;                         
    
    strRes = str1 + str2;                               //3
    cout << strRes << endl;
    //string strSubRes = strRes - str2;                 //4
    return 0;
}

