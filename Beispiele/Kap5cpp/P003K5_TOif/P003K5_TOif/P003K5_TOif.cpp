// P003K5_TOif.cpp
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

int main (void)
{ 
    char cVar;                                      //Deklaration von cVar
    cin >> cVar;
    char cChr = tolower (cVar);                     //Deklaration und Definition von cChr
    //=============================================
    CONST WCHAR * str = L"P003K5_TOif";
    printConsole(str);
    //=============================================                 
    cout << "Zeichen vor TO :  " << cChr << endl;   //Augabe von cChr
    cVar = (cChr == 'a')?'b':'c';
    cout << "Zeichen vor TO :  " << cVar << endl;   //Augabe von cVar
    cout << "--------------------- \n"; 
    cChr = 'a';                                     //Rücksezen von cChr auf 'a'
    cout << "Zeichen vor TO :  " << cChr << endl;   //Augabe von cChr
    if (cChr=='a')
        cChr='b';
    else
        cChr='c';
    cVar = cChr;
    cout << "Zeichen vor TO :  " << cVar << endl;   //Augabe von cVar 
    return 0 ;
}