// P007KB_pair.cpp 
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <utility>                                          //1                                                                     
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_Params  5                                       //2
int main(void)  
{
    //=========================================
    {
    LPCTSTR str = L"P007KB_pair";
    printConsole(str);
    }
    //=========================================
    double dX=-MAX_Params;                                  //3
    double dY=.0;

    cout << "Ausgabe der Potenzfunktion y=x^3\n";
    cout << "dX;\tdY\n";
    pair <double, double> dFkt[2*MAX_Params+1];             //4
    for (int i=-MAX_Params; i<MAX_Params+1; i++)
    {
        dFkt[i+MAX_Params].first = (double)i;               //5
        dFkt[i+MAX_Params].second = pow( (double)i, 3.0 );
        cout << dFkt[i+MAX_Params].first << ";\t " 
             << dFkt[i+MAX_Params].second << endl;
    }
    for (int i=-MAX_Params; i<MAX_Params+1; i++)            //6
    {
        swap(dFkt[i+MAX_Params].first, dFkt[i+MAX_Params].second);
    }
    cout << "\nAusgabe der Potenzfunktion y=x^0.33\n";
    for (int i=-MAX_Params; i<MAX_Params+1; i++)
    {
        cout << dFkt[i+MAX_Params].first << ";\t "          //7
             << dFkt[i+MAX_Params].second << endl;
    }
    return 0;
}