// P006K3cout.cpp
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


int main(void)
{
    //=========================================
    CONST WCHAR * str = L"P006K3cout";
    printConsole (str);
    //========================================= 
    cout << "Das ist die Zeile 1\n"                                     //1
         << "und das wird auf der Zeile 2 ausgegeben.\n";               //2
    int iSum1 = 4700, iSum2 =11;                                        //3
    cout << "Und rechnen kann man mit cout auch:\n"                     //4
         << iSum1 << " + " << iSum2 << " = " << iSum1 + iSum2 << endl;  //5
	return 0;
}

