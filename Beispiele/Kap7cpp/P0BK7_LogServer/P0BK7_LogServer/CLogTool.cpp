#include "CLogTool.h"
#include <Windows.h>
#include <stdio.h>
#include <stdarg.h>

CLogTool::CLogTool(void)
{
    defineLogSrvIniData();
    mutex_ = new CMutex;
}

CLogTool::~CLogTool()
{
}

/*===========================================================================*/
/* Desc.: Vorinitialisierung der Log-Daten                                   */
/* In   : iLs: Log-SektionNummer (0, 1, 2); enLogType: LogTyp (Sender oder   */
/*        Empfänger/Server)                                                  */
/* Out  : int: 0: Ok; sonst Fehler                                           */
/*===========================================================================*/
int CLogTool::logPreInit(int iLs, enLogType Type)
{
    if ((iLs < 0) || (iLs >= MAX_LOG_SECTIONS))
        return -1;

    logAllSection_[iLs].iInitialized = 0;
    logAllSection_[iLs].iLock = 0;

    memset(&threadInfo_, 0, sizeof(tThreadInfo) * MAX_THREAD_COUNT);

    switch (Type)
    {
    case enSENDER:
        logAllSection_[iLs].LogLvl = (enLogLevelType)logSrvIniData_.iLogServerLevel[iLs];       //enInfo: Es sollte mindestens "informiert" werden              
        break;
    case enRECEIVER:
        logAllSection_[iLs].pcLogLocalBuf = (char *)malloc(sizeof(tShareMemBuf));               //Nur der logServer braucht diesen Speicher
        if (logAllSection_[iLs].pcLogLocalBuf == NULL)
            return -1;
        logAllSection_[iLs].LogLvl = (enLogLevelType)logSrvIniData_.iLogServerLevel[iLs];
    }
    return 0;
}

/*===========================================================================*/
/* Desc.: Auslesen der Ini-Daten und sichern dieser Daten in den LogDaten    */
/*        Aktivierung des Shared Memory                                      */
/* In   : iLs: Log-SektionNummer (0, 1, 2); enLogType: LogTyp (Sender oder   */
/*        Empfänger/Server)                                                  */
/* Out  : int: 0: Ok; sonst Fehler                                           */
/*===========================================================================*/
int CLogTool::logInit(int iLs, enLogType Type)
{
    int res = 0;

    if ((iLs < 0) || (iLs >= MAX_LOG_SECTIONS))
        return -1;

    if (logAllSection_[iLs].iInitialized == 0)
    {
        strcpy_s (logAllSection_[iLs].sLogShmLockName, SIZE, logSrvIniData_.sLogShmLockName[iLs]);
        strcpy_s(logAllSection_[iLs].sMapName, SIZE, logSrvIniData_.sMapName[iLs]);
        logAllSection_[iLs].iLastLine = 0;
        logAllSection_[iLs].iLock = 0;
        switch (Type)
        {
        case enSENDER:
            res = logOpenSharedMemory(&logAllSection_[iLs]);                                    //Shared Memory wird zuerst geöffnet    
            if (res != 0)
            res = logCreateSharedMemory(&logAllSection_[iLs]);                                  //Nur wenn das nicht geht, so wird kreiert.    
            break;
        case enRECEIVER:
            res = logOpenSharedMemory(&logAllSection_[iLs]);                                    //Der Emfänger/Server darf nur öffnen   
            break;
        }
    }
    return res;
}

