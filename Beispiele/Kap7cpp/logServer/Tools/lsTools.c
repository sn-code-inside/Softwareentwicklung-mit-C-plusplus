//==============================================================================
//
// Title:		lsTools.c.c
// Purpose:		Methods and types for logSender and logServer
//
// Created on:	06.03.2023 at 17:34:26 by D. Duschl
//
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files
#include <Windows.h>
#include <utility.h>
#include <ansi_c.h>
#include "lsTools.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Local functions

/*===========================================================================*/
/* Desc.: Gibt das Shared Memory wieder frei; derzeit ungenutzt.             */
/* In   : p2LogOneSec: Pointer auf tLogOneSection                            */
/* Out  : 0: Ok; sonst Fehler                                                */
/*===========================================================================*/
int logReleaseSharedMemory(tLogOneSection* p2LogOneSec)
{
  int ret;
  int err;
  
  if (p2LogOneSec->iInitialized == 1)                      
  {
    ret = UnmapViewOfFile(p2LogOneSec->p2ShmBuf);          
    if (ret == 0)                                          
    {
      err = GetLastError();
      return err;                                          
    }
    p2LogOneSec->p2ShmBuf = NULL;                          
                                                           
    ret = CloseHandle(p2LogOneSec->hMemMapFile);           
    if (ret == 0)                                          
    {
      err = GetLastError();                                
      return err;
    }
    p2LogOneSec->hMemMapFile = 0;                          
    p2LogOneSec->iInitialized = 0;
  }
  return 0;
}
//==============================================================================
// Global variables
tLogSrvIniData logSrvIniData_;                                        //Speicher für Ini-Daten (können aus File oder aus Registry gelesen werden)
tLogOneSection logAllSection_[MAX_LOG_SECTIONS];                      //Speicher für alle Daten für Sender und Server
tThreadInfo threadInfo_[MAX_THREAD_COUNT];                            //Speicher für TheadInfo

//==============================================================================
// Global functions

