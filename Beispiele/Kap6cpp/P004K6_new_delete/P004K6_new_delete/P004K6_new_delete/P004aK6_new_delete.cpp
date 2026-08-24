//P004aK6_new_delete.cpp
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

#define iMAX    40000                                                               //1
#define iMAXCHR 150000                                                              //2
const int iMByte_ = 1024*1024;                                                      //3

struct tRamTest                                                                     //4
{
    char *cTest;                                                                    //5
    int *iMore;
};
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P004aK6_new_delete";
    printConsole (str);
    //========================================= 
    int iEnd=0;                                                                     //6
    tRamTest iTest[iMAX];                                                           //7
    do
    {
        int iIdx=0;                                                                 //8
        MEMORYSTATUSEX mState;                                                      //9
        memset (&mState, 0, sizeof (MEMORYSTATUSEX));                               //10
        mState.dwLength = sizeof (mState);                                          //11
        GlobalMemoryStatusEx (&mState);                                             //12
        cout << "Used RAM before new: "                                             //13
             << (mState.ullTotalPhys-mState.ullAvailPhys)/iMByte_ << " MegaByte; " 
             << "Total RAM : " << (mState.ullTotalPhys)/iMByte_ << " MegaByte\n\n"; //14 

        while (iIdx < iMAX)                                                         //15
        {
            iTest[iIdx].cTest = new char[iMAXCHR];                                  //16
            //iTest[iIdx].iMore = new int[4000];
            iIdx++;                                                                 //17
        }
        GlobalMemoryStatusEx (&mState);
        cout << "Used RAM after new : "                                             //18
             << (mState.ullTotalPhys-mState.ullAvailPhys)/iMByte_ << " MegaByte; " 
             << "Total RAM : " << (mState.ullTotalPhys)/iMByte_ << " MegaByte\n\n"; //19

        iIdx=0;
        while (iIdx< iMAX)
        {
            delete [] iTest[iIdx].cTest;                                            //20
            iTest[iIdx].cTest = NULL;                                               //21
            iIdx++;
        }
        GlobalMemoryStatusEx (&mState);
        cout << "Used RAM after del : "                                             //22
             << (mState.ullTotalPhys-mState.ullAvailPhys)/iMByte_ << " MegaByte; " 
             << "Total RAM : " << (mState.ullTotalPhys)/iMByte_ << " MegaByte\n\n"; //23
 
        cin >> iEnd;                                                                //24
    }
    while (1==iEnd);                                                                //25
    return 0;                                                    
}