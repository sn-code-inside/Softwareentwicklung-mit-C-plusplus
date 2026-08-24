//==============================================================================
//
// Title:		LogSender
// Purpose:		A short description of the command-line tool.
//
// Created on:	11.03.2023 at 10:34:24 by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include "asynctmr.h"
#include "lsTools.h"
//#include <userint.h>


//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions



//==============================================================================
// Global variables

int iThreadIdx_ = 0;
//==============================================================================
// Global functions
unsigned long long getFreeSpace (char *strRootPathName)  
{
  DWORD dwSectorPerCluster    = 0;
  DWORD dwBytesPerSector      = 0;
  DWORD dwNumbOfFreeClusters  = 0;
  int bSucceed                = 0;
  unsigned long long ullFreeSpaceInBytes = 0;
  
  logWrite (enInfo, 0, __func__, "__Start__");

  bSucceed = GetDiskFreeSpace((LPCSTR)strRootPathName, &dwSectorPerCluster, &dwBytesPerSector, &dwNumbOfFreeClusters, NULL);
  
  if(1 == bSucceed)
  {
    ullFreeSpaceInBytes = (unsigned long long)dwNumbOfFreeClusters * (unsigned long long)dwSectorPerCluster * (unsigned long long)dwBytesPerSector;
    
    iThreadIdx_++;
    if (iThreadIdx_==7)
    {
      char *sPtr = NULL;  
      logWrite (enError, 0, __func__, "sPtr: %x; iThreadIdx__: %d", sPtr, iThreadIdx_);       
      strcpy (sPtr, "Text"); 
    }

    logWrite (enInfo, 0, __func__, "__End__");    
    return ullFreeSpaceInBytes;
  }
  else
  {
    logWrite (enInfo, 0, __func__, "__End__");     
    return 0;
  }
}

DWORD WINAPI hdObserver ( LPVOID lpParam ) 
{
  char strName[64] = {0};
  strcpy (strName, __func__);
  
  int iID  = GetCurrentThreadId();
  saveThreadInfo (iID, "hdObserver");
  
  while (1)
  {
    unsigned long long ullFreeSpace = getFreeSpace ("C:\\");
    logWrite (enInfo, 0, __func__, "freeDiskSpace: %llu Bytes", ullFreeSpace); 
                                      
    Sleep (1000); 
  }
  return 0;
}

int main (int argc, char *argv[])
{
	int iLs    	= 0;
  int iMonth 	= 1;
  int iDay    = 1;
  int iYear   = 2000;	
 	SYSTEMTIME sysTime;	
	
	defineLogSrvIniData ();
	
	for (iLs=0; iLs<MAX_LOG_SECTIONS; iLs++)  	
	{
		logPreInit (iLs, enSENDER);
		logInit (iLs, enSENDER); 
	}
	
	GetLocalTime(&sysTime);
	
  iDay   = sysTime.wDay;
  iMonth = sysTime.wMonth;
  iYear  = sysTime.wYear;
	
  int iID  = GetCurrentThreadId();
  saveThreadInfo (iID, "MainThread");
  
	Sleep (1000);
	for (iLs=0; iLs<MAX_LOG_SECTIONS; iLs++)  	
	{
		logWrite(enInfo, iLs, __func__, "=== start of logSender, section: %d ===", iLs); 		
	}

  int iThreadData = 1;
  HANDLE hdlXHPMain = CreateThread ( NULL, 0, hdObserver, &iThreadData, 0, NULL);  
  
	int iEnd = 0;
  iLs      = 0;
	while (1)
	{
		iEnd++;
		Sleep (1000);
    if (iEnd==0)
      break;
 
    if (iLs==0)
		  logWrite(enError, iLs, __func__, "Main-Info: %d Durchgaenge in MainLoop.", iEnd); 	
    else if (iLs==1)
		  logWrite(enInfo, iLs, __func__, "Main-Info: %d Durchgaenge in MainLoop.", iEnd); 
    else if (iLs==2)    
		  logWrite(enError, iLs, __func__, "Main-Info: %d Durchgaenge in MainLoop.", iEnd);     
    iLs++;
    if (iLs==MAX_LOG_SECTIONS)
      iLs = 0;
    int iFRun=0;
	  logWrite(enError, iLs, __func__, "Main-Info: %d Durchgaenge in MainLoop. FastRun: %d", iEnd, iFRun); 
    iFRun++;
	  logWrite(enError, iLs, __func__, "Main-Info: %d Durchgaenge in MainLoop. FastRun: %d", iEnd, iFRun); 
    iFRun++;
	  logWrite(enError, iLs, __func__, "Main-Info: %d Durchgaenge in MainLoop. FastRun: %d", iEnd, iFRun); 
    iFRun++;
	  logWrite(enError, iLs, __func__, "Main-Info: %d Durchgaenge in MainLoop. FastRun: %d", iEnd, iFRun); 
    iFRun++;    
	}	
  
	for (iLs=0; iLs<MAX_LOG_SECTIONS; iLs++)  	
	{
		logWrite(enInfo, iLs, __func__, "=== end of logSender, section: %d ===", iLs); 		
	}  
	return 0;
}