/*===========================================================================*/
/* Desc.: Definiert die INI-Daten von logSender und logServer.               */
/* In   : -                                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
void CLogTool::defineLogSrvIniData(void)
{
    int iLs = 0;
    strcpy_s(logSrvIniData_.sLogShmLockName[iLs], SIZE, "SHAREDLOCK_MAIN");		                //1. LogSection; Name des Mutext-Objektes
    strcpy_s(logSrvIniData_.sMapName[iLs], SIZE, "SHAREDMEM_MAIN");	                            //Name des Shared Memorys

    strcpy_s(logSrvIniData_.sLogFileName[iLs], MAX_PATHNAME_LEN, "C:\\LOGSENDER\\LOG\\");       //Name und Pfad des LogFiles der 1. Sektion wird definiert
    strcat_s (logSrvIniData_.sLogFileName[iLs], MAX_PATHNAME_LEN, txt4SectionMain);
    strcat_s(logSrvIniData_.sLogFileName[iLs], MAX_PATHNAME_LEN, ".csv");
    strcpy_s(logSrvIniData_.sLogFileName8[iLs], MAX_PATHNAME_LEN,  "C:\\LOGSENDER\\LOG\\");     //Name des Files der "gestrigen" Tages wird vorbereitet
    strcat_s(logSrvIniData_.sLogFileName8[iLs], MAX_PATHNAME_LEN, txt4SectionMain);
    logSrvIniData_.iLogServerLevel[iLs] = enError;                                              //LogLevel ist für jede Sektion speziell setzbar
    logSrvIniData_.iWriteLogFiles[iLs] = 1;                                                     //Sektion-Hinwiese werden in einem File (txt4SectionMain) gesichert
    iLs++;

    strcpy_s(logSrvIniData_.sLogShmLockName[iLs], SIZE, "SHAREDLOCK_IR");		                //2. LogSection
    strcpy_s(logSrvIniData_.sMapName[iLs], MAX_PATHNAME_LEN, "SHAREDMEM_IR");

    strcpy_s(logSrvIniData_.sLogFileName[iLs], MAX_PATHNAME_LEN, "C:\\LOGSENDER\\LOG\\");
    strcat_s(logSrvIniData_.sLogFileName[iLs], MAX_PATHNAME_LEN, txt4SectionIRComm);
    strcat_s(logSrvIniData_.sLogFileName[iLs], MAX_PATHNAME_LEN, ".csv");
    strcpy_s(logSrvIniData_.sLogFileName8[iLs], MAX_PATHNAME_LEN, "C:\\LOGSENDER\\LOG\\");
    strcpy_s(logSrvIniData_.sLogFileName8[iLs], MAX_PATHNAME_LEN, "C:\\LOGSENDER\\LOG\\");
    strcat_s(logSrvIniData_.sLogFileName8[iLs], MAX_PATHNAME_LEN, txt4SectionIRComm);
    logSrvIniData_.iLogServerLevel[iLs] = enInfo;
    logSrvIniData_.iWriteLogFiles[iLs] = 1;
    iLs++;

    strcpy_s(logSrvIniData_.sLogShmLockName[iLs], SIZE, "SHAREDLOCK_SR");                       //3. LogSection; MAX_LOG_SECTIONS aktuell: 3
    strcpy_s(logSrvIniData_.sMapName[iLs], MAX_PATHNAME_LEN, "SHAREDMEM_SR");

    strcpy_s(logSrvIniData_.sLogFileName[iLs], MAX_PATHNAME_LEN, "C:\\LOGSENDER\\LOG\\");
    strcat_s(logSrvIniData_.sLogFileName[iLs], MAX_PATHNAME_LEN, txt4SectionSRComm);
    strcat_s(logSrvIniData_.sLogFileName[iLs], MAX_PATHNAME_LEN, ".csv");
    strcpy_s(logSrvIniData_.sLogFileName8[iLs], MAX_PATHNAME_LEN, "C:\\LOGSENDER\\LOG\\");
    strcat_s(logSrvIniData_.sLogFileName8[iLs], MAX_PATHNAME_LEN, txt4SectionSRComm);
    logSrvIniData_.iLogServerLevel[iLs] = enInfo;
    logSrvIniData_.iWriteLogFiles[iLs] = 1;
    iLs++;
}

/*===========================================================================*/
/* Desc.: LogFileName wird für entspr. Sektionm der Applikation übergeben    */
/* In   : iLs: Log-SektionNummer (0, 1, 2); sLogFileName: FileName für App   */
/* Out  : sLogFileName: FileName für App                                     */
/*===========================================================================*/
void CLogTool::getLogFileName(char* sLogFileName, int iLs)
{
    strcpy_s(sLogFileName, MAX_PATHNAME_LEN, logSrvIniData_.sLogFileName[iLs]);
}
/*===========================================================================*/
/* Desc.: LogFileName8 wird für entspr. Sektion der Applikation übergeben    */
/*        Bem.: LogFileName8 hat zunächst keine Extension                    */
/* In   : iLs: Log-SektionNummer (0, 1, 2); sLogFileName: FileName für App   */
/* Out  : sLogFileName: FileName für App                                     */
/*===========================================================================*/
void CLogTool::getLogFileName8(char* sLogFileName, int iLs)
{
    strcpy_s(sLogFileName, MAX_PATHNAME_LEN, logSrvIniData_.sLogFileName8[iLs]);
}
/*===========================================================================*/
/* Desc.: iWriteLogFiles wird für entspr. Sektionm der Applikation übergeben */
/* In   : iLs: Log-SektionNummer (0, 1, 2);                                  */
/* Out  : return: int iWriteLogFiles für App                                 */
/*===========================================================================*/
int CLogTool::getWriteLogFile(int iLs)
{
    return logSrvIniData_.iWriteLogFiles[iLs];
}
/*===========================================================================*/
/* Desc.: iLogServerLevel wird für entspr. Sektionm der Applikation übergeben*/
/* In   : iLs: Log-SektionNummer (0, 1, 2);                                  */
/* Out  : return: int iLogServerLevel für App                                */
/*===========================================================================*/
int CLogTool::getLogServerLevel(int iLs)
{
    return logSrvIniData_.iLogServerLevel[iLs];
}

