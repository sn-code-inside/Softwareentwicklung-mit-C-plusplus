//P005K4_StructSizes
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
    struct tTest                                                            //1
    {
        unsigned char ucByte;                                               //2
        unsigned int uiNumb;                                                //3 
    };

    struct tTest test1 = {1, 0x1001u};                                      //4
    struct tTest test2 = {2, 0x1002u};
    struct tTest test3 = {3, 0x1003u};


    size_t uiSOTest = sizeof (test1);                                       //5
    //=========================================
    CONST WCHAR * str = L"P005K4_StructSizes";
    printConsole(str);
    //=========================================  
    printf ("Variablen der Struktur tTest belegen %i Bytes.", uiSOTest);    //6
    return 0;
}
