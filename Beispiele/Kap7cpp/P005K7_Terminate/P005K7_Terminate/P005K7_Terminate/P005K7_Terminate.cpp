// P005K7_Terminate.cpp
#include "stdafx.h"
#include <stdexcept>
#include <iostream>                                                     
using namespace std;                                                   
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
                                                       
void exitus (void)                                                  //1
{
    int i=0;
    cout << "Software terminiert durch nicht abgefangenen Exception.\n";
    cin  >> i;
    exit (i);
}
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P005K7_Terminate";
    printConsole (str);
    //========================================= 
    set_terminate (exitus);                                         //2
    try
    {
        throw 3;                                                    //3
    }
    catch (char *str)                                               //4
    {
        cout << "AAA";
    }
    return 0;                                                                                                                         
} 