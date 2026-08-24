// P007K7_BiblioExcept.cpp
#include "stdafx.h"
#include <iostream> 
#include <string> 
#include <stdexcept>                                                        //1
using namespace std;                                                   
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
#define iMAX_ERRSTR 1024                                                       

int main (int argc, char *argv[])
{
    //=========================================
    CONST WCHAR * str = L"P007K7_BiblioExcept";
    printConsole (str);
    //========================================= 
    char cError[iMAX_ERRSTR]; 
    try                                                                         
    {
        if (argc !=4)                                                       //2
        {
            invalid_argument Err ("Invalid arguments.\n");                  //3
            throw Err;                                                      //4
        }
        else
        {
            cout << "Arument 1: " << argv[1] << endl;                       //5
            cout << "Arument 2: " << argv[2] << endl;
            cout << "Arument 3: " << argv[3] << endl;

            string str1;
            string str2("ABC");

            str1 = move (str2);
            cout << "Arument 1: " << argv[1] << endl;                       //5
            cout << "Arument 2: " << argv[2] << endl;
            cout << "Arument 3: " << argv[3] << endl;
        }

    }
    catch (invalid_argument &Err)                                           //6
    {
        cout << Err.what ();                                                //7
    }
    catch (...)                                                             //8                                         
    {
        int iErr = GetLastError ();                                             
        strerror_s (cError, iMAX_ERRSTR, iErr);                               
        cout << endl << __DATE__ << "; " << __TIME__ << "; Error in " 
             << __FUNCTION__ << ". Error: " << cError << endl;
    }
    return 0;                                                                                                                         
} 