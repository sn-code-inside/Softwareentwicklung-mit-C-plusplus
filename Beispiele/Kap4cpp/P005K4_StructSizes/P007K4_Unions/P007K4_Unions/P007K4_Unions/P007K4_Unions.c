//P007K4_Unions
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
    union tUnion                                //1
    {
        char cChar;                             //2
        unsigned char ucChar;                   //3
    };
    union tUnion myUnion;                       //4
    //=========================================
    CONST WCHAR * str = L"P007K4_Unions";
    printConsole(str);
    //=========================================  
    myUnion.cChar   = 'A';                      //5
    printf ("cChar : %c\n", myUnion.cChar);     //6
    printf ("ucChar: %c\n\n", myUnion.ucChar);  //7
    myUnion.ucChar  = 'Z';                      //8
    printf ("cChar : %c\n", myUnion.cChar);     //9
    printf ("ucChar: %c\n", myUnion.ucChar);    //10

    return 0;
}
