// P002KB_TemplFkt.cpp
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
template <typename T> T getMin (T x, T y)                   //1
{
  return x<y ? x:y;
}
template <typename T> bool isFirstMin (T x, T y)                  
{
  return x<y ? true:false;
}
template <typename T1, typename T2> T2 getMin (T1 x, T2 y) 
{  
    return (T2)x<y ? (T2)x:y; 
}
int main(void)
{
    //=========================================
    LPCTSTR str = L"P002KB_TemplFkt";
    printConsole(str);
    //=========================================
    int iZ1 = 1; int iZ2 = 2;                               //2
    float fZ1 =.2f; float fZ2=3.f;
    double dZ1 = 0.200000002; 
    cout << "Min der int-Var   " << iZ1 << " \tund " 
         << iZ2 << ": " << getMin (iZ1, iZ2) <<endl;        //3
    cout << "Min der float-Var " << fZ1 << " \tund " 
         << fZ2 << ": " << getMin (fZ1, fZ2) <<endl;        //4
    cout.precision (9);                                     //5
    cout << "Min float&double  " << fZ1 << " \tund " 
         << dZ1 << ": " << getMin (fZ1, dZ1) <<endl;        //6

    bool bFirst = isFirstMin (iZ1, iZ2);                    //7
    cout << "Erste Zahl: "    << iZ1 
         << ". Zweite Zahl: " << iZ2 << endl;
    cout << "Die erste Zahl ist das Minimum ist " 
         << boolalpha << bFirst << ".\n";                   //8
	return 0;
}

