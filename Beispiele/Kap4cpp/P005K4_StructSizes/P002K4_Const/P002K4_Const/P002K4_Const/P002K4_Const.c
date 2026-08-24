//P002K4_Const
#include <stdio.h>
#include <math.h>                                                                   //1
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 
#define EZ 2.718281828459045    //basis logarithmus naturalis (Eulersche Zahl)      //2
#define WBV 0x198B2591A         //Weltbevölkerung (01.10.2010)                      //3

int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P002K4_Const";
    //=========================================  
    long long llWBV = WBV;                                                          //4
    double dWBV     = WBV;                                                          //5
    double dEZ      = EZ;                                                           //6
    double dLn      = log (dEZ);                                                    //7
    double dLg      = log10 (dEZ);                                                  //8
    printConsole(str);

    printf ("Eulersche Zahl                                : %.15f\n", dEZ);        //9 
    printf ("dekadischer logarithmus von EZ                : %.15lf\n", dLg);       //10
    printf ("logarithmus naturalis von EZ                  : %.15lf\n", dLn);       //11
    printf ("\n");
    printf ("Welbev\x94lkerung als int                        : %i\n", llWBV);      //12
    printf ("Welbev\x94lkerung als long int                   : %li\n", llWBV);     //13
    printf ("Welbev\x94lkerung als long long                  : %lli\n", llWBV);    //14
    printf ("Welbev\x94lkerung als long (hex-Darst. klein)    : %lx\n", llWBV);     //15
    printf ("Welbev\x94lkerung als long long (hex-Darst. gro\xe1): %llX\n", llWBV); //16
    printf ("\n");
    printf ("Welbev\x94lkerung als double                     : %.0f\n", dWBV);     //17
    printf ("Welbev\x94lkerung als double (Exp.-Darst.)       : %.1e\n", dWBV);     //18
    return 0;
}