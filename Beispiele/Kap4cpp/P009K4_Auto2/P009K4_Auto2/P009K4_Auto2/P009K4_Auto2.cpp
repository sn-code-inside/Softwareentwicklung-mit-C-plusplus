// P009K4_Auto2
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
    auto cTest = 'A';                                                   //1
    auto iTest = 3;                                                     
    auto fTest = 3.14f;                                                 
    auto dTest = 22./7.;  
    //=========================================
    CONST WCHAR * str = L"P009K4_Auto2";
    printConsole(str);
    //========================================= 
    cout << "Ausgabe der Typ-Bezeichner der auto-Variablen:\n";
    const type_info *p2TI = &typeid (cTest);                            //2
    cout << "Der Typ von aTest ist: " << p2TI->name() << endl;          //3
    p2TI = &typeid (iTest);
    cout << "Der Typ von iTest ist: " << p2TI->name() << endl;
    p2TI = &typeid (fTest);
    cout << "Der Typ von fTest ist: " << p2TI->name() << endl;
    p2TI = &typeid (dTest);
    cout << "Der Typ von dTest ist: " << p2TI->name() << endl;
    return 0;
}

