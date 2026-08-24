// P002KA_PolySBing.cpp
#include "stdafx.h"
#include <iostream>
#include "cRechteck.h"
#include "cDreieck.h"
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================

const char* getName(cDreieck *drei)                                    
{
    return drei->getClassName();
}
double ermittleFlaeche (cDreieck *drei)                                
{
    return drei->ermittleFlaeche ();
}
int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR str = L"P002KA_PolySBing";
    printConsole(str);
    //=========================================
    cRechteck rect(2,3);                                               
    cDreieck drei (2,3);                                               

    cout << "Name   : " << getName (&rect) << endl;                    
    cout << "Flaeche: " << ermittleFlaeche (&rect) << endl << endl;

    cout << "Name   : " << getName (&drei) << endl;                    
    cout << "Flaeche: " << ermittleFlaeche (&drei) << endl << endl;

    cout << "sizeof (cDreieck) bei spaeter Bindung: "  << sizeof (cDreieck) << endl;
    return 0;
}

