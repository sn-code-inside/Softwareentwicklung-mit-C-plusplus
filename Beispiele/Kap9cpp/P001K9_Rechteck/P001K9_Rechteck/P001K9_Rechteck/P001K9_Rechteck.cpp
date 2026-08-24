// P001K9_Rechteck.cpp
#include "stdafx.h"
#include "cRechteck.h"                                          //1
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
    LPCTSTR str = L"P001K9_Rechteck";
    printConsole(str);
    //=========================================    
    double dA = 2.0;                                            //2
    double dB = 3.0;
    cout << "Seite a: " << dA << endl;                          //3
    cout << "Seite b: " << dB << endl << endl;

    cRechteck rect (dA, dB);                                    //4

    cout << "Umfang Recheck : " << rect.getUmfang () << endl;   //5
    cout << "Flaeche Recheck: " << rect.getFlaeche () << endl;  //6
	return 0;
}                                                               //7

