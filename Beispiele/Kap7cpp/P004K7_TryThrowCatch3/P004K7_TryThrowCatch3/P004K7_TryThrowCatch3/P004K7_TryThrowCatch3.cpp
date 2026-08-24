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

int main(void) {
    errno_t iError;
    FILE* p2File;
    char cError[iMAX_ERRSTR];
    try
    {
        //iError = fopen_s (&p2File, "..\\Debug\\P004K7_TryThrowCatch3D.exe", "r");
        iError = fopen_s(&p2File, "P004K7_TryThrowCatch3D.exe", "r");
        strerror_s(cError, iMAX_ERRSTR, iError);
        if (0 == iError)
            iError = fclose(p2File);

        iError = fopen_s(&p2File, "NoFileFound.TXT", "r");
        if (0 == iError)
            iError = fclose(p2File);

        int i; int j = 1;
        for (i = 2; i > -1; i--)
        {
            cout << "j: " << j << "; i: " << i;
            j = 8 / i;                                                            //1
            cout << "; division OK" << endl;
        }

    }
    catch (char* strErr)
    {
        cout << endl << __DATE__ << "; " << __TIME__ << "; Error in "
            << __FUNCTION__ << ". Error1: " << strErr << endl;
    }
    catch (int iErr)
    {
        strerror_s(cError, iMAX_ERRSTR, iErr);
        cout << endl << __DATE__ << "; " << __TIME__ << "; Error in "
            << __FUNCTION__ << ". Error2: " << cError << endl;
    }
    catch (...)
    {
        int iErr = GetLastError();                                             //2
        strerror_s(cError, iMAX_ERRSTR, iErr);
        cout << endl << __DATE__ << "; " << __TIME__ << "; Error in "
            << __FUNCTION__ << ". Error3: " << cError << endl;
    }
    return 0;
}