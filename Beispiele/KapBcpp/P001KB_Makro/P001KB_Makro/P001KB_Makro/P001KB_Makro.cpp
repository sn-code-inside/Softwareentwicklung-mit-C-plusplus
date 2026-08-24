// P001KB_Makro.cpp
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
#define GETMIN(y,x)      ((x)<(y)?(x):(y))                  //1
int main(void)
{
    //=========================================
    LPCTSTR str = L"P001KB_Makro";
    printConsole(str);
    //=========================================
    int iZ1 = 1; int iZ2 = 2;                               //2
    float fZ1 =.2f; float fZ2=3.f;
    double dZ1 = 0.200000002; 
    cout << "Min int-Vars\t\t " << iZ1 << " \t\tund " 
         << iZ2 << "\t\t: " << GETMIN (iZ1, iZ2) <<endl;    //3
    cout << "Min float-Vars\t\t " << fZ1 << " \t\tund " 
         << fZ2 << "\t\t: " << GETMIN (fZ1, fZ2) <<endl;    //4
    cout << "Min float&double-Vars\t " << fZ1 << " \t\tund ";
    cout.precision(9);                                      //5
    cout << dZ1 << " : ";
    cout << GETMIN(fZ1, dZ1) << endl;                       //6
	return 0;
}

