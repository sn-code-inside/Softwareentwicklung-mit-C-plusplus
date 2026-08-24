//==============================================================================
//
// Title:		logServer
// Purpose:		A short description of the command-line tool.
//
// Created on:	06.03.2023 at 17:19:17 by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <userint.h>
#include <windows.h>
#include <ansi_c.h>
#include "asynctmr.h"
#include "lsTools.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

int iCurrDay_ = -1;
//==============================================================================
// Static functions

int CVICALLBACK timerToRead (int reserved, int timerId, int event, void *callbackData, int eventData1, int eventData2)
{
  FILE *fp = NULL;
  char *logLines[LOG_MAX_LINES] = {0};
  int iLineCount = 0;
 
  int iSMonth = 0;
  int iSDay   = 0;
  int iSYear  = 0;
  
  switch (event)
  {                                                        
    case EVENT_TIMER_TICK:                                 

      GetSystemDate(&iSMonth, &iSDay, &iSYear);            
      if (iCurrDay_ == -1)                                
        iCurrDay_ = iSDay;                                 

      if (iSDay != iCurrDay_)                              
      {
        for (int iLs=0; iLs<MAX_LOG_SECTIONS; iLs++)    
        {
  		    char sOldLogFileName[MAX_PATHNAME_LEN] = {0};
            char sLogFileName8[MAX_PATHNAME_LEN] = {0};  
            char sLogFileName[MAX_PATHNAME_LEN] = {0};           
            getLogFileName8 (sLogFileName8, iLs);
  		    sprintf(sOldLogFileName, "%s_%02d.csv", sLogFileName8, iCurrDay_);
            DeleteFile (sOldLogFileName);
            getLogFileName (sLogFileName, iLs);          
            RenameFile (sLogFileName, sOldLogFileName); 
        }
        iCurrDay_ = iSDay;                                   
      }

      for (int iLs=0; iLs<MAX_LOG_SECTIONS; iLs++)            
      {
          logRead(iLs, &iLineCount, logLines);                
	      if(iLineCount>0)                                   
          {
            char sLogFileName[MAX_PATHNAME_LEN] = {0};           
            getLogFileName (sLogFileName, iLs);
            if (getWriteLogFile(iLs) == 1)
                fp = fopen (sLogFileName, "a");    

          for(int j=0; j<iLineCount; j++)                      
          {          
            if ( (fp != NULL) && (getWriteLogFile(iLs) == 1) )
              fprintf(fp, "%s\n", logLines[j]);		      
            printf ("%s\n", logLines[j]);
          }
  
          if ( (fp != NULL) && (getWriteLogFile(iLs) == 1) )
          {
            fclose(fp);
            fp = NULL;
          }
        }
      }
  }                                       
  return 0;
}

//==============================================================================
// Global variables

//==============================================================================
// Global functions


int main (int argc, char *argv[])
{
  defineLogSrvIniData ();                  //iniData werden gesetzt (hier hard coded; in der Praxis sollten sie aus der Registry gelesen werden)

  printf ("Kein Sender gestartet. Warte auf Sender-Start....\n");
  while (1)
  {
    int iCheckSenderStart = 0;
  	for (int iLs=0; iLs<MAX_LOG_SECTIONS; iLs++)  	
  	{
  		logPreInit (iLs, enRECEIVER);
		  logInit (iLs, enRECEIVER);       
  	}
    iCheckSenderStart = checkSenderStarted();
    if (MAX_LOG_SECTIONS == iCheckSenderStart)
      break;
    else
      Sleep(1000);
    printf (".");    
  }
  printf ("\nSender gestarted\n\n");   
    
	Sleep (1000);
	NewAsyncTimer(1.0, -1, 1, timerToRead, NULL);	
	
	int iEnd = 1;
	while (1)
	{
		iEnd++;
		if (iEnd==0)
			break;
		Sleep (1000);	
	}
	return 0;
}