/*===========================================================================*/
/* Desc.: Handelt ThreadID und ThreadName (ID und Name werden nach           */
/*        threadInfo_ gespeichert)                                           */
/*        Bem.: Bei Möglichkeiten einer gemeinsamen Nutzung von threadInfo_, */
/*              müsste der Speicher semaphoren-geschützt werden              */
/* In   : iID: ThreadID; sThreadName: Name des Threads                       */
/* Out  : -                                                                  */
/*===========================================================================*/
void CLogTool::saveThreadInfo(int iID, char* sThreadName)
{
    int iIdx = 0;
    while (iIdx < MAX_THREAD_COUNT)
    {
        if ((threadInfo_[iIdx].iThreadID == 0) && (threadInfo_[iIdx].sTheadName[0] == 0))
        {
            threadInfo_[iIdx].iThreadID = iID;
            strcpy_s(threadInfo_[iIdx].sTheadName, SIZE, sThreadName);
            break;
        }
        iIdx++;
    }
}
/*===========================================================================*/
/* Desc.: Gibt für eine ID den Namen des Threads zurück                      */
/*        Bem.: Bei Möglichkeiten einer gemeinsamen Nutzung von threadInfo_, */
/*              müsste der Speicher semaphoren-geschützt werden              */
/* In   : iID: ThreadID; sThreadName: Name des Threads                       */
/* Out  : -                                                                  */
/*===========================================================================*/
void CLogTool::getThreadName(int iID, char* sThreadName)
{
    int iIdx = 0;
    while (iIdx < MAX_THREAD_COUNT)
    {
        if (threadInfo_[iIdx].iThreadID == iID)
        {
            strcpy_s(sThreadName, SIZE, threadInfo_[iIdx].sTheadName);
            break;
        }
        iIdx++;
    }
    if (iIdx == MAX_THREAD_COUNT)
    {
        strcpy_s(sThreadName, SIZE, "Name not in list!");
    }
}


