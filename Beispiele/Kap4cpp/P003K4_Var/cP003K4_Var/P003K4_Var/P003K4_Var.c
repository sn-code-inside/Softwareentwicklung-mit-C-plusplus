//P003K4_Var
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
    int iX = 1;                     //Def. von iX
    //printf ("iX: %i\n", iX);      //Geht nur mit dem gcc!
    long double ldTest = 1.01E308;  //Def eine long double Var.
    //=========================================
    CONST WCHAR * str = L"P003K4_Var";
    printConsole(str);
    //=========================================  
    printf ("iX: %i\n", iX);        //Ausgabe von iX
    {
        int i  = 0;                 //Neuer Scope; iX ist ungültig,
                                    //falls es neu definiert wird.
        int iX = 25;                //iX wird neu definiert.
        printf ("iX: %i\n", iX);    //Ausgabe von iX 
    }
    //int iNumber = 1;              //Geht nur mit dem gcc!
    printf ("iX: %i\n", iX);      //Ausgabe von iX 
    return 0;
}
