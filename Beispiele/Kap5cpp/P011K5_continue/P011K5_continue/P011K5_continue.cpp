// P011K5_continue.cpp
#include "stdafx.h"
#include <iostream>   
using namespace std;
#define MAX_TRY     3                                       //1
//=============================================    
#include <Windows.h>   
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
int main (void)
{                   
    int iNumb, iTry;                                        //2                                 
    //=========================================
    CONST WCHAR * str = L"P011K5_continue";
    printConsole(str);
    //========================================= 
    cout << "Zahl zwischen 10 und 20 eingeben!\n";          //3
    iTry = 0;                                               //4
    do
    {
        cin >> iNumb;                                       //5
        if ( (iNumb<10)||(iNumb>20) )                       //6
        {
            cout << "\rFalsche Eingabe: " << iNumb << endl; //7
            continue;                                       //8
        }
        else
        {
            break;                                          //9
            cout <<  "Dieser Text wird nie ausgegeben.";
        }
    } while (iTry++<MAX_TRY-1);                             //10
    if (iTry>MAX_TRY-1)                                     //11
        cout<<iTry<<" Fehlversuche. Abbruch der Eingabe!";  //12
    else
        cout << "Korrekte Eingabe: " << iNumb;              //13
    return 0;                                                 
}