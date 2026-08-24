//P009K4_Bitfelder
#include <stdio.h>
#include <string.h>                                                     //1
#include <errno.h>                                                      //2
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
        unsigned char ucLanJava:1;
        unsigned char ucLanPerl:1;
        unsigned char ucLanC:1;
        unsigned char ucLanCpp:1;
        unsigned char ucRes1:1;
        unsigned char ucRes2:1;
        unsigned char ucRes3:1;
        unsigned char ucRes4:1;
    };
    struct tMitarbeiter mitarbeiter;
    int usSize;
    CONST WCHAR * str = L"P009K4_Bitfelder";
    errno_t iErr = strcpy_s ( mitarbeiter.cVorname, 16, "Max");         //3
            iErr = strcpy_s ( mitarbeiter.cNachname, 16, "Mustermann"); 
    //=========================================

    printConsole(str);
    //========================================= 
    mitarbeiter.ucLanJava  = 1;                                         //4
    mitarbeiter.ucLanPerl  = 0;
    mitarbeiter.ucLanC     = 1;
    mitarbeiter.ucLanCpp   = 1;
    mitarbeiter.ucRes1     = 0;
    mitarbeiter.ucRes2     = 0;
    mitarbeiter.ucRes3     = 0;
    mitarbeiter.ucRes4     = 1;                                         //5               
    usSize = sizeof (mitarbeiter);
    printf ("Sizeof mitarbeiter  : %u\n", usSize);                      //6
    return 0;
}