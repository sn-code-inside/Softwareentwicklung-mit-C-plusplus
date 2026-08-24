// Auf4K3
#include "stdafx.h"
#include <iostream>
#include <iomanip>                                                      //1
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
   char     cTest;
    //=========================================
    CONST WCHAR * str = L"Auf4K3";
    printConsole(str);
    //=========================================    
   cin >> cTest;                                                        //2
   cout << "Ausgabe als Char: " << cTest << endl;                       //3
   cout << "Ausgabe als Int : " << setiosflags (ios::showbase) 
        << (int) cTest << endl;                                         //4
   cout << "Ausgabe als Oct : " << setiosflags (ios::showbase) 
        << oct << (int) cTest << endl;                                  //5
   cout << "Ausgabe als Hex : " << setiosflags (ios::showbase) 
        << hex << (int) cTest << endl;                                  //6
   return 0;
}


