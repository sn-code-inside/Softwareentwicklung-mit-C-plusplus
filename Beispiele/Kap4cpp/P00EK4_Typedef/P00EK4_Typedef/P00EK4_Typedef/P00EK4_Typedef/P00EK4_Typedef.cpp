// P00EK4_Typedef
#include "stdafx.h"
#include <iostream>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 

typedef unsigned short int CARDINAL;                                //1
typedef unsigned char BYTE;                                         //2
int main (void)
{
    CARDINAL cardTest;
    BYTE btTest;

    //=========================================
    CONST WCHAR * str = L"P00EK4_Typedef";
    printConsole(str);
    //========================================= 
    cardTest = 0xFFFF;                                              //3
    btTest   = 0xFF;
    cout     << hex;
    cout << "SizeOf CARDINAL: " << sizeof (CARDINAL) 
         << "\tWert von cardTest: " << cardTest    << endl;         //4
    cout << "SizeOf BYTE    : " << sizeof (BYTE)     
         << "\tWert von btTest  : " << (int)btTest << endl;
    return 0;
}