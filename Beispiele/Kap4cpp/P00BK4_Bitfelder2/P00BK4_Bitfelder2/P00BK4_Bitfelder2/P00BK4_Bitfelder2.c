//P00BK4_Bitfelder2
#include <stdio.h>
#include <string.h>                                                         //1
#include <errno.h>                                                          //2
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================   
int main (void)
{
    struct tMitarbeiter
    {
        char cVorname[16];
        char cNachname[16];  
        unsigned int uiEuropa:4;                                            //3
        unsigned int uiAfrika:4;
        unsigned int uiAmerika:4;
        unsigned int uiAustralien:4;
        unsigned int uiAsien:4;
    };
    struct tMitarbeiter mitarbeiter;
    int usSize;
    //=========================================
    CONST WCHAR * str = L"P00BK4_Bitfelder2";

    //========================================= 
    errno_t iErr = strcpy_s ( mitarbeiter.cVorname, 16, "Max");             //4
            iErr = strcpy_s ( mitarbeiter.cNachname, 16, "Mustermann"); 
    mitarbeiter.uiEuropa     = 5;                                           //5
    mitarbeiter.uiAfrika     = 1;
    mitarbeiter.uiAmerika    = 2;
    mitarbeiter.uiAustralien = 1;
    mitarbeiter.uiAsien      = 10;      
    usSize = sizeof (mitarbeiter);
    printConsole(str);
    printf ("Sizeof mitarbeiter     : %u\n", usSize);                       //6
    printf ("Herr %s spricht: ", mitarbeiter.cNachname);                     
    printf ("%u europ\x84ische, \n\t\t\t %u afrikanische, \n\t\t\t "
            "%u amerikanische, \n\t\t\t %u australische und \n\t\t\t "
            "%u asiatische Sprachen.\n", 
            mitarbeiter.uiEuropa, mitarbeiter.uiAfrika, 
            mitarbeiter.uiAmerika, mitarbeiter.uiAustralien, 
            mitarbeiter.uiAsien);                                           //7
    return 0;
}
