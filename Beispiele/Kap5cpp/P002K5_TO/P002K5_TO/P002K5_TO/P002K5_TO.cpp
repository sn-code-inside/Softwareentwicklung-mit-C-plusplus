// P002K5_TO.cpp
#include "stdafx.h"
#include <stdio.h>                                  // 1
#include <iostream>                                 // 2
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
    char cChr;                                      //3
    //=============================================
    CONST WCHAR * str = L"P002K5_TO";
    printConsole(str);
    //=============================================
    cin >> cChr;                                    //4
    cChr = tolower (cChr);                          //5 
    cout << "Zeichen vor TO :  " << cChr << endl;   //6
    (cChr == 'a')?cChr++:cChr--;                    //7
    cout << "Zeichen nach TO:  " << cChr << endl;   //8
    cout << "--------------------- \n";            
    cin >> cChr;                                    //9
    cChr = tolower (cChr);                          //10
    cout << "Zeichen vor TO :  " << cChr << endl;   //11
    (cChr == 'a')?cChr++:cChr--;                    //12
    cout << "Zeichen vor TO :  " << cChr << endl;   //13    
    return 0 ;
}