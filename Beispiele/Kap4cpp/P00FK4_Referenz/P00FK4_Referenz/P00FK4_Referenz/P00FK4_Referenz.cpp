// P00FK4_Referenz.cpp
#include "stdafx.h"
#include <iostream>                                                 //1
using namespace std;                            
//=============================================
#include <Windows.h>    
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================

//Tauscht den Wert von iVar1 gegen den von iVar2 aus.
void exchange (int& iVar1, int& iVar2)
{
    int iTemp = iVar1;
    iVar1 = iVar2;
    iVar2 = iTemp;
}
int main (void)
{
    int iTest=0;                                                    //2
    int& iROiTest = iTest;                                          //3
    //int iTest2 = 1;
    //exchange (iTest, iTest2);

    //=============================================
    CONST WCHAR * str = L"P00FK4_Referenz";
    printConsole(str);
    //=============================================
    cout << "Inhalt von iTest    : " << ++iTest  << endl;           //4
    cout << "Inhalt von iROiTest : " << iROiTest << endl;           //5
    cout << "Adresse von iTest   : " << hex << &iTest    << endl;   //6
    cout << "Adresse von iROiTest: " << hex << &iROiTest << endl;   //7
    return 0;                                           
}