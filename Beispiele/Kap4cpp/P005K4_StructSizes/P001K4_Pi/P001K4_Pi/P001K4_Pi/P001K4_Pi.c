//P001K4_Pi 
//Achtung: Nur für gcc!!!
#include <math.h>
#include <stdio.h>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 
int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR * str = "P001K4_Pi";
    printConsole(str);
    //=========================================       
    printf("U und A des Einheitskreises: %f\n", M_PI);
    return 0;
}
