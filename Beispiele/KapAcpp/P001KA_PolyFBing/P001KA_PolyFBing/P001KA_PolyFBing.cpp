// P008K9_PolyFBing.cpp
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
const char* getName(cDreieck *drei)                                     //1
{
    return drei->getClassName();
}
double ermittleFlaeche (cDreieck *drei)                                 //2
{
    return drei->ermittleFlaeche ();
}
int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR str = L"P001KA_PolyFBing";
    printConsole(str);
    //=========================================
    cRechteck rect(2,3);                                                //3
    cDreieck drei (2,3);                                                //4

    cout << "Name   : " << getName (&rect) << endl;                     //5
    cout << "Flaeche: " << ermittleFlaeche (&rect) << endl << endl;

    cout << "Name   : " << getName (&drei) << endl;                     //6
    cout << "Flaeche: " << ermittleFlaeche (&drei) << endl;
    return 0;
}

