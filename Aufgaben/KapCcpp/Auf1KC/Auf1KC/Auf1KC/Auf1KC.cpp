// Auf1KC.cpp
#include "stdafx.h"
#include <windows.h> 
#include <stdio.h>
#include "cConsole.h"
#include <iostream>
using namespace std;

DWORD WINAPI ThreadGreen( LPVOID lpParam )                                          
{
    cConsole* cons = (cConsole*)lpParam;                                            
    COORD Pos; bool bEnd = false; Pos.X = 50; Pos.Y = 2;
    char strGreen[128] ={0}; int iGreenNumb = 0;
    sprintf_s (strGreen, 128, "Konsolen-Handle Green");
    cons->enterSection();                                                                     
    cons->printfStrWithColorAtPos(Pos, strGreen, ciLGreen);
    cons->leaveSection(); 
    int iColor = ciLGreen;                                                                                                                            
    Pos.Y++;
    while (!bEnd)
    {
        sprintf_s (strGreen, 128, "%i", iGreenNumb++);
        cons->enterSection();
        cons->printfStrWithColorAtPos(Pos, strGreen, iColor);                       
        cons->leaveSection();
        MSG msg;
        msg.message = 0;       
        BOOL bReceived = PeekMessage (&msg, 0, 0, 0, PM_REMOVE );
        if (bReceived==TRUE)
        {
            int iRecv = msg.wParam;                                                                              
            if (iRecv == (int)'g')                                                  
                bEnd = true;                                                        
            else if ((iRecv>=0) && (iRecv<=0x0f) )                                  
            {
                iColor = iRecv; 
                cons->setReceived (true);       //Hier "sagt" der Thread, dass er die gedrückte Taste verarbeitet hat
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
    cConsole myConsole;                                                             
    //=========================================
    LPCTSTR str = L"Auf1KC";
    myConsole.printConsole(str);
    //=========================================
    
    HANDLE Array_Of_Thread_Handles[1];
    myConsole.initSection();                                                        
    HANDLE hThreadGreen = 0; DWORD dwTID;
    char strGreen[128] ={0};

    bool bEndMain = false; char cChr     = 0; 
    COORD cHintPos;
    cHintPos.X = 10;
    cHintPos.Y = 2;
    myConsole.enterSection();
    myConsole.printfStrWithColorAtPos(cHintPos, "Waehle Farben aus!", ciWhite);
    myConsole.leaveSection();
    hThreadGreen = CreateThread( NULL, 0, ThreadGreen,                              
        &myConsole, 0, &dwTID);     
    Array_Of_Thread_Handles[0] = hThreadGreen;
    myConsole.setReceived (true);                   //Hier gehen Sie davon aus, dass alle Tasten gelesen wurden
    while (!bEndMain)                                                                           
    {  
        
        while (false == myConsole.getReceived ())   //Hier fragen Sie nach, ob alle Testen schon aus
        {                                           //dem Tastatur-Puffer entfernt worden sind.
            cChr = myConsole.getKey();              //Falls nicht, so holen Sie alle ab.
        }
        
        cChr = 0;
        cChr = myConsole.getKey();                  //Und erst danach lesen Sie die Tastatur aus.                                             
        if (cChr)
        { 
            if (cChr == 'g')                                                                                                
            {
                BOOL bRet = PostThreadMessage (dwTID, WM_COMMAND, 'g', 0);
                WaitForMultipleObjects(1, &Array_Of_Thread_Handles[0], TRUE, INFINITE);
                bEndMain = true;
                myConsole.enterSection();
                myConsole.delLine (cHintPos, 33);
                myConsole.printfStrWithColorAtPos(cHintPos, "Start endOfThread", ciWhite);
                myConsole.leaveSection();
            }
            else if ( (cChr >= '0')&&(cChr <= '9')||(cChr >= 'a')&&(cChr <= 'f') )   
            {
                char strNumb[2]; strNumb[0] = cChr; strNumb[1] = 0;
                char * strEnd; long iColor = strtol (strNumb, &strEnd, 16);
                myConsole.setReceived (false);      //Vor dem Wegsenden (PostThreadMessage) merken Sie sich, dass der 
                                                    //Thread diese Taste noch nicht verarbeitet haben kann!
                BOOL bRet = PostThreadMessage (dwTID, WM_COMMAND, iColor, 0);       

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

