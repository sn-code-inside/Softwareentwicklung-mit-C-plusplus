// P0AK7_STDMeth2.cpp
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
        cMethExc(void) {
            try{
                throw 1;                            //2
                cout << "Konstruktor\n";
                str_ = new char[256];               //1

            }
            catch (...) {
                cout << "Exception im Konstruktor\n";
            }
        }
        ~cMethExc(void)
        {
            try{
                cout << "Destruktor\n";
                delete [] str_;                     //3
                throw 1;                            //4
            }
            catch (...) {
                cout << "Exception im Destruktor\n";
            }
        }
    private:
        char *str_;

};
int main (void) {
    //=========================================
    CONST WCHAR * str = L"P0AK7_STDMeth2";
    printConsole (str);
    //========================================= 
    try {
        cout << "start main\n";                     //5
        cMethExc test;
    }
    catch (...)  {
        cout << "Unbekannter Fehler in main!\n";    //6 
    }
    return 0;                                                                                                                         
} 