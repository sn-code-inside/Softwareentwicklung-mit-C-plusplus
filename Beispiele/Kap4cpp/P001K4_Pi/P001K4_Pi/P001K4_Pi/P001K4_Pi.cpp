// P001K4_Pi
#include "stdafx.h"
#define _USE_MATH_DEFINES                                                       //1
#include <iostream>                                                             
using namespace std;
#include <math.h>
#include <float.h>
#include <iomanip >
//=============================================
#include <Windows.h> 
#include "limits.h"
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 
int main(int argc, char* argv[])
{
    //=========================================
    CONST WCHAR * str = L"P001K4_Pi";
    printConsole(str);
    //========================================= 
    //float  fTest = 5.6;
    cout << "Radius des Einheitskreises       : " << 1.0  << endl;              //2
    cout << "Fl\x84 \bcheninhalt des Einheitskreises: " << M_PI << endl;        //3
    cout << setprecision(17) << "Umfang des Einheitskreises       : " << 2.0*M_PI << endl;            //4
    return 0;
}
