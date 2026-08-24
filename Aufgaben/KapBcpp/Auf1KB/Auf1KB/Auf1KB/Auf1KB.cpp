// Auf1KB.cpp : 
#include "stdafx.h"
#include <iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
template <typename T> void xSwap (T &x, T &y)                 
{
    T tTemp = x;
    x = y;
    y = tTemp;
}

int main(void)
{
    //=========================================
    LPCTSTR str = L"Auf1KB";
    printConsole(str);
    //=========================================
    int iZ1    = 1; int iZ2         = 2;                               
    double dZ1 = M_E; double dZ2    = M_PI;
    char *str1 = "Hans"; char *str2 = "Peter";
    cout << "Vor Tausch:\n";
    cout << "iZ1: "  << iZ1  << ";\t\tiZ2: " << iZ2 << endl;
    cout << "dZ1: "  << dZ1  << ";\tdZ2: "   << dZ2 << endl;    
    cout << "str1: " << str1 << ";\tstr2: "  << str2 << endl << endl;   
    xSwap (iZ1, iZ2);
    xSwap (dZ1, dZ2);
    xSwap (str1, str2);
    cout << "Nach Tausch:\n";
    cout << "iZ1: "  << iZ1  << ";\t\tiZ2: " << iZ2 << endl;
    cout << "dZ1: "  << dZ1  << ";\tdZ2: "   << dZ2 << endl;
    cout << "str1: " << str1 << ";\tstr2: "  << str2 << endl; 
	return 0;
}

