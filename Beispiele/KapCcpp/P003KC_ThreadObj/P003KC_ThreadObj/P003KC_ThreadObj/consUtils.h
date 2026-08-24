#include "stdafx.h"
#include <windows.h> 
#pragma once
const int ciDefGray = 0x7;                      //default Farbe
const int ciRed     = 0x0C;
const int ciGreen   = 0x0A;
///Ausgabe des Names der Konsole als Titel  
void printConsole (LPCTSTR lpConsoleTitle);

///Liest Key von Tastatur wenn diese gedrueckt wurde
char getKey (void);

///Ausgabe eines Textes an der CursorPos
void printfWithColor(HANDLE hCons, char * str, int iColor);

///Ausgabe eines Textes an der CursorPos  
void printfStrWithColorAtPos(HANDLE hCons, COORD Pos, char *str, int iColor);