/*===========================================================================*/
/* Desc.: Vorinitialisierung der Log-Daten                                   */
/* In   : iLs: Log-SektionNummer (0, 1, 2); enLogType: LogTyp (Sender oder   */
/*        Empfänger/Server)                                                  */
/* Out  : int: 0: Ok; sonst Fehler                                           */
/*===========================================================================*/
int logPreInit(int iLs, enLogType Type)                                         /**/
{
  if ((iLs < 0) || (iLs >= MAX_LOG_SECTIONS))
    return -1;                                             

  logAllSection_[iLs].iInitialized = 0;
  logAllSection_[iLs].iLock        = 0;
  
  memset (&threadInfo_, 0, sizeof(tThreadInfo)*MAX_THREAD_COUNT);
  
  switch (Type)
  {
    case enSENDER:                                                
      logAllSection_[iLs].LogLvl = logSrvIniData_.iLogServerLevel[iLs];//enInfo: Es sollte mindestens "informiert" werden              
      break;
    case enRECEIVER:                                              
      logAllSection_[iLs].pcLogLocalBuf = malloc(sizeof(tShareMemBuf));//Nur der logServer braucht diesen Speicher
      if (logAllSection_[iLs].pcLogLocalBuf == NULL)
        return -1;
	  logAllSection_[iLs].LogLvl = logSrvIniData_.iLogServerLevel[iLs];
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
int logInit(int iLs, enLogType Type)                                            /**/
{
  int res = 0;
  
  if ((iLs < 0) || (iLs >= MAX_LOG_SECTIONS))
    return -1;                                             

  if (logAllSection_[iLs].iInitialized == 0)
  {
    strcpy(logAllSection_[iLs].sLogShmLockName, logSrvIniData_.sLogShmLockName[iLs]);  
    strcpy(logAllSection_[iLs].sMapName, logSrvIniData_.sMapName[iLs]); 
    logAllSection_[iLs].iLastLine = 0;
    logAllSection_[iLs].iLock     = 0;
    switch (Type)
    {
      case enSENDER:                                                                      
        res = logOpenSharedMemory(&logAllSection_[iLs]);               //Shared Memory wird zuerst geöffnet    
        if (res != 0)                                                  
          res = logCreateSharedMemory(&logAllSection_[iLs]);           //Nur wenn das nicht geht, so wird kreiert.    
      break;
      case enRECEIVER:                                             
        res = logOpenSharedMemory(&logAllSection_[iLs]);               //Der Emfänger/Server darf nur öffnen   
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
void defineLogSrvIniData (void)                                                 /**/
{
  int iLs = 0;  
	strcpy (logSrvIniData_.sLogShmLockName[iLs], "SHAREDLOCK_MAIN");		  //1. LogSection; Name des Mutext-Objektes
	strcpy (logSrvIniData_.sMapName[iLs], "SHAREDMEM_MAIN");	            //Name des Shared Memorys
  
  strcpy (logSrvIniData_.sLogFileName[iLs], "C:\\LOGSENDER\\LOG\\");    //Name und Pfad des LogFiles der 1. Sektion wird definiert
  strcat (logSrvIniData_.sLogFileName[iLs], txt4SectionMain);
  strcat (logSrvIniData_.sLogFileName[iLs], ".csv"); 
	strcpy (logSrvIniData_.sLogFileName8[iLs], "C:\\LOGSENDER\\LOG\\");   //Name des Files der "gestrigen" Tages wird vorbereitet
  strcat (logSrvIniData_.sLogFileName8[iLs], txt4SectionMain);  
  logSrvIniData_.iLogServerLevel[iLs] = enError;                        //LogLevel ist für jede Sektion speziell setzbar
  iLs++;
  
	strcpy (logSrvIniData_.sLogShmLockName[iLs], "SHAREDLOCK_IR");		    //2. LogSection
	strcpy (logSrvIniData_.sMapName[iLs], "SHAREDMEM_IR");
  
  strcpy (logSrvIniData_.sLogFileName[iLs], "C:\\LOGSENDER\\LOG\\");
  strcat (logSrvIniData_.sLogFileName[iLs], txt4SectionIRComm);
  strcat (logSrvIniData_.sLogFileName[iLs], ".csv");  
	strcpy (logSrvIniData_.sLogFileName8[iLs], "C:\\LOGSENDER\\LOG\\");  
  strcat (logSrvIniData_.sLogFileName8[iLs], txt4SectionIRComm); 
  logSrvIniData_.iLogServerLevel[iLs] = enInfo;
	iLs++;
  
	strcpy (logSrvIniData_.sLogShmLockName[iLs], "SHAREDLOCK_SR");        //3. LogSection; MAX_LOG_SECTIONS aktuell: 3
	strcpy (logSrvIniData_.sMapName[iLs], "SHAREDMEM_SR");				        
  
  strcpy (logSrvIniData_.sLogFileName[iLs], "C:\\LOGSENDER\\LOG\\");
  strcat (logSrvIniData_.sLogFileName[iLs], txt4SectionSRComm);
  strcat (logSrvIniData_.sLogFileName[iLs], ".csv");  
	strcpy (logSrvIniData_.sLogFileName8[iLs], "C:\\LOGSENDER\\LOG\\");  
  strcat (logSrvIniData_.sLogFileName8[iLs], txt4SectionSRComm);   
  logSrvIniData_.iLogServerLevel[iLs] = enInfo;
	iLs++;  
}

/*===========================================================================*/
/* Desc.: LogFileName wird für entspr. Sektionm der Applikation übergeben    */
/* In   : iLs: Log-SektionNummer (0, 1, 2); sLogFileName: FileName für App   */
/* Out  : sLogFileName: FileName für App                                     */
/*===========================================================================*/
void getLogFileName (char *sLogFileName, int iLs)
{
  strcpy (sLogFileName , logSrvIniData_.sLogFileName[iLs]);
}
/*===========================================================================*/
/* Desc.: LogFileName8 wird für entspr. Sektion der Applikation übergeben    */
/*        Bem.: LogFileName8 hat zunächst keine Extension                    */
/* In   : iLs: Log-SektionNummer (0, 1, 2); sLogFileName: FileName für App   */
/* Out  : sLogFileName: FileName für App                                     */
/*===========================================================================*/
void getLogFileName8 (char *sLogFileName, int iLs)
{
  strcpy (sLogFileName , logSrvIniData_.sLogFileName8[iLs]);
}

/*===========================================================================*/
/* Desc.: Handelt ThreadID und ThreadName (ID und Name werden nach           */
/*        threadInfo_ gespeichert)                                           */
/*        Bem.: Bei Möglichkeiten einer gemeinsamen Nutzung von threadInfo_, */
/*              müsste der Speicher semaphoren-geschützt werden              */
/* In   : iID: ThreadID; sThreadName: Name des Threads                       */
/* Out  : -                                                                  */
/*===========================================================================*/
void saveThreadInfo (int iID, char* sThreadName)
{
  int iIdx = 0;
  while (iIdx < MAX_THREAD_COUNT)
  {
    if ((threadInfo_[iIdx].iThreadID == 0)&&(threadInfo_[iIdx].sTheadName[0]==0))
    {
      threadInfo_[iIdx].iThreadID = iID;
      strcpy (threadInfo_[iIdx].sTheadName, sThreadName);
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
void getThreadName (int iID, char *sThreadName)
{
  int iIdx = 0;
  while (iIdx < MAX_THREAD_COUNT)
  {
    if (threadInfo_[iIdx].iThreadID == iID)
    {
      strcpy (sThreadName, threadInfo_[iIdx].sTheadName);
      break;
    }
    iIdx++;
  }
  if (iIdx==MAX_THREAD_COUNT)
  {
    strcpy (sThreadName, "Name not in list!");    
  }
}

/*===========================================================================*/
/* Desc.: Erzeugt einen Shared Memory                                        */
/* In   : p2LogOneSec: Pointer auf tLogOneSection                            */
/* Out  : 0: Ok; sonst Fehler                                                */
/*===========================================================================*/
int logCreateSharedMemory(tLogOneSection* p2LogOneSec)                          /**/
{                                                                                       
  void *memPtr = NULL;                                                  //Speicher für Shared momory
  unsigned long long int iShmSize;
  int ret;
  int err;
  
  if (p2LogOneSec->iInitialized == 0)                                   //0: Abschnitt wurde noch nicht initialisiert
  {
    iShmSize = sizeof(tShareMemBuf);
    
    if (p2LogOneSec->iLock == 0)                                        //0: Mutex wurde noch nicht definiert
    {                                                                   //Mutex wird definiert; mit sLogShmLockName; iLock wird returned
      ret = CmtNewLock(p2LogOneSec->sLogShmLockName, 0, &(p2LogOneSec->iLock)); 
      if (ret != 0)                                             
        return ret;                                                     //falls ret!=0, so muss abgebrochen werden                                                      
    }
    ret = CmtGetLock(p2LogOneSec->iLock);                               //Jetzt wird der Bereich gelockt     
    if (ret != 0)                                                       //Der Lock sichert, dass nur ein Mal CreateFileMapping aktiviert wird
      return ret;                                              
           
    p2LogOneSec->hMemMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, (DWORD) iShmSize, p2LogOneSec->sMapName);
    if (p2LogOneSec->hMemMapFile == NULL)                               //falls p2LogOneSec->hMemMapFile!=NULL, so kann das Handle MapViewOfFile
    {                                                                   //übergeben werden                       
      err = GetLastError();                                
      CmtReleaseLock(p2LogOneSec->iLock);                     
      return err;
    }
     
    memPtr = (LPSTR)MapViewOfFile(p2LogOneSec->hMemMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    if (memPtr == NULL)                                                 //lass memPtr!=NULL, so der Shared RAM bekannt
    {
      err = GetLastError();
      CloseHandle (p2LogOneSec->hMemMapFile);
      CmtReleaseLock(p2LogOneSec->iLock);                     
      return err;                                          
    }

    p2LogOneSec->p2ShmBuf = memPtr;                                     //p2ShmBuf ist somit für logRead als auch logWrite für eine Sektion definiert
    memset(memPtr, 0, sizeof(tShareMemBuf));                
    CmtReleaseLock(p2LogOneSec->iLock);                                 //Jetzt wird der Bereich wieder frei gegeben
    p2LogOneSec->iInitialized = 1;
  }
  return 0;
}

/*===========================================================================*/
/* Desc.: Öffnet Shared Memory; siehe Kommentare zu logCreateSharedMemory    */
/* In   : p2LogOneSec: Pointer auf tLogOneSection                            */
/* Out  : 0: Ok; sonst Fehler                                                */
/*===========================================================================*/
int logOpenSharedMemory(tLogOneSection* p2LogOneSec)  
{
  void *memPtr = NULL;
  int ret;
  int err;
  
  if (p2LogOneSec->iInitialized == 0)                         
  {
    if (p2LogOneSec->iLock == 0)                              
    {
      ret = CmtNewLock(p2LogOneSec->sLogShmLockName, 0, &(p2LogOneSec->iLock)); 
      if (ret != 0)                                                       
        return ret;
    }
    ret = CmtGetLock(p2LogOneSec->iLock);                         
    if (ret != 0)
      return ret;
                                                           
    p2LogOneSec->hMemMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, p2LogOneSec->sMapName); 
    if (p2LogOneSec->hMemMapFile == NULL)                     
    {                                                            
      err = GetLastError();                                 
      CmtReleaseLock(p2LogOneSec->iLock);                     
      return err;
    }
     
    memPtr = (LPSTR)MapViewOfFile(p2LogOneSec->hMemMapFile, FILE_MAP_ALL_ACCESS, 0, 0, 0);
    if (memPtr == NULL)                                    
    {
      err = GetLastError();
      CloseHandle (p2LogOneSec->hMemMapFile);
      CmtReleaseLock(p2LogOneSec->iLock);                    
      return err;                                          
    }
    p2LogOneSec->p2ShmBuf = memPtr;                           
    p2LogOneSec->iSenderRuns = 1;
    CmtReleaseLock(p2LogOneSec->iLock);                       
    p2LogOneSec->iInitialized = 1;
  }
  return 0;
}

/*===========================================================================*/
/* Desc.: Überprüft, ob das Shared Memory zur Verfügung steht                */
/* In   : -                                                                  */
/* Out  : MAX_LOG_SECTIONS: Ok; sonst Fehler                                 */
/*===========================================================================*/
int checkSenderStarted (void)
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
void logRead(int iLs, int *iLineCount, char **p2p2Lines)
{
  int lines   = 0;
  int i	      = 0;
  *iLineCount = 0;                                        

  if ((iLs < 0) || (iLs >= MAX_LOG_SECTIONS))
   	return ;   
	
  if (logAllSection_[iLs].iInitialized != 1)          
   	return;                                         

  CmtGetLock(logAllSection_[iLs].iLock);                                //Lock Bereich, damit nur eine Applikation zugreifen kann
  if (logAllSection_[iLs].p2ShmBuf->iAktLine != logAllSection_[iLs].iLastLine)  
  {                                                                     //Nur wenn iAktLine geändert wurde (bei logWrite) erfolgt eine Lesen 
   	if (logAllSection_[iLs].p2ShmBuf->iAktLine > logAllSection_[iLs].iLastLine) 
   	{                                                                   //Normalfall: iAktLine>iLastLine
     	lines = logAllSection_[iLs].p2ShmBuf->iAktLine - logAllSection_[iLs].iLastLine; 
     	memcpy(logAllSection_[iLs].pcLogLocalBuf,                         //Kopiere Zeilen aus dem Shared Memory in den Lokalen Buffer pcLogLocalBuf 
             &(logAllSection_[iLs].p2ShmBuf->asLines[logAllSection_[iLs].iLastLine + 1][0]), 
             lines * LOG_MESSAGE_SIZE);
      if (logAllSection_[iLs].p2ShmBuf->iAktLine>=lines)                //iAktLine wird zurückgesetzt, da alles gelesen wurde
        logAllSection_[iLs].p2ShmBuf->iAktLine = logAllSection_[iLs].p2ShmBuf->iAktLine - lines;
   	}                                                      
   	logAllSection_[iLs].iLastLine = logAllSection_[iLs].p2ShmBuf->iAktLine;  
  }	
	
  if (lines > 0)          
  {
   	for (i=0; i<lines ; i++)                               
   	{                                                                   //pcLogLocalBuf wird der App (p2p2Lines) übergeben
     	p2p2Lines[*iLineCount]= &(logAllSection_[iLs].pcLogLocalBuf[i * LOG_MESSAGE_SIZE]);
     	(*iLineCount)++;                                   
   	}   
  }	
  CmtReleaseLock(logAllSection_[iLs].iLock);	                          //Jetzt kann der Lock-Bereich wieder frei gegeben werden  
}

/*===========================================================================*/
/* Desc.: Schreibt auf das Shared memory                                     */
/* In   : logLevel: Log-Level; iLs: Log-SektionNummer (0, 1, 2);             */
/*        sFunction: Name der aufrufenden Funktion; sFormat: Rest            */
/* Out  : 0: Ok; sonst Fehler                                                */
/*===========================================================================*/
int logWrite(enLogLevelType logLevel, int iLs, const char *sFunction, char *sFormat, ...)
{
  va_list args;	
  char sMsg[1000]={0};
  char sMessage[LOG_MESSAGE_SIZE]={0};
  char sTransfer[LOG_MESSAGE_SIZE]={0};	
  char sThreadName[SIZE] = {0};
	
 	int iMaxMsgLen = LOG_MESSAGE_SIZE-1;  	
  char sLogLevel[20]={0};
  char sFuncName[50]={0};
  char sLogSect[50] ={0};
	
  SYSTEMTIME sysTime;	
  int iBytesToTransfer = 0;
  int iBytesTransfered = 0;
  
	if ( (iLs<0)|| (iLs>=MAX_LOG_SECTIONS))
		return -1;
	if (logAllSection_[iLs].LogLvl == enNoLog)
		return 0;
  if (logLevel == enNoLog)
    return 0;
	if (logAllSection_[iLs].iInitialized != 1)
		return -1;
	if (logAllSection_[iLs].LogLvl < logLevel )
		return 0;
    
  CmtGetLock(logAllSection_[iLs].iLock);                                //Lock Bereich, damit nur eine Applikation zugreifen kann

  va_start(args, sFormat);                                              //logWrite ist printf-kompatibel
  vsprintf(sMsg, sFormat, args);
  va_end(args);
  
	switch (logLevel)                                                     //Definition der LogLevel-Texte                                      
  {
    case enNoLog  :
      strcpy(sLogLevel, txt4NoLog); 
      break;      
    case enInfo   : 
      strcpy(sLogLevel, txt4Info); 
      break;
    case enError  : 
      strcpy(sLogLevel, txt4Error); 
      break;           
    default         :  
      strcpy(sLogLevel,"LLLLL");
      break;
  }	
  switch (iLs)                                                          //Definition der Sektionen
  {
    case 0  :
      strcpy(sLogSect, txt4SectionMain); 
      break;      
    case 1   : 
      strcpy(sLogSect, txt4SectionIRComm); 
      break;
    case 2  : 
      strcpy(sLogSect, txt4SectionSRComm); 
      break;           
    default         :  
      strcpy(sLogSect,"SSSSS");
      break;
  }	  
	 
	strncpy(sFuncName, sFunction, 25); 
	GetLocalTime(&sysTime);
	
  iBytesToTransfer = strlen(sMsg);                          
  iBytesTransfered = 0;
    
  int iDay   = sysTime.wDay;
  int iMonth = sysTime.wMonth;
  int iYear  = sysTime.wYear;	
  
	int iID  = GetCurrentThreadId();  
  getThreadName (iID, sThreadName);
	
  while (iBytesToTransfer > 0)                
  {
	  strncpy(sTransfer, &sMsg[iBytesTransfered], iMaxMsgLen);            //copy der Message in den lokalen Buffer
	  sTransfer[iMaxMsgLen] = 0;                                          
	                    //dd.md.yyyy  ;hh:mm:ss      ; ms ;ll;ls;TN;FN;Msg
	  sprintf(sMessage,"%02d.%02d.%04d;%02d:%02d:%02d;%03d;%s;%s;%s;%s;%s", iDay, iMonth, iYear, sysTime.wHour, sysTime.wMinute, sysTime.wSecond, sysTime.wMilliseconds,       
	                    sLogLevel, sLogSect, sThreadName, sFuncName,   	                     
	                    sTransfer);                                       //Generierung der zu schreibenden Message: dd.mm.yyyy;hh:mm:ss;ms;LogLevel;LogSektion;threadName;functName;Message
	    
	  logAllSection_[iLs].p2ShmBuf->iAktLine++;                           //iAktLine wird erhöht
	    
	  int iLnIdx = logAllSection_[iLs].p2ShmBuf->iAktLine;
	    
	  if (strlen(sMessage) > LOG_MESSAGE_SIZE)                            //Message auf Size prüfen
	    sMessage[LOG_MESSAGE_SIZE-1] = 0;
	    
	  strcpy(logAllSection_[iLs].p2ShmBuf->asLines[iLnIdx], sMessage);    //Schreibe die Message in den Shared memory 
                                     
	  iBytesTransfered += strlen(sTransfer);                  
	  iBytesToTransfer -= strlen(sTransfer);
  }	
  CmtReleaseLock(logAllSection_[iLs].iLock);         
	return 0;
}

