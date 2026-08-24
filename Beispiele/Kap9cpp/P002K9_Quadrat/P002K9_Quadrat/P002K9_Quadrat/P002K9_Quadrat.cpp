// P002K9_Quadrat.cpp
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
    LPCTSTR str = L"P002K9_Quadrat";
    printConsole(str);
    //=========================================    
    double dA = 2.0;                                            
    cout << "Seite a: " << dA << endl << endl;                  

    cQuadrat quad (dA);                                         

    cout << "Umfang Quadrat : " << quad.getUmfang () << endl;   
    cout << "Flaeche Quadrat: " << quad.getFlaeche () << endl;  
	return 0;
}                                                               


