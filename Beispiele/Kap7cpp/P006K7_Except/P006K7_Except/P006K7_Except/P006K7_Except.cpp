// P006K7_Except.cpp 
#include "stdafx.h"
#include <iostream>                                                     
using namespace std;
#include "cMyExcError.h"                                                //1
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
 
void testExample (void)                                                 //2
{
    try
    {
        cout << "Aufruf testExample\n";
        throw (cMyExcError("Exception in Funktion testExample.\n"));    //3
    }
    catch (...)                                                         //4
    {
        cout << "Exception-Handler in Funktion testExample.";
        cout << "Exception wird weiter geleitet.\n";
        throw;                                                          //5
    }
}
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P006K7_Except2";
    printConsole (str);
    //========================================= 
    try
    {
        testExample();                                                  //6                                             //3
    }
    catch (cMyExcError& error)                                          //7                    
    {
        cout << error.getErrHint();
    }
    return 0;                                                                                                                         
} 