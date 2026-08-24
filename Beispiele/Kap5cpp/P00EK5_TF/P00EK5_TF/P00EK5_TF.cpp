// P00EK5_TF.cpp
#include "stdafx.h"
#include <iostream>  
using namespace std;
#include <ctime>                                                               //1
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_BUFF 1024                                   
int main (void)
{
    time_t tCurrTime;                                                          //2                        
    char strDateTime[MAX_BUFF];                                                //3                                  
    struct tm tLocalTime;                                                      //4                 
    errno_t uiError;                                                           //5                
    //=========================================
    CONST WCHAR * str = L"P00EK5_TF";
    printConsole(str);
    //========================================= 
    tCurrTime = time (NULL);                                                   //6                    
    uiError = localtime_s (&tLocalTime, &tCurrTime);                           //7
    strftime (strDateTime, MAX_BUFF, "%d.%m.%Y;\t%H:%M:%S", &tLocalTime);      //8
    cout << "Aktuelle Zeit: " << strDateTime << endl;   //9
    strftime (strDateTime, MAX_BUFF, "%d.%m.%y;\t%H:%M:%S", &tLocalTime);      //10
    cout << "               " << strDateTime << endl;   
    strftime (strDateTime, MAX_BUFF, "%d.%m.%y;\t%H:%M:%S Tag im Jahr   : %j", 
                                                            &tLocalTime);      //11   
    cout << "               " << strDateTime << endl;  
    strftime (strDateTime, MAX_BUFF, "%d.%b %y;\t%H:%M:%S", &tLocalTime);      //12   
    cout << "               " << strDateTime << endl;     
    strftime (strDateTime, MAX_BUFF, "%d.%B %y;\t%H:%M:%S", &tLocalTime);      //13   
    cout << "               " << strDateTime << endl;  
    strftime (strDateTime, MAX_BUFF, "%d.%m.%y;\t%H:%M:%S Wochentag     : %w", 
                                                            &tLocalTime);      //14   
    cout << "               " << strDateTime << endl;  
    strftime (strDateTime, MAX_BUFF, "%d.%m.%y;\t%H:%M:%S Kalenderwochen: %W", 
                                                            &tLocalTime);      //15   
    cout << "               " << strDateTime << endl;  
    strftime (strDateTime, MAX_BUFF, "%d.%m.%y;\t%H:%M:%S Zeitzone      : %Z", 
                                                            &tLocalTime);      //16   
    cout << "               " << strDateTime << endl;  
    strftime (strDateTime, MAX_BUFF, "%c", &tLocalTime);                       //17  
    cout << "               " << strDateTime << endl;  
    strftime (strDateTime, MAX_BUFF, "%x", &tLocalTime);                       //18  
    cout << "               " << strDateTime << endl;  
    strftime (strDateTime, MAX_BUFF, "%X", &tLocalTime);                       //19 
    cout << "               " << strDateTime << endl;  
    return 0; 
}