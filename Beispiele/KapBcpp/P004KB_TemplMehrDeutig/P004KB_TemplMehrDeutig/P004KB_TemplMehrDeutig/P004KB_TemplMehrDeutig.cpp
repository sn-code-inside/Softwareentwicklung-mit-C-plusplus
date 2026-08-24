// P004KB_TemplMehrDeutig.cpp 
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <typeinfo>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
template <typename T> T add (T x, T y)                          //1                
{
    const type_info *p2TIx = &typeid (x);
    const type_info *p2TIy = &typeid (y);
    cout << ">> Typ x: "  << p2TIx->name() << "; Typ y: " 
         << p2TIy->name() << endl;                              //2
    return (x+y);                                           
}

int main(void)
{
    //=========================================
    LPCTSTR str = L"P004KB_TemplMehrDeutig";
    printConsole(str);
    //=========================================
    int    iZ1 = 1;   int    iZ2 = 2;                           //3
    double dZ1 = 1.5; double dZ2 = 2.0;
    cout << "int Add\t\t\t: "              << iZ1 << "\t+ " 
         << iZ2 << " = " << add (iZ1, iZ2) << "\n\n";           //4
    cout << "double Add\t\t: "             << dZ1 << "\t+ " 
         << dZ2 << " = " << add (dZ1, dZ2) << "\n\n";           //5
    cout << "int/double Add<int>\t: "      << iZ1 << "\t+ " 
         << dZ1 << " = " << add<int> (iZ1, (int)dZ1)<< "\n\n";  //6
    cout << "int/double Add<double>\t: "   << iZ1 << "\t+ " 
         << dZ1 << " = " << add<double> (iZ1, dZ1)<< "\n\n";    //7
    return 0;
}

