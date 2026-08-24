// Auf3KB.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <list>                                                               
#include <algorithm>                                                          
#include <time.h>                                                             
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_NUMB  5                                                                   
int main(void)  
{
    //=========================================
    {
    LPCTSTR str = L"Auf3KB";
    printConsole(str);
    }
    //=========================================
    list <int>::iterator itForw;                                            
    list <int> listInt;                                            
    srand( (unsigned int)time(NULL));                                         
    cout << "Aufbau einer zufaelligen Integer-Liste <list>...\n";
    for (unsigned int i=0; i<MAX_NUMB; i++)                              
        listInt.push_back (rand());                                                   
    cout << "... fertig\n";

    cout << "\nAusgabe der zufaelligen Integer-Liste <list>\n";
    for (itForw = listInt.begin(); itForw != listInt.end(); itForw++)            
    {
        cout << *itForw << "\n";                                              
    }
    listInt.sort ();                                    
    cout << "\nAusgabe der Zufallszahlen in sortierter Reihenfolge <list>:\n";
    for (itForw = listInt.begin(); itForw != listInt.end(); itForw++)
    {
        cout << *itForw << "\n";
    }
    return 0;
}