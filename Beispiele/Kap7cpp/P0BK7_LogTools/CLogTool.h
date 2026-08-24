#pragma once
//==============================================================================
// Include 
#include <Windows.h>
#include "CMutex.h"

//==============================================================================
// Constants

#define MAX_THREAD_COUNT       30
#define SIZE                   256                      //Max. Size der hier verwendeten Namen
#define MAX_PATHNAME_LEN       260

#define LOG_MESSAGE_SIZE       256                      //Laenge einer Textzeile 
#define LOG_MAX_LINES          16                      //Anzahl Textzeilen  

#define txt4NoLog             "NOLOG"                   //Log-Typen als Text
#define txt4Info              "INFO"
#define txt4Error             "ERROR"

#define MAX_LOG_SECTIONS	   3
#define txt4SectionMain       "Main"                    //Namen der drei Log-Bereiche
#define txt4SectionIRComm     "IRComm"  
#define txt4SectionSRComm     "SRComm"   

//==============================================================================
// Types
typedef enum                                              //Typen der Programme (Sender, Empfänger/Server)
{
    enSENDER,
    enRECEIVER
} enLogType;

typedef enum                                              //Level der Logs
{
    enNoLog,
    enInfo,
    enError
} enLogLevelType;

typedef enum                                              //Current Comm-Types (3 Types: Main, Interface-Rechner; SPS-Rechner)
{
    enMain,
    enIRComm,
    enSRComm
} enCommType;

typedef struct                                            //structure für ThreadName-Handling
{
    char sTheadName[SIZE];
    int iThreadID;
} tThreadInfo;

typedef struct                                            //structure für iniData 
{
    char sMapName[MAX_LOG_SECTIONS][SIZE];                //MapName für Shared Memory
    char sLogFileName[MAX_LOG_SECTIONS][MAX_PATHNAME_LEN];//FileNames
    char sLogFileName8[MAX_LOG_SECTIONS][MAX_PATHNAME_LEN];
}tLogSrvIniData;

typedef struct
{
    int iAktLine;                                     //Die aktuelle Zeile müssen Sender und Empfänger sehen können
    char asLines[LOG_MAX_LINES][LOG_MESSAGE_SIZE];    //Speicher der LogDaten (auch für beide sichtbar)                                          
}tShareMemBuf;

typedef struct                                        //structure für eine Sektion
{
    char           sMapName[SIZE];                    //Name für Memory der Sektion (prozessübergreifend)
    HANDLE         hMemMapFile;                       //Handle für Create- bzw. OpenFileMapping
    int            iInitialized;                      //Prüft, ob die Sektion initialisiert ist
    tShareMemBuf*  p2ShmBuf;                          //Shared Memory (prozessübergreifend)
    int            iLastLine;                         //merkt sich der Empfänger und ändert sie auch 
    char* pcLogLocalBuf;                              //lokaler Speicher der LOG-Zeile durch den Empfänger
    int            iSenderRuns;                       //Wird bei checkSenderStarted (prüft ob der logServer laufen kann) 
} tLogOneSection;                                     //logServer sollte erst dann starten, wenn Sender gestartet ist

class CLogTool
{
    public:
        CLogTool(void);
        ~CLogTool(void);

        //Desc.: Vorinitialisierung der Log-Daten
        int logPreInit(int iLs, enLogType Type);
        //Desc.: Auslesen der Ini-Daten und Sichern dieser Daten in den LogDaten
        //       Aktivierung des Shared Memory 
        int logInit(int iLs, enLogType Type);
        //Desc.: Definiert die INI-Daten (Konfiguration) von logSender und logServer. 
        void defineLogSrvIniData(void);
        void getLogFileName(char* sLogFileName, int iLs);
        //Desc.: LogFileName8 wird für entspr. Sektion der Applikation übergeben
        void getLogFileName8(char* sLogFileName, int iLs);
        //Desc.: Handelt ThreadID und ThreadName (ID und Name werden nach threadInfo_ gespeichert) 
        void saveThreadInfo(int iID, char* sTHreadName);
        //Desc.: Gibt für eine ID den Namen des Threads zurück                
        void getThreadName(int iID, char* sThreadName);

        //Desc.: Erzeugt einen Shared Memory 
        int logCreateSharedMemory(tLogOneSection* p2LogOneSec);
        //Desc.: Öffnet Shared Memory; siehe Kommentare zu logCreateSharedMemory
        int logOpenSharedMemory(tLogOneSection* p2LogOneSec);
        //Desc.: Überprüft, ob das Shared Memory zur Verfügung steht
        int checkSenderStarted(void);

        //Desc.: Liest vom Shared Memory
        int logRead(int iLs, int* iLineCount, char** p2p2Lines);
        //Desc.: Schreibt auf das Shared memory                                    
        int logWrite(enLogLevelType logLevel, int iLs, const char* sFunction, char* sFormat, ...);

        //Wird 1x festgelegt (z.B.: im Konstruktorvon CLogTool)
        void setGlobalLogLevel(enLogLevelType enLLevel);
        enLogLevelType getGlobalLogLevel(void);
private:
    tLogOneSection logAllSection_[MAX_LOG_SECTIONS];                      //Speicher für alle Daten für Sender und Server
    tLogSrvIniData logSrvIniData_;                                        //Speicher für Ini-Daten (können aus File oder aus Registry gelesen werden)
    tThreadInfo threadInfo_[MAX_THREAD_COUNT];                            //Speicher für TheadInfo
    CMutex* mutex_;                                                       //mutex-Objekt
    enLogLevelType iGlobalLogLevel_;                                      //bei enNoLog: Kein LOG; Bei enInfo: Nur Info wird geloggt; bei enError: Info und Error werden gelogt 
};

