// P003KB_TemplFkt2.cpp
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
int getMin (int x, int y)                                   //1
{
    cout << ">> Funktion\t\t\t: " << __FUNCTION__ << endl;
    return x<y ? x:y;
}
template <typename T> T getMin (T x, T y)                   //2
{
    cout << ">> Template - ein Typ\t\t: " << __FUNCTION__ << endl;
    return x<y ? x:y;
}
template <typename T1, typename T2> T2 getMin (T1 x, T2 y)  //3
{
    cout << ">> Template - zwei Typen\t: " << __FUNCTION__ << endl;
    return x<y ? x:y;
}
template <typename T> bool isFirstMin (T x, T y)            //4
{
     cout << ">> Funktion\t\t\t: " << __FUNCTION__ << endl;
    return x<y ? true:false;
}
int main(void)
{
    //=========================================
    LPCTSTR str = L"P003KB_TemplFkt2";
    printConsole(str);
    //=========================================
    int iZ1 = 1; int iZ2 = 2;                               
    float fZ1 =.2f; float fZ2=3.f;
    double dZ1 = 0.200000002; 
    cout << "Min int  &int   :" << iZ1 << " \t\tund " 
         << iZ2 << "\t\t: " << getMin (iZ1, iZ2) <<endl;    //4
    cout << "Min float&float :" << fZ1 << " \t\tund " 
         << fZ2 << "\t\t: " << getMin (fZ1, fZ2) <<endl;    //5
    cout.precision (9);                                     
    cout << "Min float&double:" << fZ1 << " \tund "  
         << dZ1 << "\t: " << getMin (fZ1, dZ1) <<endl<<endl;//6


    bool bFirst = isFirstMin (iZ1, iZ2);                    //7
    cout << "Erste Zahl: "    << iZ1 
         << ". Zweite Zahl: " << iZ2 << endl;
    cout << "Die erste Zahl ist das Minimum ist " 
         << boolalpha << bFirst << ".\n";                   //8
	return 0;
}

