// P000KE_ConsCol.cpp
//#define no_init_all deprecated

#include "stdafx.h"
#include <windows.h> 
const int ciDefGray = 0x7;                      //default Farbe
/*===========================================================================*/
/* Desc.: Ausgabe des Namens der Konsole als Titel                           */
/* In   : lpConsoleTitle (LPCTSTR): Konsolennamen                            */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void printConsole (LPCTSTR lpConsoleTitle)  
/*---------------------------------------------------------------------------*/
{
    SetConsoleTitle (lpConsoleTitle);
}
/*===========================================================================*/
/* Desc.: Ausgabe eines Textes an der CursorPos                              */
/* In   : hCons (HANDLE): Konsolen-Handle                                    */
/*        str (char *)  : auszugebender Text                                 */
/*        iColor (int)  : Textfarbe                                          */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void printfWithColor(HANDLE hCons, char * str, int iColor)
/*---------------------------------------------------------------------------*/
{
    SetConsoleTextAttribute(hCons, iColor);
    printf (str);
    SetConsoleTextAttribute(hCons, ciDefGray);  //DefFarbe wieder aktivieren!
}
int main(int argc, char* argv[])
{                                                            
    //=========================================
    LPCTSTR str = L"P000KE_ConsCol";
    printConsole(str);
    //=========================================
    int iZeile = 0x0; int iSpalte = 0x0; int iTemp; 
    char chr [5]; HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    printf ("Alle Farben mit allen Hintergrundfarben:\n");
    while (iZeile<0x10)
    {
        iTemp = iZeile*0x10;
        for (iSpalte=0; iSpalte<0x10; iSpalte++)
        {
            sprintf_s (chr, 5, "%2X", iTemp+iSpalte);
            if (chr[0] == ' ') chr[0] = '0';
            printfWithColor(hConsole, chr, iTemp+iSpalte);
        }
        printf ("\n");
        iZeile++;
    }
	return 0;    
}

