// P002K7_TryThrowCatch.cpp
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
#define iMAX_ERRSTR 1024                                                       

int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P002K7_TryThrowCatch";
    printConsole (str);
    //========================================= 
    errno_t iError; 
    FILE * p2File; 
    char cError[iMAX_ERRSTR]; 
    try                                                                         //1
    {
        iError = fopen_s (&p2File, "NoFileFound.TXT", "r");                        
        if  (iError)                                                               
            throw iError;                                                       //2
        else
            //iError = fclose (p2File);          
        cout << "Test" << endl;
    }
    catch (int iErr)                                                            //3
    {
        strerror_s (cError, iMAX_ERRSTR, iErr);                               
        cout << __DATE__ << "; " << __TIME__ << "; Error in " << __FUNCTION__ 
             << ". Error: " << cError << endl;                                  //4
    }
    return 0;                                                                                                                         
} 