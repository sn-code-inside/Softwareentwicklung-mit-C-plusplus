#include "stdafx.h"
#include "cConsole.h"
#include <conio.h>
cConsole::cConsole(void)
{
    initSection ();
    hConsole_ = NULL;
    hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE); 
}
cConsole::~cConsole(void)
{
}
/*===========================================================================*/
/* Desc.:Ermittlung des Namens der Vordergrundfarbe                          */
/* In   : int iColor   : Farbwert                                            */
/* Out  : str (char *) : auszugebender Text                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
const char * cConsole::strColor2String (int iColor)
/*---------------------------------------------------------------------------*/
{
    if (ciBlack == iColor) return "ciBlack"; else if (ciBlue == iColor) return "ciBlue"; 
    else if (ciGreen == iColor) return "ciGreen"; else if (ciCyan == iColor) return "ciCyan";
    else if (ciRed == iColor) return "ciRed"; else if (ciMagenta == iColor) return "ciMagenta"; 
    else if (ciBrown == iColor) return "ciBrown"; else if (ciLGray == iColor) return "ciLGray";

    else if (ciDGray == iColor) return "ciDGray"; else if (ciLRed == iColor) return "ciLRed"; 
    else if (ciLBlue == iColor) return "ciLBlue"; else if (ciLMagenta == iColor) return "ciLMagenta";
    else if (ciLGreen == iColor) return "ciLGreen"; else if (ciLCyan == iColor) return "ciLCyan";
    else if (ciYellow == iColor) return "ciYellow"; else if (ciWhite == iColor) return "ciWhite";
    else return "ciBlack";
}
/*===========================================================================*/
/* Desc.: Löscht eine Zeile der Länge iLen.                                  */
/* In   : Pos (COORD)   : Position des farblichen Textes                     */
/*        iLen (int)    : Länge der Zeile                                    */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void cConsole::delLine (COORD Pos, int iLen)
/*---------------------------------------------------------------------------*/
{
    SetConsoleTextAttribute(hConsole_, ciBlack);     
    SetConsoleCursorPosition(hConsole_,Pos); 
    for (int i=0; i<iLen; i++)
        printf (" ");                                   
    SetConsoleTextAttribute(hConsole_, ciLGray); 
}
/*===========================================================================*/
/* Desc.: Ausgabe eines Textes an der CursorPos                              */
/* In   : Pos (COORD)   : Position des farblichen Textes                     */
/*        str (char *)  : auszugebender Text                                 */
/*        iColor (int)  : Textfarbe                                          */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void cConsole::printfStrWithColorAtPos(COORD Pos, char *str, int iColor)
/*---------------------------------------------------------------------------*/
{
    SetConsoleTextAttribute(hConsole_, iColor);     //neue Farbe
    SetConsoleCursorPosition(hConsole_,Pos);        //neue Pos
    printf (str);                                   //Ausgabe (Farbe und Character)
    SetConsoleTextAttribute(hConsole_, ciLGray);    //DefFarbe wieder aktivieren!
}
/*===========================================================================*/
/* Desc.: Ausgabe eines Textes an der CursorPos                              */
/* In   : str (char *)  : auszugebender Text                                 */
/*        iColor (int)  : Textfarbe                                          */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void cConsole::printfWithColor(char * str, int iColor)
/*---------------------------------------------------------------------------*/
{
    SetConsoleTextAttribute(hConsole_, iColor);
    printf (str);
    SetConsoleTextAttribute(hConsole_, ciLGray);  //DefFarbe wieder aktivieren!
}
/*===========================================================================*/
/* Desc.: Ausgabe des Namens der Konsole als Titel                            */
/* In   : lpConsoleTitle (LPCTSTR): Konsolennamen                            */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void cConsole::printConsole (LPCTSTR lpConsoleTitle)
/*---------------------------------------------------------------------------*/
{
    SetConsoleTitle (lpConsoleTitle);
}
/// Löscht alle Tasten aus dem Puffer.
void cConsole::clearKeyBuffer(void)
{
    char chr = 0;
    while (_kbhit())
    {
        chr = _getch();
    }
}
/*===========================================================================*/
/* Desc.: Liest Key von Tastatur wenn diese gedrueckt wurde                  */
/* In   : -                                                                  */
/* Out  : char: gedrueckte Taste                                             */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
char cConsole::getKey (void)
/*---------------------------------------------------------------------------*/
{
    char chr = 0;
    if ( _kbhit() ) 
        chr = _getch(); 
    return chr; 
}
/*===========================================================================*/
/* Desc.: setzt die private Menber-Variable bReceived_                       */
/* In   : bReceived: bool; true: Taste angekommen; sonst false               */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void cConsole::setReceived (bool bReceived)
/*---------------------------------------------------------------------------*/
{
    bReceived_ = bReceived;
}
/*===========================================================================*/
/* Desc.: returned ob Taste im Thread angekommen ist                         */
/* In   : -                                                                  */
/* Out  : true: Taste angekommen; sonst false                                */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
bool cConsole::getReceived (void)
/*---------------------------------------------------------------------------*/
{
    return bReceived_;
}
/*===========================================================================*/
/* Desc.: Setzt das consSection_                                             */
/* In   : -                                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
void cConsole::enterSection (void)                                                
{
    EnterCriticalSection (&consSection_);
}
/*===========================================================================*/
/* Desc.: Gibt die consSection_  wieder frei                                 */
/* In   : -                                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
void cConsole::leaveSection (void)                                                
{
    LeaveCriticalSection (&consSection_);
}
/*===========================================================================*/
/* Desc.: Initialisiert die consSection_                                     */
/* In   : -                                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
void cConsole::initSection (void)                                                 
{
    InitializeCriticalSection (&consSection_);
}