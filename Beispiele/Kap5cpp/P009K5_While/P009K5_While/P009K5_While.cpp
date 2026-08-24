// P009K5_While.cpp
#include "stdafx.h"
#include <iostream>                                         //1 
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
    int iZahl, iOrgZahl, iFak;                              //2                   
    //=============================================
    CONST WCHAR * str = L"P009K5_While";
    printConsole(str);
    //============================================= 
    cout << "Berechnung der Fakult\x84t von Zahlen. ";      //3
    cout << "Bitte Zahl eingeben:\n";                       //4
    
    cin >> iZahl;                                           //5
    iOrgZahl = iZahl;                                       //6
    if ((iOrgZahl < 14) && (iOrgZahl>=0))                   //7
    {
        cout<<"Berechnung Fakult\x84t von "<<iZahl<<endl;   //8
        iFak=1;
        while (iZahl)                                       //9
        {
            iFak *= iZahl--;                                  //10
            //iZahl--;                                        //11
        }
        cout << iOrgZahl << "! = " << iFak << endl;         //12
    }
    else
        cout<<"Falsche Eingabe. iZahl: "<< iZahl << endl;   //13
    return 0;                                       
}
