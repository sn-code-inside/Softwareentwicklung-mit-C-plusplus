//P00EK4_Typedef
#include <stdio.h>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 

typedef unsigned short int CARDINAL;
typedef unsigned char BYTE;
int main (void)
{
    CARDINAL cardTest;
    BYTE btTest;

    //=========================================
    CONST WCHAR * str = L"P00EK4_Typedef";
    printConsole(str);
    //========================================= 
    cardTest = 0xFFFF;
    btTest   = 0xFF;
    printf ("SizeOf CARDINAL: %i;\tWert von cardTest: %#x\n", sizeof (CARDINAL), cardTest);
    printf ("SizeOf BYTE    : %i;\tWert von btTest  : %#x\n", sizeof (BYTE), btTest);
    return 0;
}