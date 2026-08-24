// P004K9FuncOL.cpp
#include "stdafx.h"
#include <iostream>
#include <typeinfo>                                                 //1
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================

void ichBin (char chr)                                              //2
{
    const type_info *p2TI = &typeid (chr);  
    cout << "Ich bin ein " << p2TI->name() 
         << " und heisse " << chr << endl;
}
void ichBin (int  iInt)                                             //3
{
    const type_info *p2TI = &typeid (iInt);  
    cout << "Ich bin ein " << p2TI->name() 
         << " und heisse " << iInt << endl;
}
void ichBin (float  fFloat)                                         //4
{
    const type_info *p2TI = &typeid (fFloat);  
    cout << "Ich bin ein " << p2TI->name() 
         << " und heisse " << fFloat << endl;
}


int main(void)
{
    //=========================================
    LPCTSTR str = L"P004K9FuncOL";
    printConsole(str);
    //========================================= 
    ichBin ('A');                                                   //5
    ichBin (4711);
    ichBin (3.14159f);
    return 0;
}                                                               


