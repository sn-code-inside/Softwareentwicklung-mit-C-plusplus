// P006K5_EZ.cpp
#include "stdafx.h"
#include <iostream>                             //1
#include <iomanip>
#include <cmath>
using namespace std; 
//=============================================
#include <Windows.h>
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
int main (void)
{
    int i;                                      //2
    double dEZ=1;                               //3                         
    double dNenn=1.0;                           //4
    double dZaehl=1.0;                          //5
    double dEpsilon=1.0E-20;                    //6
    //=============================================
    CONST WCHAR * str = L"P006K5_EZ";
    printConsole(str);
    //============================================= 
    for (i=1; dEpsilon<dZaehl/dNenn; i++)       //7
    {
        dNenn=dNenn*i;                          //8
        dEZ=dEZ+(dZaehl/dNenn);                 //9
    }
    cout << "Die Eulersche Zahl ist: " 
         << setprecision (17) << dEZ << "\n";                        //10
    return 0;
}