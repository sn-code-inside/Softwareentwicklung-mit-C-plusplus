//P012K6_goto
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
    int iZeile;                                     
    int iSpalte; 
    char cChr;                                      //1
    //int iFound; 
    //=========================================
    CONST WCHAR * str = L"P012K6_goto";
    printConsole(str);
    //========================================= 
    cChr   = '~';                                   //2
    printf("Alle Zeichen werden von 0x10 bis %c "
           "hin ausgegeben\n\n", cChr);             //3           
    //iFound = 0;                                   //4
    for (iZeile = 1; iZeile<0x10; iZeile++)         
    {
        for (iSpalte=0; iSpalte<0x10; iSpalte++)    
        {
            printf ("%x %c|", iZeile*0x10+iSpalte,  
                              iZeile*0x10+iSpalte); 
            if (cChr == iZeile*0x10+iSpalte)        //5
            {
                //iFound = 1;                       //6
                //break;                            //7
                goto labelCharFound;                //8
            }
        }
        //if (iFound==1)                            //9
        //    break;                                //10
    }
labelCharFound:                                     //11
    printf ("\n\nLetzes Zeichen (char "
        "/ hexCode): %c / %#x\n", cChr, cChr);      //12
    return 0;                                                 
}