/*===========================================================================*/
/* Desc.: Erzeugt einen Shared Memory                                        */
/* In   : p2LogOneSec: Pointer auf tLogOneSection                            */
/* Out  : 0: Ok; sonst Fehler                                                */
/*===========================================================================*/
int CLogTool::logCreateSharedMemory(tLogOneSection* p2LogOneSec)
{
    void* memPtr = NULL;                                                                        //Speicher für Shared momory
    unsigned long long int iShmSize;
    int ret = 0;
    int err = 0;

    if (p2LogOneSec->iInitialized == 0)                                                         //0: Abschnitt wurde noch nicht initialisiert
    {
        iShmSize = sizeof(tShareMemBuf);

        /*
        if (p2LogOneSec->iLock == 0)                                                            //0: Mutex wurde noch nicht definiert
        {                                                                                       //Mutex wird definiert; mit sLogShmLockName; iLock wird returned
        //   ret = CmtNewLock(p2LogOneSec->sLogShmLockName, 0, &(p2LogOneSec->iLock));
            if (ret != 0)
                return ret;                                                                     //falls ret!=0, so muss abgebrochen werden                                                      
        }
        */
        mutex_->lockMutex(); //ret = CmtGetLock(p2LogOneSec->iLock);                                                 //Jetzt wird der Bereich gelockt     
        if (ret != 0)                                                                           //Der Lock sichert, dass nur ein Mal CreateFileMapping aktiviert wird
            return ret;

        p2LogOneSec->hMemMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD)iShmSize, (LPCWSTR)p2LogOneSec->sMapName);
        if (p2LogOneSec->hMemMapFile == NULL)                                                   //falls p2LogOneSec->hMemMapFile!=NULL, so kann das Handle MapViewOfFile
        {                                                                                       //übergeben werden                       
            err = GetLastError();
        //   CmtReleaseLock(p2LogOneSec->iLock);
            return err;
        }

        memPtr = (LPSTR)MapViewOfFile(p2LogOneSec->hMemMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
        if (memPtr == NULL)                                                                     //lass memPtr!=NULL, so der Shared RAM bekannt
        {
            err = GetLastError();
            CloseHandle(p2LogOneSec->hMemMapFile);
        //   CmtReleaseLock(p2LogOneSec->iLock);
            return err;
        }

        p2LogOneSec->p2ShmBuf = (tShareMemBuf*)memPtr;                                          //p2ShmBuf ist somit für logRead als auch logWrite für eine Sektion definiert
        memset(memPtr, 0, sizeof(tShareMemBuf));
        mutex_->unlockMutex(); //CmtReleaseLock(p2LogOneSec->iLock);                                                   //Jetzt wird der Bereich wieder frei gegeben
        p2LogOneSec->iInitialized = 1;
    }
    return 0;
}

/*===========================================================================*/
/* Desc.: Öffnet Shared Memory; siehe Kommentare zu logCreateSharedMemory    */
/* In   : p2LogOneSec: Pointer auf tLogOneSection                            */
/* Out  : 0: Ok; sonst Fehler                                                */
/*===========================================================================*/
int CLogTool::logOpenSharedMemory(tLogOneSection* p2LogOneSec)
{
    void* memPtr = NULL;
    int ret = 0;
    int err = 0;

    if (p2LogOneSec->iInitialized == 0)
    {
        /*
        if (p2LogOneSec->iLock == 0)
        {
            //ret = CmtNewLock(p2LogOneSec->sLogShmLockName, 0, &(p2LogOneSec->iLock));
            if (ret != 0)
                return ret;
        }
        */
        mutex_->lockMutex();  //ret = CmtGetLock(p2LogOneSec->iLock);
        if (ret != 0)
            return ret;

        p2LogOneSec->hMemMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, (LPCWSTR) p2LogOneSec->sMapName);
        if (p2LogOneSec->hMemMapFile == NULL)
        {
            err = GetLastError();
            mutex_->unlockMutex(); //CmtReleaseLock(p2LogOneSec->iLock);
            return err;
        }

        memPtr = (LPSTR)MapViewOfFile(p2LogOneSec->hMemMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
        if (memPtr == NULL)
        {
            err = GetLastError();
            CloseHandle(p2LogOneSec->hMemMapFile);
            mutex_->unlockMutex(); //CmtReleaseLock(p2LogOneSec->iLock);
            return err;
        }
        p2LogOneSec->p2ShmBuf = (tShareMemBuf*) memPtr;
        p2LogOneSec->iSenderRuns = 1;
        mutex_->unlockMutex(); //CmtReleaseLock(p2LogOneSec->iLock);
        p2LogOneSec->iInitialized = 1;
    }
    return 0;
}

