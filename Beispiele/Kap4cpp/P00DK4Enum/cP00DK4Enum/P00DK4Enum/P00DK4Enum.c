//P00DK4Enum
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
    enum enMonat {Januar=1, Februar, März, April, Mai, Juni, Juli, August, 
                  September, Oktober, November, Dezember};                      //1
    int iTageSJ[Dezember+1]  = {  0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 
                                  31, 30, 31 };                                 //2
    int iTageNSJ[Dezember+1] = {  0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 
                                  31, 30, 31 };                                 //3
    int iJahr, i, iErr;                                                         //4
    //=========================================
    CONST WCHAR * str = L"P00DK4Enum";
    printConsole(str);
    //========================================= 

    for (i=0; i<=Dezember; i++)
    {
        iTageSJ[0]+=iTageSJ[i];                                                 //5
        iTageNSJ[0]+=iTageNSJ[i];
    }

    iJahr = 0;                                                                  //6
    printf ("Geben Sie eine Jahreszahl ein:\n");
    while (iJahr != 2011)                                                       //7
    {
        iErr =  scanf_s ("%i", &iJahr);
        if (iJahr%4==0)
            printf ("Das Jahr %i ist ein Schaltjahr und hat %i Tage.\n", 
                     iJahr, iTageSJ[0]);                                        //8
        else 
            printf ("Das Jahr %i ist kein Schaltjahr und hat %i Tage.\n", 
                     iJahr, iTageNSJ[0]);                                       //9
    }
    return 0;
}