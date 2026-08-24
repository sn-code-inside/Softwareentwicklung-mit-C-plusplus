// P002KE_multiThreading.cpp
#include "stdafx.h"
#include <windows.h> 
#include <stdio.h>
#include "consUtils.h"
CRITICAL_SECTION consSection_;                                          //1
HANDLE  hConsole_;                                                      //2
/*===========================================================================*/
/* Desc.: Setzt das consSection_                                             */
/* In   : -                                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
void enterSection (void)                                                //3
{
    EnterCriticalSection (&consSection_);
}
/*===========================================================================*/
/* Desc.: Gibt die consSection_  wieder frei                                 */
/* In   : -                                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
void leaveSection (void)                                                //4
{
    LeaveCriticalSection (&consSection_);
}
/*===========================================================================*/
/* Desc.: Initialisiert die consSection_                                     */
/* In   : -                                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
void initSection (void)                                                 //5
{
    InitializeCriticalSection (&consSection_);
}
DWORD WINAPI ThreadRed( LPVOID lpParam )                                //6
{
    COORD Pos; bool bEnd = false; Pos.X = 8; Pos.Y = 2;                 //7
    int iRedNumb = 0; char strRed[128] ={0};
    sprintf_s (strRed, 128, "Konsolen-Handle Red: %x", (unsigned int)hConsole_);
    enterSection();                                                     //8
    printfStrWithColorAtPos(hConsole_, Pos, strRed, ciRed);
    leaveSection();                                                     //9
    Pos.Y++;
    while (!bEnd)
    {
        sprintf_s (strRed, 128, "%i", iRedNumb++);
        enterSection();                                                 //10
        printfStrWithColorAtPos(hConsole_, Pos, strRed, ciRed);
        leaveSection();
        MSG msg;
        msg.message = 0;
        BOOL bReceived = PeekMessage (&msg, 0, 0, 0, PM_REMOVE );
        if (bReceived==TRUE)
        {
            int iRecv = msg.wParam;
            if ( (iRecv == (int)'r') || (iRecv == (int)'x') )
                bEnd = true;
        }  

        Sleep (500);
    }
    Pos.Y++;
    enterSection();
    printfStrWithColorAtPos(hConsole_, Pos, "end of ThreadRed", ciRed);
    leaveSection();
    return 0; 
} 

DWORD WINAPI ThreadGreen( LPVOID lpParam ) 
{
    COORD Pos; bool bEnd = false; Pos.X = 50; Pos.Y = 2;
    char strGreen[128] ={0}; int iGreenNumb = 0;
    sprintf_s (strGreen, 128, "Konsolen-Handle Green: %x", (unsigned int)hConsole_);
    enterSection();
    printfStrWithColorAtPos(hConsole_, Pos, strGreen, ciGreen);
    leaveSection();
    int iColor = ciGreen;                                               //11                           
    Pos.Y++;
    while (!bEnd)
    {
        sprintf_s (strGreen, 128, "%i", iGreenNumb++);
        enterSection();
        printfStrWithColorAtPos(hConsole_, Pos, strGreen, iColor);
        leaveSection();
        MSG msg;
        msg.message = 0;
        //BOOL bReceived = GetMessage(&msg,0,0,0);   //wartet           //12
        BOOL bReceived = PeekMessage (&msg, 0, 0, 0, PM_REMOVE );
        if (bReceived==TRUE)
        {
            int iRecv = msg.wParam;                                     //13
            if ( (iRecv == (int)'g') || (iRecv == (int)'x') )
                bEnd = true;
            else if ((iRecv>=0) && (iRecv<=0x0f) )
                iColor = iRecv;                                         //14
        }               
        Sleep (900);
    }
    Pos.Y++;
    enterSection();
    printfStrWithColorAtPos(hConsole_, Pos, "end of ThreadGreen", ciGreen);
    leaveSection();    
    return 0; 
} 

int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR str = L"multiThreading";
    printConsole(str);
    //=========================================
    int iDataThreadRed   = 1; int iDataThreadGreen = 2;
    HANDLE Array_Of_Thread_Handles[2];
    hConsole_ = NULL;
    if( (hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE)) == INVALID_HANDLE_VALUE )  
        return 1;

    initSection();
    HANDLE hThreadRed   = 0; HANDLE hThreadGreen = 0;
    DWORD dwThreadIDRed;     DWORD dwThreadIDGreen;
    hThreadRed = CreateThread( NULL, 0, ThreadRed, &iDataThreadRed, 0, &dwThreadIDRed);  
    if ( hThreadRed == NULL)
        ExitProcess(iDataThreadRed);   
    hThreadGreen = CreateThread( NULL, 0, ThreadGreen, 
        &iDataThreadGreen, 0, &dwThreadIDGreen);  
    if ( hThreadGreen == NULL)
        ExitProcess(iDataThreadGreen);    
    Array_Of_Thread_Handles[0] = hThreadRed;
    Array_Of_Thread_Handles[1] = hThreadGreen;
    bool bEndMain = false; char cChr     = 0; 
    while (!bEndMain)                                                   //15
    {
        cChr = getKey();                                                //16
        if (cChr)
        { 
            if (cChr == 'x')                                            //17
            {
                BOOL bRet = PostThreadMessage (dwThreadIDGreen, WM_COMMAND, 'g', 0);
                WaitForMultipleObjects(1, &Array_Of_Thread_Handles[1], TRUE, INFINITE);
                bRet = PostThreadMessage (dwThreadIDRed, WM_COMMAND, 'r', 0);
                bEndMain = true;
            }
            else if (cChr == 'g')                                       //18
            {
                BOOL bRet = PostThreadMessage (dwThreadIDGreen, WM_COMMAND, cChr, 0);
            }
            else if ( (cChr >= '0')&&(cChr <= '9')||(cChr >= 'a')&&(cChr <= 'f') )  //19
            {
                char strNumb[2]; strNumb[0] = cChr; strNumb[1] = 0;
                char * strEnd;
                long iColor = strtol (strNumb, &strEnd, 16);
                BOOL bRet = PostThreadMessage (dwThreadIDGreen, WM_COMMAND, iColor, 0);
            }
            else if (cChr == 'r')                                       //20
            {
                BOOL bRet = PostThreadMessage (dwThreadIDRed, WM_COMMAND, cChr, 0);
            }
        }
    }
    WaitForMultipleObjects( 2, Array_Of_Thread_Handles, TRUE, INFINITE);
    CloseHandle(hThreadRed);
    CloseHandle(hThreadGreen);
    return 0;                                                           //21
}
