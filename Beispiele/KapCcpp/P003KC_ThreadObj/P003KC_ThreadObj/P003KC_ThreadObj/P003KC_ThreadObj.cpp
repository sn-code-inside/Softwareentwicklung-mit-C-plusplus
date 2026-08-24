// P003KE_ThreadObj.cpp
#include "stdafx.h"
#include <windows.h> 
#include <stdio.h>
#include "cConsole.h"
#include <iostream>
using namespace std;

DWORD WINAPI ThreadGreen( LPVOID lpParam )                                          //1
{
    cConsole* cons = (cConsole*)lpParam;                                            //2
    COORD Pos; bool bEnd = false; Pos.X = 50; Pos.Y = 2;
    char strGreen[128] ={0}; int iGreenNumb = 0;
    sprintf_s (strGreen, 128, "Konsolen-Handle Green");
    cons->enterSection();                                                           //3           
    cons->printfStrWithColorAtPos(Pos, strGreen, ciLGreen);
    cons->leaveSection(); 
    int iColor = ciLGreen;                                                          //4                                                                   
    Pos.Y++;
    while (!bEnd)
    {
        sprintf_s (strGreen, 128, "%i", iGreenNumb++);
        cons->enterSection();
        cons->printfStrWithColorAtPos(Pos, strGreen, iColor);                       //5
        cons->leaveSection();
        MSG msg;
        msg.message = 0;       
        BOOL bReceived = PeekMessage (&msg, 0, 0, 0, PM_REMOVE );
        if (bReceived==TRUE)
        {
            int iRecv = msg.wParam;                                                 //6                              
            if (iRecv == (int)'g')                                                  //7
                bEnd = true;                                                        //8
            else if ((iRecv>=0) && (iRecv<=0x0f) )                                  //9
            {
                iColor = iRecv; 
                //cons->setReceived (true);
            }
        }               
        Sleep (1200);
    }
    Pos.Y++;
    cons->enterSection();
    cons->printfStrWithColorAtPos(Pos, "end of ThreadGreen", ciLGreen);
    cons->leaveSection();    
    return 0; 
} 

int main(int argc, char* argv[])
{
    cConsole myConsole;                                                             //10
    //=========================================
    LPCTSTR str = L"P003KE_ThreadObj";
    myConsole.printConsole(str);
    //=========================================
    
    HANDLE Array_Of_Thread_Handles[1];
    myConsole.initSection();                                                        //11
    HANDLE hThreadGreen = 0; DWORD dwTID;
    char strGreen[128] ={0};

    bool bEndMain = false; char cChr     = 0; 
    COORD cHintPos;
    cHintPos.X = 10;
    cHintPos.Y = 2;
    myConsole.enterSection();
    myConsole.printfStrWithColorAtPos(cHintPos, "Waehle Farben aus!", ciWhite);
    myConsole.leaveSection();
    hThreadGreen = CreateThread( NULL, 0, ThreadGreen,                              //12
        &myConsole, 0, &dwTID);     
    int iPGreen = GetThreadPriority (hThreadGreen);
    int iErr = SetThreadPriority (hThreadGreen, THREAD_PRIORITY_HIGHEST);
    Array_Of_Thread_Handles[0] = hThreadGreen;
    //myConsole.setReceived (true);
    while (!bEndMain)                                                               //13            
    {
        cChr = myConsole.getKey();                                                
        //myConsole.clearKeyBuffer();
        if (cChr)
        { 
            if (cChr == 'g')                                                        //14                                          
            {
                BOOL bRet = PostThreadMessage (dwTID, WM_COMMAND, 'g', 0);
                WaitForMultipleObjects(1, &Array_Of_Thread_Handles[0], TRUE, INFINITE);
                bEndMain = true;
                myConsole.enterSection();
                myConsole.delLine (cHintPos, 33);
                myConsole.printfStrWithColorAtPos(cHintPos, "Start endOfThread", ciWhite);
                myConsole.leaveSection();
            }
            else if ( (cChr >= '0')&&(cChr <= '9')||(cChr >= 'a')&&(cChr <= 'f') )  //15 
            {
                char strNumb[2]; strNumb[0] = cChr; strNumb[1] = 0;
                char * strEnd; long iColor = strtol (strNumb, &strEnd, 16);
                myConsole.setReceived (false);
                BOOL bRet = PostThreadMessage (dwTID, WM_COMMAND, iColor, 0);       //16

                myConsole.enterSection();
                myConsole.delLine (cHintPos, 33);
                sprintf_s (strGreen, 128, "Aktuelle Farbe: %s (0x%x)", myConsole.strColor2String(iColor), iColor);
                myConsole.printfStrWithColorAtPos(cHintPos, strGreen, ciWhite);
                myConsole.leaveSection();
            }
        }
    }
    CloseHandle(hThreadGreen);
    return 0;                                                          
}
