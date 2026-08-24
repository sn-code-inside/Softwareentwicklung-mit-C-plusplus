//P00AK4_Align
#include <stdio.h>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================   
int main (void)
{
    #pragma pack(show)                           // Default-Alignment im Ausgabefenster. 
                                                 // Achtung: warning auf: C4810.
    #pragma pack(1)                              // Alignment auf 1 setzen
    #pragma pack(show)                           // Default-Alignment im Ausgabefenster. 
    struct tAlignTestPack                        // struct tAlignTestPack definieren
    {
        char cTest1;
        int iTest1;
        char cTest2;
    };
    #pragma pack()                               // Default-Alignment wieder herstellen
    #pragma pack(show)                           // Aktuelles-Alignment wieder anzeigen. 
    struct tAlignTestDefault                     // struct tAlignTestDefault definieren
    {
        char cTest1;
        int iTest1;
        char cTest2;
    };
    struct tAlignTestPack packAlign;
    struct tAlignTestDefault defaultAlign; 
    //=========================================
    CONST WCHAR * str = L"P00AK4_Align";
    printConsole(str);
    //========================================= 
    printf ("Anzahl Bytes von packAlign   : %u\n",
            sizeof (packAlign));                //Ausgabe der Größe von packAlign
    printf ("Anzahl Bytes von defaultAlign: %u",
            sizeof (defaultAlign));             //Ausgabe der Größe von defaultAlign 
    return 0;
}