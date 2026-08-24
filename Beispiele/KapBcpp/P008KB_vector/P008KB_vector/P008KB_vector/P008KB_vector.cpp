// P008KB_vector.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <vector>                                                               //1           
#include <algorithm>                                                            //2
#include <time.h>                                                               //3
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_NUMB  20                                                            //4                   
int main(void)  
{
    //=========================================
    {
    LPCTSTR str = L"P008KB_vector";
    printConsole(str);
    }
    //=========================================
    vector <int>::iterator itForw;                                              //5
    vector <int> vecInt(MAX_NUMB);                                              //6 
    unsigned int usiTime = (unsigned int)time(NULL);
    srand(usiTime);                                                             //7 1775533668
    for (unsigned int i=0; i<vecInt.size(); i++)                                //8
    {
        vecInt[i] = rand();                                                     //9
    }
    cout << "Ausgabe der Zufallszahlen:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)              //10
    {
        cout << *itForw << "\t";                                                //11
    }
    sort (vecInt.begin(), vecInt.end());                                        //12
    cout << "\n\nAusgabe der Zufallszahlen in sortierter Reihenfolge:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)
    {
        cout << *itForw << "\t";
    }
    vecInt.pop_back ();                                                         //13
    vecInt.push_back (1);                                                       //14
    vecInt.insert (vecInt.begin(), 999999);                                     //15
    cout << "\n\nAusgabe der Zufallszahlen nach Einfuegen bei Begin und Ende:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)
    {
        cout << *itForw << "\t";
    }
    sort (vecInt.begin(), vecInt.end());
    cout << "\n\nAusgabe der Zufallszahlen nochmals sortiert:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)
    {
        cout << *itForw << "\t";
    }
    reverse (vecInt.begin(), vecInt.end());                                     //16
    cout << "\n\nAusgabe der Zufallszahlen in umgekehrter Reihenfolge:\n";
    for (itForw = vecInt.begin(); itForw < vecInt.end(); itForw++)
    {
        cout << *itForw << "\t";
    }
    return 0;
}