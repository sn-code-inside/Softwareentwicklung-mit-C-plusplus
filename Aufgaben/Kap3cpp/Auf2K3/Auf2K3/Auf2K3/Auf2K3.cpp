// Auf2K3
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


/* =========================================================================== */
/* Desc .: Zentiert einen String in einen Bereich                              */
/* In    : cStr (char*): zu zentrierender String                               */
/*         iMax (int)  : Maximale Anzahl der Bytes, die cStr fassen kann.      */
/* Out   : cStr (char*): zentrierter String                                    */
/* =========================================================================== */
/* --------------------------------------------------------------------------- */
void centerString (char * cStr, int iMax)
/* --------------------------------------------------------------------------- */
{
    int iLen = strlen (cStr);                                       //1
    int iPart = (iMax - iLen) / 2;                                  //2
    char *cTemp = new char[iLen+1];                                 //3
    strcpy_s (cTemp, iLen+1, cStr);                                 //4
    memset (cStr, 0x20, iMax);                                      //5
    cStr[iMax-1] = 0;                                               //6
    memcpy (cStr+iPart, cTemp, iLen);                               //7
    delete[] cTemp;                                                 //8
}

const int iMax = 80;                                                //9
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"Auf2K3";
    printConsole(str);
    //=========================================                     
 
    char cStr[iMax];                                                //10
    strcpy_s (cStr, iMax, "Der Trichter");                          //11
    centerString (cStr, iMax);                                      //12
    cout << cStr << endl << endl;                                   

    strcpy_s (cStr, iMax, "Zwei Trichter wandeln durch die Nacht.");
    centerString (cStr, iMax);
    cout << cStr << endl;
    strcpy_s (cStr, iMax, "Durch ihres Rumpfs verengten Schacht");
    centerString (cStr, iMax);
    cout << cStr << endl;
    strcpy_s (cStr, iMax, "flie\xe1t wei\xe1 \bes Mondlicht");         //13     
    centerString (cStr, iMax);
    cout << cStr << endl;
    strcpy_s (cStr, iMax, "still und heiter");
    centerString (cStr, iMax);
    cout << cStr << endl;
    strcpy_s (cStr, iMax, "auf ihrem");
    centerString (cStr, iMax);
    cout << cStr << endl;
    strcpy_s (cStr, iMax, "Waldweg");
    centerString (cStr, iMax);
    cout << cStr << endl;
    strcpy_s (cStr, iMax, "u.s.");
    centerString (cStr, iMax);
    cout << cStr << endl;
    strcpy_s (cStr, iMax, "w.");
    centerString (cStr, iMax);
    cout << cStr << endl;

   return 0;
}