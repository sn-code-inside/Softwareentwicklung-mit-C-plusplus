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
    errno_t iError;
    FILE* p2File;
    char cError[iMAX_ERRSTR];


    wchar_t buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);                                  // Name des EXE-Files inkl. Pfad

    try
    {
 //iError = fopen_s (&p2File, "..\\Debug\\P003K7_TryThrowCatch2D.exe", "r");   //1
        iError = fopen_s(&p2File, "P003K7_TryThrowCatch2D.exe", "r");          //2
        strerror_s(cError, iMAX_ERRSTR, iError);                               //3
        if (iError)                                                            //4
            throw cError;                                                      //5
        else
            iError = fclose(p2File);                                           //6

        iError = fopen_s(&p2File, "NoFileFound.TXT", "r");                     //7
        if (iError)
            throw iError;
        else
            iError = fclose(p2File);
    }
    catch (char* strErr)                                                        //8
    {
        cout << __DATE__ << "; " << __TIME__ << "; Error in " << __FUNCTION__
            << ". Error: " << strErr << endl;
    }
    catch (int iErr)                                                            //9
    {
        strerror_s(cError, iMAX_ERRSTR, iErr);
        cout << __DATE__ << "; " << __TIME__ << "; Error in " << __FUNCTION__
            << ". Error: " << cError << endl;
    }
    return 0;
} 