// P001K7_PrtErr.cpp
#include "stdafx.h"
#include <iostream>                                                     
using namespace std;                                                   
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
#define iMAX_ERRSTR 1024                                                        //1

int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P001K7_PrtErr";
    printConsole (str);
    //========================================= 
    errno_t iError; FILE * p2File; char cError[iMAX_ERRSTR]; int iErrIdx;       //2
    iError = fopen_s (&p2File, "NoFileFound.TXT", "r");                         //3
    if  (iError)                                                                //4
    {
        perror (NULL);                                                          //5
        perror ("NoFileFound.TXT nicht gefunden!");                             //6
        strerror_s (cError, iMAX_ERRSTR, iError);                               //7
        cout << "strerror_s-Error: " << cError << endl; 
        int iWinErr = GetLastError ();
        strerror_s (cError, iMAX_ERRSTR, iWinErr); 
        cout << "Windows-Error   : " << cError << "\n\n"; 
    }
    else
        iError = fclose (p2File);                                               //8                                

    int iErr=0;                                                                 //9
    cout << "Ausgabe der FehlerCode\n";  
    for (iErrIdx = 0; iErrIdx < 43 ; iErrIdx ++)                                
    {
        iErr = strerror_s (cError, iMAX_ERRSTR, iErrIdx);                       //10
        if (0==iErr)                                                            //11
            strerror_s (cError, iMAX_ERRSTR, iErrIdx);                          
        else
            strerror_s (cError, 256, iErr);                                     //12
        cout << "Code : " << (iErr?iErr:iErrIdx)                                //13
             << ";\t Text : " << cError << endl;
    }
    return 0;                                                                                                                         
}  