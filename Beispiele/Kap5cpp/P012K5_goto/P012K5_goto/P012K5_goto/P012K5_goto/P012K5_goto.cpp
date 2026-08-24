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
int main (void) {                   
    int iZeile;                                     
    int iSpalte; 
    char cChr;                                      //1
    //int iFound; 
    //=========================================
    CONST WCHAR * str = L"P012K5_goto";
    printConsole(str);
    //========================================= 
    cChr   = 'z';                                   //2
    cout << "Alle Zeichen werden von 0x20 bis " 
         << cChr << " hin ausgegeben\n\n";          //3           
    //iFound = 0;                                   //4
    for (iZeile = 2; iZeile<0x10; iZeile++) {
        for (iSpalte=0; iSpalte<0x10; iSpalte++) {
            cout << hex <<  iZeile*0x10+iSpalte 
                 << " " << (char) (iZeile*0x10+iSpalte)
                 << "|";
            if (cChr == iZeile*0x10+iSpalte) {      //5
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
    cout<<"\n\nLetzes Zeichen (char/hexCode): "<<cChr<<"/"<<hex<<(int)cChr; //12
    return 0;                                                 
}