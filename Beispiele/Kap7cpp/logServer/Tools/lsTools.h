//==============================================================================
//
// Title:		lsTools.h
// Purpose:		Methods and types for logSender and logServer
//
// Created on:	06.03.2023 at 17:21:43 by D. Duschl.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __lsTools_H__
#define __lsTools_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include 
#include <Windows.h>
#include <utility.h>
#include "cvidef.h"

//==============================================================================
// Constants

#define MAX_THREAD_COUNT       30
#define SIZE                   256                      //Max. Size der hier verwendeten Namen

#define MAX_LOG_SECTIONS	     3
		
#define LOG_MESSAGE_SIZE       256                      //Laenge einer Textzeile 
#define LOG_MAX_LINES          512                      //Anzahl Textzeilen  
 
#define txt4NoLog             "NOLOG"                   //Log-Typen als Text
#define txt4Info              "INFO"
#define txt4Error             "ERROR"
      
#define txt4SectionMain       "Main"                    //Namen der drei Log-Bereiche
#define txt4SectionIRComm     "IRComm"  
#define txt4SectionSRComm     "SRComm"       
      
//==============================================================================
// Types
typedef enum                                            //Typen der Programme (Sender, Empfänger/Server)
{
  enSENDER,
  enRECEIVER
} enLogType;

typedef enum                                            //Level der Logs
{ 
  enNoLog, 
  enInfo, 
  enError
} enLogLevelType;

typedef struct                                          //structure für ThreadName-Handling
{
  char sTheadName[SIZE];                  
  int iThreadID;                          
} tThreadInfo;

typedef struct                                          //structure für iniData 
{
  int iLogServerLevel[MAX_LOG_SECTIONS];                //LogLevel 
  int iWriteLogFiles[MAX_LOG_SECTIONS];                 //Flag, ob csv-File geschrieben werden soll  
  
  char sLogShmLockName[MAX_LOG_SECTIONS][SIZE];         //LockName für Mutex
  char sMapName[MAX_LOG_SECTIONS][SIZE];                //MapName für Shared Memory
  
  char sLogFileName[MAX_LOG_SECTIONS][MAX_PATHNAME_LEN];//FileNames
  char sLogFileName8[MAX_LOG_SECTIONS][MAX_PATHNAME_LEN];   
}tLogSrvIniData;	                                      

typedef struct
{
  int iAktLine;                                     //Die aktuelle Zeile müssen Sender und Empfänger sehen können
  char asLines[LOG_MAX_LINES][LOG_MESSAGE_SIZE];    //Speicher der LogDaten (auch für beide sichtbar)                                          
}tShareMemBuf;

typedef struct                                      //structure für eine Sektion
{                                           
  enLogLevelType LogLvl;                  
  char           sLogShmLockName[SIZE];             //Name für Mutex der Sektion (prozessübergreifend)
  char           sMapName[SIZE];                    //Name für Memory der Sektion (prozessübergreifend)
  int            iLock;                             //0: Mutext wurde noch nicht generiert
  HANDLE         hMemMapFile;                       //Handle für Create- bzw. OpenFileMapping
  int            iInitialized;                      //Prüft, ob die Sektion initialisiert ist
  tShareMemBuf   *p2ShmBuf;                         //Shared Memory (prozessübergreifend)
  int            iLastLine;                         //merkt sich der Empfänger und ändert sie auch 
  char           *pcLogLocalBuf;                    //lokaler Speicher der LOG-Zeile durch den Empfänger
  int            iSenderRuns;                       //Wird bei checkSenderStarted (prüft ob der logServer laufen kann) 
} tLogOneSection;                                   //logServer sollte erst dann starten, wenn Sender gestartet ist
//==============================================================================
// External variables

//==============================================================================
// Global functions

//Desc.: Vorinitialisierung der Log-Daten
int logPreInit(int iLs, enLogType Type);
//Desc.: Auslesen der Ini-Daten und Sichern dieser Daten in den LogDaten
//       Aktivierung des Shared Memory 
int logInit(int iLs, enLogType Type);
//Desc.: Definiert die INI-Daten (Konfiguration) von logSender und logServer. 
void defineLogSrvIniData (void);
//Desc.: LogFileName wird für entspr. Sektionm der Applikation übergeben
void getLogFileName (char *sLogFileName, int iLs);
//Desc.: LogFileName8 wird für entspr. Sektion der Applikation übergeben
void getLogFileName8 (char *sLogFileName, int iLs);
//Desc.: iWriteLogFiles wird für entspr. Sektionm der Applikation übergeben
int getWriteLogFile (int iLs);
//Desc.: iLogServerLevel wird für entspr. Sektionm der Applikation übergeben
int getLogServerLevel (int iLs);

//Desc.: Handelt ThreadID und ThreadName (ID und Name werden nach threadInfo_ gespeichert) 
void saveThreadInfo (int iID, char* sTHreadName);
//Desc.: Gibt für eine ID den Namen des Threads zurück                
void getThreadName (int iID, char *sThreadName);

//Desc.: Erzeugt einen Shared Memory 
int logCreateSharedMemory(tLogOneSection* p2LogOneSec);
//Desc.: Öffnet Shared Memory; siehe Kommentare zu logCreateSharedMemory
int logOpenSharedMemory(tLogOneSection* p2LogOneSec);
//Desc.: Überprüft, ob das Shared Memory zur Verfügung steht
int checkSenderStarted (void);

//Desc.: Liest vom Shared Memory
void logRead(int iLs, int *iLineCount, char **p2p2Lines);
//Desc.: Schreibt auf das Shared memory                                    
int logWrite(enLogLevelType logLevel, int iLs, const char *sFunction, char *sFormat, ...);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __lsTools_H__ */
