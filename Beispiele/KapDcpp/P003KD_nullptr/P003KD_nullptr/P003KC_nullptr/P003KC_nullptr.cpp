// P003KD_nullptr.cpp
#include "stdafx.h"
#include <iostream>
using namespace std; 

int testFkt (char *p2Char)
{
    if (p2Char == nullptr)
        return 0;
    else
        return 1;
}
int testFkt (int iTest)
{
    if (iTest == 0)
        return 2;
    else 
        return 3;
}



//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_NUMB  5                                                                   
int main(int argc, char* argv[])
{
    //=========================================
    {
    LPCTSTR str = L"P003KD_nullptr";
    printConsole(str);
    }
    //=========================================
    cout << "testFkt (0)      : " << testFkt (0)      << endl;      //1
    cout << "testFkt (NULL)   : " << testFkt (NULL)   << endl;      //2
    cout << "testFkt (nullptr): " << testFkt (nullptr)<< endl;      //3
    return 0;
}


