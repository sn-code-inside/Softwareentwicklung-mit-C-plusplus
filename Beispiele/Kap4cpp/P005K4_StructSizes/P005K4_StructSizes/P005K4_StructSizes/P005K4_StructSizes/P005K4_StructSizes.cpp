// P005K4_StructSizes
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

int main (void)
{
//#pragma pack(8)
    struct tTest                                                            //1
    {
        unsigned char ucByte;                                               //2
        unsigned int uiNumb;                                                //3 
    };

    tTest test1 = {1, 0x1001u};                                             //4
    tTest test2 = {2, 0x1002u};
    tTest test3 = {3, 0x1003u};
    //alignas(128) char cacheline[128];

    size_t uiSOTest1 = sizeof (test1);                                      //5
    size_t uiSOTest2 = sizeof (test2);                                      
    size_t uiSOTest3 = sizeof (test3);                                      

    //=========================================
    CONST WCHAR * str = L"P005K4_StructSizes";
    printConsole(str);
    //========================================= 
    cout << "Eine Variable der Struktur tTest belegt " 
         << uiSOTest1 << " Bytes.\n";
    cout << "Eine Variable der Struktur tTest belegt "
        << uiSOTest2 << " Bytes.\n";
    cout << "Drei Variablen der Struktur tTest belegen " 
         << uiSOTest1+uiSOTest1+uiSOTest1 << " Bytes.\n";                   //6
    
    //cout << alignof(char); 
#pragma pack (show)
    return 0;
}
