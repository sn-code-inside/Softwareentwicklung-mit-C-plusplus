// P00DK5_Break.cpp
#include "stdafx.h"
#include <conio.h>                                                               
#include <iostream> 
using namespace std;
#include <ctime> 
#include <cmath> 
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_BUFF 1024                                   //1
int main (void)
{
    time_t tCurrTime, tStartTime, tEndTime;             //2                   
    char strDateTime[MAX_BUFF];                         //3                
    struct tm tLocalTime;                               //4
    errno_t uiError;                                    //5
    double dTime;                                       //6

    //=========================================
    CONST WCHAR * str = L"P00DK5_Break";
    printConsole(str);
    //========================================= 
    tStartTime = time (NULL);                           //7
    while (1)                                           //8               
    {
        tCurrTime = time(NULL);                         //9
        uiError = localtime_s (&tLocalTime, &tCurrTime);//10
        strftime (strDateTime, MAX_BUFF, 
                  "%d.%m.%y; %H:%M:%S", &tLocalTime);   //11
        cout << "\rAktuelle Zeit: " << strDateTime;     //12
        if (_kbhit())                                   //13
            break;                                      //14
    }
    tEndTime = time (NULL);                             //15
    dTime = difftime (tStartTime, tEndTime);            //16
    cout << "\nDas Programm lief " << (int)fabs(dTime) 
         << " Sekunde(n).\n";                           //17                    
    return 0;                                       
}