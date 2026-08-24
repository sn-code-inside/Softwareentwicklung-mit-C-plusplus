// P03KA_FileWrite.cpp
#include "stdafx.h"
#include "P002K8_fileUtil.h"
#include <iostream>
using namespace std;  
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
#define FNAME "WFile.TXT"                                           //1  
#define FNAMEOLD "WFile.OLD"                                        //2
#define MAX_CHR 1113
int main (void)
{ 
    //=========================================
    LPCTSTR str = L"P04K8_FileWrite";
    printConsole(str);
    //=========================================
    char ucBuffer[MAX_CHR];                                         //3
    cFUtils file(FNAME);                                            //4
    bool bExist = file.fileExist ();                                //5
    if (bExist)                                                     //6           
    {
        cFUtils file(FNAMEOLD);                                     //7
        if (file.fileExist())                                       //8
            remove (FNAMEOLD);                                      //9
        rename (FNAME, FNAMEOLD);                                   //10
    }
    bool bEnd = false;                                              //11
    do
    {
        //cin >> ucBuffer;
        cin.getline (ucBuffer, MAX_CHR-2);                          //12
        strcat_s (ucBuffer, "\r\n");                                //13
        (ucBuffer[0]=='!')?(bEnd=true):file.writeFile (ucBuffer);   //14
    }while (!bEnd);                                                 //15      
    return 0;
}