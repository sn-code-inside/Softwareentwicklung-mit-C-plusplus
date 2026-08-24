#include "stdafx.h"
#include <conio.h>
#include "consUtils.h"
/*===========================================================================*/
/* Desc.: Ausgabe des Names der Konsole als Titel                            */
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
/* Desc.: Liest Key von Tastatur wenn diese gedrueckt wurde                  */
/* In   : -                                                                  */
/* Out  : char: gedrueckte Taste                                             */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
char getKey (void)
/*---------------------------------------------------------------------------*/
{
    char chr = 0;
    if ( _kbhit() ) 
        chr = _getch(); 
    return chr; 
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
/*===========================================================================*/
/* Desc.: Ausgabe eines Textes an der CursorPos                              */
/* In   : hCons (HANDLE): Konsolen-Handle                                    */
/*        Pos (COORD)   : Position des farblichen Textes                     */
/*        str (char *)  : auszugebender Text                                 */
/*        iColor (int)  : Textfarbe                                          */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void printfStrWithColorAtPos(HANDLE hCons, COORD Pos, char *str, int iColor)
/*---------------------------------------------------------------------------*/
{
    SetConsoleTextAttribute(hCons, iColor);     //neue Farbe
    SetConsoleCursorPosition(hCons,Pos);        //neue Pos
    printf (str);                               //Ausgabe (Farbe und Character)
    SetConsoleTextAttribute(hCons, ciDefGray);  //DefFarbe wieder aktivieren!
}