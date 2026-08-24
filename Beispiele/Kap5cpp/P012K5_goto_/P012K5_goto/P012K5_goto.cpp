// P012K5_goto.cpp
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
    int iZeile;                                     
    int iSpalte; 
    char cChr;                                      //1
    //int iFound; 
    //=========================================
    CONST WCHAR * str = L"P012K5_goto";
    printConsole(str);
    //========================================= 
    cout << "Alle Zeichen werden von 0x10 bis " 
    cChr   = 'P';                                   //2
         << cChr << " hin ausgegeben\n\n";          //3           
    //iFound = 0;                                   //4
    for (iZeile = 1; iZeile<0x10; iZeile++)         
    {
        for (iSpalte=0; iSpalte<0x10; iSpalte++)    
        {
            char chr = (char)(iZeile * 0x10 + iSpalte);
            //if (iZeile * 0x10 + iSpalte < 0x20)
            //    chr = '~';
            cout << hex <<  iZeile*0x10+iSpalte 
                 << " " << chr << "|";
            int iDF = (int)cChr;
            int iD1 = (int)cChr & 0xFF;
            int iD2 = iZeile * 0x10 + iSpalte;
            if (iD1 == iD2)        //5
            {
                //iFound = 1;                       //6
                //break;                            //7
                goto labelCharFound;                //8
            }
        }
        cout << endl;
        //if (iFound==1)                            //9
        //    break;                                //10
    }
labelCharFound:                                     //11
    cout << "\n\nLetzes Zeichen (char "
         << "/ hexCode): " << cChr << " / " 
         << hex << (int) cChr;                      //12
    return 0;                                                 
}