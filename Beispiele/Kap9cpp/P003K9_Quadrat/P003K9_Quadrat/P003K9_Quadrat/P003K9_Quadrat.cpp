// P003K9_Quadrat.cpp
#include "stdafx.h"
#include "cQuadrat.h"
#include <iostream>
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
    //=========================================
    LPCTSTR str = L"P003K9_Quadrat";
    printConsole(str);
    //=========================================    
    double dA = 2.0;                                            
    cout << "Seite a: " << dA << endl << endl;                  

    cQuadrat quad (dA);                                             //1                                
    double dX = 0;                                                  //2
    quad.getFlaeche();
    double dInc = 0.1;                                              //3
    cout << "dX\tFlaecheKleinQ" << endl;                            //4
    while (dX < (dA+0.001))                                         //5
    {
        cout << dX << "\t" << quad.getFlaecheKleinQ (dX) << endl;   //6
        dX += dInc;                                                 //7
    } 
	return 0;
}                                                               


