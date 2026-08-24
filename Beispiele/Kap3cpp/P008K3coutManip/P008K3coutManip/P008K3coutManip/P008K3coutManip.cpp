// P008K3coutManip
#include "stdafx.h"
#include <iostream>
#include <iomanip>                                                                  //1
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
    double dEulerZ = 2.7182818284590452;
    //=========================================
    CONST WCHAR * str = L"P008K3coutManip";
    printConsole (str);
    //========================================= 
    cout << 555555.55 << endl;
    cout.fill ('!');                                                                //2
    cout << setw (5) << setiosflags (ios::right) << "345";                          //3
    cout << endl;                                                                   //4
    cout << setbase (8) << 10;                                                      //5
    cout << endl;
    cout << setiosflags (ios::uppercase) << setbase (16) << 10;                     //6
    cout << endl;
    cout << dEulerZ;                                                                //7
    cout << endl;
    cout.fill ('.');                                                                //8
    cout << setw (20) << dEulerZ;                                                   //9
    cout << endl;
    cout << setiosflags (ios::scientific) << dEulerZ;                               //10
    cout << endl;
    cout << setw (20) << setprecision (17) 
         << resetiosflags (ios::scientific) << dEulerZ;                             //11
    cout << endl;
    cout << setw (20) << setprecision (17) << setiosflags (ios::showpos) << dEulerZ;//12
    cout << endl;
    cout << "012345678901234567890\n";
    return 0;
}