/*===========================================================================*/
/* Desc.: Überprüft, ob das Shared Memory zur Verfügung steht                */
/* In   : -                                                                  */
/* Out  : MAX_LOG_SECTIONS: Ok; sonst Fehler                                 */
/*===========================================================================*/
int CLogTool::checkSenderStarted(void)
{
    int iStarted = 0;
    int iLs = 0;
    while (iLs < MAX_LOG_SECTIONS)
    {
        iStarted = iStarted + logAllSection_[iLs].iSenderRuns;
        iLs++;
    }
    return iStarted;
}

/*===========================================================================*/
/* Desc.: Liest vom Shared Memory                                            */
/* In   : iLs: Log-SektionNummer (0, 1, 2); Pointer auf iLineCount;          */
/*        Pointer auf ein Arry von char*                                     */
/* Out  : -                                                                  */
/*===========================================================================*/
void CLogTool::logRead(int iLs, int* iLineCount, char** p2p2Lines)
{
    int lines = 0;
    int i = 0;
    *iLineCount = 0;

    if ((iLs < 0) || (iLs >= MAX_LOG_SECTIONS))
        return;

    if (logAllSection_[iLs].iInitialized != 1)
        return;

    mutex_->lockMutex(); //CmtGetLock(logAllSection_[iLs].iLock);                                                    //Lock Bereich, damit nur eine Applikation zugreifen kann
    if (logAllSection_[iLs].p2ShmBuf->iAktLine != logAllSection_[iLs].iLastLine)
    {                                                                                           //Nur wenn iAktLine geändert wurde (bei logWrite) erfolgt eine Lesen 
        if (logAllSection_[iLs].p2ShmBuf->iAktLine > logAllSection_[iLs].iLastLine)
        {                                                                                       //Normalfall: iAktLine>iLastLine
            lines = logAllSection_[iLs].p2ShmBuf->iAktLine - logAllSection_[iLs].iLastLine;
            memcpy(logAllSection_[iLs].pcLogLocalBuf,                                           //Kopiere Zeilen aus dem Shared Memory in den Lokalen Buffer pcLogLocalBuf 
                &(logAllSection_[iLs].p2ShmBuf->asLines[logAllSection_[iLs].iLastLine + 1][0]),
                lines * LOG_MESSAGE_SIZE);
            if (logAllSection_[iLs].p2ShmBuf->iAktLine >= lines)                                //iAktLine wird zurückgesetzt, da alles gelesen wurde
                logAllSection_[iLs].p2ShmBuf->iAktLine = logAllSection_[iLs].p2ShmBuf->iAktLine - lines;
        }
        logAllSection_[iLs].iLastLine = logAllSection_[iLs].p2ShmBuf->iAktLine;
    }

    if (lines > 0)
    {
        for (i = 0; i < lines; i++)
        {                                                                                       //pcLogLocalBuf wird der App (p2p2Lines) übergeben
            p2p2Lines[*iLineCount] = &(logAllSection_[iLs].pcLogLocalBuf[i * LOG_MESSAGE_SIZE]);
            (*iLineCount)++;
        }
    }
    mutex_->unlockMutex(); //CmtReleaseLock(logAllSection_[iLs].iLock);	                                            //Jetzt kann der Lock-Bereich wieder frei gegeben werden  
}

