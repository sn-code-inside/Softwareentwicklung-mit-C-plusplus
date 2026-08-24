// P002K5_TO2.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <ctype.h>                              
//=============================================
#include <Windows.h>
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================

int main (void)
{ 
    char cChr; cin >> cChr; cChr = tolower (cChr); 
    //=============================================
    CONST WCHAR * str = L"P002K5_TO2";
    printConsole(str);
    //=============================================                 
    cout << "Zeichen vor TO :  " << cChr << endl; 
    (cChr == 'a')?cChr++:cChr--;
    cout << "Zeichen nach TO:  " << cChr << endl;  
    cout << "---------------------"      << endl; 
    cin >> cChr; cChr = tolower (cChr);                     
    cout << "Zeichen vor TO :  " << cChr << endl;    
    (cChr == 'a')?cChr++:cChr--;
    cout << "Zeichen nach TO:  " << cChr << endl;  
    return 0 ;
}