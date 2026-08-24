// P001KE_threadEx1.cpp
#include "stdafx.h"
#include <windows.h> 
#include <conio.h>                                  //1
#include <iostream>
using namespace std;

const int ciDefGray = 0x7;                          //default Farbe
HANDLE  hConsole_   = 0;                            //2
HANDLE hThreadRed_  = 0;                            //3

const int ciRed_    = 0x0C;                         //4

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
/* Desc.: Liest Key von Tastatur, wenn diese gedrueckt wurde                 */
/* In   : -                                                                  */
/* Out  : char: gedrueckte Taste                                             */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
char getKey (void)
/*---------------------------------------------------------------------------*/
{
    char chr = 0;
    if ( _kbhit() )                                 //5    
        chr = _getch();                             //6
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
    SetConsoleTextAttribute(hCons, iColor);         //7
    printf (str);                                   //8
    SetConsoleTextAttribute(hCons, ciDefGray);      //DefFarbe wieder aktivieren!
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
    SetConsoleTextAttribute(hCons, iColor);         //neue Farbe
    SetConsoleCursorPosition(hCons,Pos);            //neue Pos
    printf (str);                                   //Ausgabe (Farbe und Character)
    SetConsoleTextAttribute(hCons, ciDefGray);      //DefFarbe wieder aktivieren!
}

DWORD WINAPI ThreadRed( LPVOID lpParam )  
{
    COORD Pos;                                      //9
    bool bEnd = false;                              //10
    Pos.X = 8;                                      //11
    Pos.Y = 3;
    int iRedNumb = 0;                               //12
    char strRed[128] ={0};                          //13
    sprintf_s (strRed, 128, "ThreadHandle Red: %x", (unsigned int)hThreadRed_);
    printfStrWithColorAtPos(hConsole_, Pos, strRed, ciRed_);
    Pos.Y++;
    while (!bEnd)                                   //14
    {
        sprintf_s (strRed, 128, "%i", iRedNumb++);  //15
        printfStrWithColorAtPos(hConsole_, Pos, strRed, ciRed_);
        Sleep (500);                                //16
        char cChr = getKey();                       //17
        if (cChr == 'r')                            //18
            bEnd = true;                            //19
    }
    Pos.Y++;                                        //20
    printfStrWithColorAtPos(hConsole_, Pos, "end of ThreadRed", ciRed_);
    return 0; 
} 

int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR str = L"threadExample";
    printConsole(str);
    //=========================================
    HANDLE arrOfThreadHandles[1];                   //21
    
    if( (hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE )  
        return 1;                                   //22

    cout << "Beispiel eines Threads.\n";
    hThreadRed_ = CreateThread( NULL, 0, 
                    ThreadRed, NULL, 0, NULL);      //23 
    if ( hThreadRed_ == NULL)
       return 2;
      
    arrOfThreadHandles[0] = hThreadRed_;            //24
    
    WaitForMultipleObjects( 1, arrOfThreadHandles,  
        TRUE, INFINITE);                            //25

    CloseHandle(hThreadRed_);                       //26

    cout << "\n\nEnde des Programmes P001KE_threadEx1.\n";
	return 0;
}
