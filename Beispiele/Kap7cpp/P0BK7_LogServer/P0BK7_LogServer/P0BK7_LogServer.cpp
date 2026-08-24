// P0BK7_LogServer.cpp 
//
#pragma once
#include <iostream>
#include "..\..\P0BK7_LogTools\CLogTool.h"
#include "..\..\P0BK7_LogTools\CMutex.h"
#include <fstream>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
//============================================= 
int iCurrDay_ = -1;             //Sichert das Setzen des aktuellen Tages bei Neustart.
CLogTool log_;                  //Globale LOG-Variable

// SendObsrver ================================
DWORD WINAPI SNDObserver(LPVOID lpParam)
{
    FILE* fp = NULL;
    char* logLines[LOG_MAX_LINES] = { 0 };
    int iLineCount = 0;

    int iSMonth = 0;
    int iSDay = 0;
    int iSYear = 0;

    while (1)
    {
        SYSTEMTIME sysTime;
        GetLocalTime(&sysTime);
        iSYear = sysTime.wYear;
        iSMonth= sysTime.wMonth;
        iSDay = sysTime.wDay;
        if (iCurrDay_ == -1)
            iCurrDay_ = iSDay;

        if (iSDay != iCurrDay_)                                 
        {
            for (int iLs = 0; iLs < MAX_LOG_SECTIONS; iLs++)        // Bei neuem Tag wird ein neues File angelegt
            {                                                       
                char sOldLogFileName[MAX_PATHNAME_LEN] = { 0 };
                char sLogFileName8[MAX_PATHNAME_LEN] = { 0 };
                char sLogFileName[MAX_PATHNAME_LEN] = { 0 };
                log_.getLogFileName8(sLogFileName8, iLs);
                sprintf_s(sOldLogFileName, MAX_PATHNAME_LEN, "%s_%02d.csv", sLogFileName8, iCurrDay_);
                DeleteFile((LPCTSTR)sOldLogFileName);
                log_.getLogFileName(sLogFileName, iLs);
                rename(sLogFileName, sOldLogFileName);
            }
            iCurrDay_ = iSDay;
        }

        for (int iLs = 0; iLs < MAX_LOG_SECTIONS; iLs++)
        {
            log_.logRead(iLs, &iLineCount, logLines);
            if (iLineCount > 0)                                 //Nur wenn Zeilen auf dem Shared Mem geschrieben wurde,
            {                                                   //werden sie auch ausgelesen.
                char sLogFileName[MAX_PATHNAME_LEN] = { 0 };
                log_.getLogFileName(sLogFileName, iLs);         //Ermittelt den Filenamen einer LOG_Section
                fopen_s(&fp, sLogFileName, "a");

                for (int j = 0; j < iLineCount; j++)
                {
                    if ((fp != NULL) )
                        fprintf(fp, "%s\n", logLines[j]);
                    printf("%s\n", logLines[j]);
                }

                if ((fp != NULL) )
                {
                    fclose(fp);
                    fp = NULL;
                }
            }
            else
                int i = 0;
        }
        Sleep(500);
    }
    return 0;
}
// SendObsrver =============================end
int main(void)
{
    //=========================================
    CONST WCHAR* str = L"P00BK7_LogServer";
    printConsole(str);
    //========================================= 

    int iThreadData = 1;
    HANDLE hdlXHPMain = CreateThread(NULL, 0, SNDObserver, &iThreadData, 0, NULL);

    cout << "Kein Sender gestartet. Warte auf Sender-Start....\n";
    while (1)
    {
        int iCheckSenderStart = 0;
        for (int iLs = 0; iLs < MAX_LOG_SECTIONS; iLs++)
        {
            log_.logPreInit(iLs, enRECEIVER);
            log_.logInit(iLs, enRECEIVER);
        }
        
        iCheckSenderStart = log_.checkSenderStarted();
        if (MAX_LOG_SECTIONS == iCheckSenderStart)
            break;
        else
            Sleep(1000);
        cout << ".";
    }
    cout <<  "\nSender gestarted\n\n";

    int i = 1;
    while (i)
    {
        Sleep(1000);
    }
    return 0;
}
