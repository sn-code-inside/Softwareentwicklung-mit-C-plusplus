// P0BK7_LogSender.cpp.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "..\..\P0BK7_LogTools\CLogTool.h"
#include "..\..\P0BK7_LogTools\CMutex.h"
//=============================================
#include <Windows.h>                                
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
//============================================= 
using namespace std;
CLogTool log_;
int iThreadIdx_ = 0;
unsigned long long getFreeSpace(wchar_t* strRootPathName)
{
    DWORD dwSectorPerCluster = 0;
    DWORD dwBytesPerSector = 0;
    DWORD dwNumbOfFreeClusters = 0;
    int bSucceed = 0;
    unsigned long long ullFreeSpaceInBytes = 0;

    log_.logWrite(enInfo, 0, __func__, (char*)"__Start__");

    bSucceed = GetDiskFreeSpace(strRootPathName, &dwSectorPerCluster, &dwBytesPerSector, &dwNumbOfFreeClusters, NULL);

    if (1 == bSucceed)
    {
        ullFreeSpaceInBytes = (unsigned long long)dwNumbOfFreeClusters * (unsigned long long)dwSectorPerCluster * (unsigned long long)dwBytesPerSector;

        iThreadIdx_++;
        log_.logWrite(enInfo, enMain, __func__, (char*)"__End__");
        return ullFreeSpaceInBytes;
    }
    else
    {
        log_.logWrite(enInfo, enMain, __func__, (char*)"__End__");
        return (unsigned long long) 0;
    }
}

DWORD WINAPI hdObserver(LPVOID lpParam)
{
    char strName[64] = { 0 };
    strcpy_s(strName, 64, __func__);

    int iID = GetCurrentThreadId();
    log_.saveThreadInfo(iID, (char*)__func__);
    Sleep(1000);
    while (1)
    {
        wchar_t wChr[4] = L"C:\\";
        unsigned long long ullFreeSpace = getFreeSpace(wChr);
        log_.logWrite(enError, enMain, __func__, (char*)"freeDiskSpace: %llu Bytes", ullFreeSpace);
        Sleep(3000);
    }
    return 0;
}

DWORD WINAPI IRObserver(LPVOID lpParam)
{
    char strName[64] = { 0 };
    strcpy_s(strName, 64, __func__);

    int iID = GetCurrentThreadId();
    log_.saveThreadInfo(iID, (char*)__func__);
    Sleep(1000);
    int iIRLoop = 0;
    while (1)
    {
        log_.logWrite(enInfo, enIRComm, __func__, (char*)"IRLoopCounter: %d", iIRLoop);
        Sleep(1333);
        iIRLoop++;
    }
    return 0;
}

DWORD WINAPI SRObserver(LPVOID lpParam)
{
    char strName[64] = { 0 };
    strcpy_s(strName, 64, __func__);

    int iID = GetCurrentThreadId();
    log_.saveThreadInfo(iID, (char*)__func__);
    Sleep(1000);
    int iSRLoop = 0;
    while (1)
    {
        log_.logWrite(enInfo, enSRComm, __func__, (char*)"SRLoopCounter: %d", iSRLoop);

        Sleep(1000);
        iSRLoop++;
    }
    return 0;
}

int main(void)
{
    //=========================================
    CONST WCHAR* str = L"P00BK7_LogSender";
    printConsole(str);
    //========================================= 

    log_.setGlobalLogLevel(enError);                                                                
    for (int iLs = 0; iLs < MAX_LOG_SECTIONS; iLs++)
    {
        log_.logPreInit(iLs, enSENDER);
        log_.logInit(iLs, enSENDER);
    }

    int iID = GetCurrentThreadId();
    log_.saveThreadInfo(iID, (char*)txt4SectionMain);

    int iThreadData = 1;
    HANDLE hdlMain = CreateThread(NULL, 0, hdObserver, &iThreadData, 0, NULL);

    HANDLE hdlIR = CreateThread(NULL, 0, IRObserver, &iThreadData, 0, NULL);

    HANDLE hdlSR = CreateThread(NULL, 0, SRObserver, &iThreadData, 0, NULL);

    for (int iLs = 0; iLs < MAX_LOG_SECTIONS; iLs++)
    {
        log_.logWrite(enInfo, iLs, __func__, (char*)"=== start of logSender, section: %d ===", iLs);
    }

    int i = 1;
    while (i)
    {
        Sleep(1000);
        cout << ".";
    }

    for (int iLs = 0; iLs < MAX_LOG_SECTIONS; iLs++)
    {
        log_.logWrite(enInfo, iLs, __func__, (char*)"=== end of logSender, section: %d ===", iLs);
    }
    return 0;
}

