// P00AK4_decltype
#include "stdafx.h"
#include <iostream>
#include <typeinfo>
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
    auto iTest = 42;                                                   //1
    decltype (iTest) iTest2=43;                                        //2
    auto iTest3 = 44; 

    //=========================================
    CONST WCHAR * str = L"P00AK4_decltype";
    printConsole(str);
    //========================================= 
    cout << "Ausgabe der Variablen und deren Typ:\n";
    const type_info *p2TI = &typeid (iTest);                            //3
    cout << "iTest hat den Wert von : " << iTest << "; der Typ von iTest ist  : " 
         << p2TI->name() << endl;         
    p2TI = &typeid (iTest2);
    cout << "iTest2 hat den Wert von: " << iTest2<< "; der Typ von iTest2 ist : " 
        << p2TI->name() << endl; 
    p2TI = &typeid (iTest3);
    cout << "iTest3 hat den Wert von: " << iTest3<< "; der Typ von iTest3 ist : " 
        << p2TI->name() << endl;         
    return 0;
}

