// P09K7_STDMeth.cpp
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
 
class cMethExc
{
    public:
        cMethExc(void) 
        {
            cout << "Konstruktor\n";
            str_ = new char[256];                   //1
            //throw 1;                              //2
        }
        ~cMethExc(void)
        {
            throw 1;                              //3
            delete [] str_;                         //4
            cout << "Destruktor\n";
        }
    private:
        char *str_;

};

int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P09K7_STDMeth";
    printConsole (str);
    //========================================= 
    try
    {
        cout << "start main\n";                     //5
        cMethExc test;
    }
    catch (...)                                                              
    {
        cout << "Unbekannter Fehler in main!\n";    //6 
    }
    return 0;                                                                                                                         
} 