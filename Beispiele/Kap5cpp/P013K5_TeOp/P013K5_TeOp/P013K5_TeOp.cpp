//P013K5_TeOp.cpp
#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;
//=============================================
#include <Windows.h>
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
bool main(int argc, char *argv[])                           //1
{
    //=============================================
    CONST WCHAR * str = L"P013K5_TeOp";
    printConsole(str);
    //=============================================       
    BOOL bBOOL = -5;                                        //2
    bool bbool;
    int iSOB  = sizeof(BOOL);                               //3
    int iSOb  = sizeof(bool);
    cout << "Size des Types BOOL: " <<  iSOB << endl;       //4
    cout << "Size des Types bool: " <<  iSOb << endl;
    bbool = !(bBOOL?true:false);                            //5
    cout << "bBOOL ist " << (bBOOL?"TRUE":"FALSE") << endl; //6
    cout << "bbool ist " << (bbool?"true":"false") << endl; //7

    bBOOL = TRUE;
    bbool = bBOOL?true:false;                               //8
    return bbool;
}