/*===========================================================================*/
/* Desc.: Schreibt auf das Shared memory                                     */
/* In   : logLevel: Log-Level; iLs: Log-SektionNummer (0, 1, 2);             */
/*        sFunction: Name der aufrufenden Funktion; sFormat: Rest            */
/* Out  : 0: Ok; sonst Fehler                                                */
/*===========================================================================*/
int CLogTool::logWrite(enLogLevelType logLevel, int iLs, const char* sFunction, char* sFormat, ...)
{
    va_list args;
    char sMsg[1000] = { 0 };
    char sMessage[LOG_MESSAGE_SIZE] = { 0 };
    char sTransfer[LOG_MESSAGE_SIZE] = { 0 };
    char sThreadName[SIZE] = { 0 };

    int iMaxMsgLen = LOG_MESSAGE_SIZE - 1;
    char sLogLevel[20] = { 0 };
    char sFuncName[50] = { 0 };
    char sLogSect[50] = { 0 };

    SYSTEMTIME sysTime;
    int iBytesToTransfer = 0;
    int iBytesTransfered = 0;

    if ((iLs < 0) || (iLs >= MAX_LOG_SECTIONS))
        return -1;
    if (logAllSection_[iLs].LogLvl == enNoLog)
        return 0;
    if (logLevel == enNoLog)
        return 0;
    if (logAllSection_[iLs].iInitialized != 1)
        return -1;
    if (logAllSection_[iLs].LogLvl < logLevel)
        return 0;

    mutex_->lockMutex(); //CmtGetLock(logAllSection_[iLs].iLock);                                                    //Lock Bereich, damit nur eine Applikation zugreifen kann

    va_start(args, sFormat);                                                                    //logWrite ist printf-kompatibel
    vsprintf_s (sMsg, 10000, sFormat, args);
    va_end(args);

    switch (logLevel)                                                                           //Definition der LogLevel-Texte                                      
    {
    case enNoLog:
        strcpy_s(sLogLevel, 20, txt4NoLog);
        break;
    case enInfo:
        strcpy_s(sLogLevel, 20, txt4Info);
        break;
    case enError:
        strcpy_s(sLogLevel, 20, txt4Error);
        break;
    default:
        strcpy_s(sLogLevel, 20, "LLLLL");
        break;
    }
    switch (iLs)                                                                                //Definition der Sektionen
    {
    case 0:
        strcpy_s(sLogSect, 50, txt4SectionMain);
        break;
    case 1:
        strcpy_s(sLogSect, 50, txt4SectionIRComm);
        break;
    case 2:
        strcpy_s(sLogSect, 50, txt4SectionSRComm);
        break;
    default:
        strcpy_s(sLogSect, 50, "SSSSS");
        break;
    }

    strncpy_s (sFuncName, 50, sFunction, 25);
    GetLocalTime(&sysTime);

    iBytesToTransfer = (int)strlen(sMsg);
    iBytesTransfered = 0;

    int iDay = sysTime.wDay;
    int iMonth = sysTime.wMonth;
    int iYear = sysTime.wYear;

    int iID = GetCurrentThreadId();
    getThreadName(iID, sThreadName);

    while (iBytesToTransfer > 0)
    {
        strncpy_s(sTransfer, LOG_MESSAGE_SIZE , &sMsg[iBytesTransfered], iMaxMsgLen);           //copy der Message in den lokalen Buffer
        sTransfer[iMaxMsgLen] = 0;
        //dd.md.yyyy  ;hh:mm:ss      ; ms ;ll;ls;TN;FN;Msg
        sprintf_s (sMessage, LOG_MESSAGE_SIZE, "%02d.%02d.%04d;%02d:%02d:%02d;%03d;%s;%s;%s;%s;%s", iDay, iMonth, iYear, sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds,
            sLogLevel, sLogSect, sThreadName, sFuncName,
            sTransfer);                                                                         //Generierung der zu schreibenden Message: dd.mm.yyyy;hh:mm:ss;ms;LogLevel;LogSektion;threadName;functName;Message

        logAllSection_[iLs].p2ShmBuf->iAktLine++;                                               //iAktLine wird erhöht

        int iLnIdx = logAllSection_[iLs].p2ShmBuf->iAktLine;

        if (strlen(sMessage) > LOG_MESSAGE_SIZE)                                                //Message auf Size prüfen
            sMessage[LOG_MESSAGE_SIZE - 1] = 0;

        strcpy_s(logAllSection_[iLs].p2ShmBuf->asLines[iLnIdx], LOG_MESSAGE_SIZE, sMessage);    //Schreibe die Message in den Shared memory 

        iBytesTransfered += (int)strlen(sTransfer);
        iBytesToTransfer -= (int)strlen(sTransfer);
    }
    mutex_->unlockMutex(); //CmtReleaseLock(logAllSection_[iLs].iLock);
    return 0;
}