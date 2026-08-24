// Auf2KE.cpp 
#include "stdafx.h"
#include <windows.h> 
#include <stdio.h>
#include "cConsole.h"
#include <iostream>
#include <ctime>
#include <limits.h>
using namespace std;

const int ciHintPosX     = 2; const int ciHintPosY     = 2;
const int ciFramePosX    = 2; const int ciFramePosY    = 4;
const int ciCursPosX     = ciFramePosX+1; const int ciCursPosY     = ciFramePosY+1;
const int iMaxCharInBuff = 74;

struct tEditLine {
    COORD curPos;
    int iIdxPos;
    char strEditLine[iMaxCharInBuff+1];     //+1 wegen \0
    char cOrder;    //l für left, r für right, d für delete c für insert char
    char cChar;     //cChar: Char, das zu editieren ist
};

int lineEditor (tEditLine * editLn, cConsole* cons) {
    int iErr = 0;
    cons->enterSection();
    if (editLn->cOrder == 'c')     {
        if (editLn->iIdxPos<iMaxCharInBuff)    {
            editLn->strEditLine[editLn->iIdxPos] = editLn->cChar;
            COORD cStartPos; cStartPos.X = ciCursPosX; cStartPos.Y = ciCursPosY;
            editLn->iIdxPos++;
            if (strlen (editLn->strEditLine) == editLn->iIdxPos)
                editLn->strEditLine[editLn->iIdxPos] = 0;
            cons->delLine (cStartPos, iMaxCharInBuff);
            cons->printfStrWithColorAtPos (cStartPos, editLn->strEditLine, ciYellow);
            editLn->curPos.X++;
            cons->GotoPos (editLn->curPos);
        }
        else
            iErr = 1;
    }
    else if (editLn->cOrder == 'l')  {
        if (editLn->iIdxPos>0)  {
            editLn->iIdxPos--; editLn->curPos.X--;
            cons->GotoPos (editLn->curPos);
        }
        else
            iErr = 2;
    }
    else if (editLn->cOrder == 'r')  {
        if (editLn->iIdxPos<(int)strlen(editLn->strEditLine)) {
            editLn->iIdxPos++; editLn->curPos.X++;
            cons->GotoPos (editLn->curPos);
        }
        else
            iErr = 3;
    }

    cons->leaveSection();
    return iErr;
}

/*===========================================================================*/
/* Desc.: Zeichnet den Rahmen des Zeilen-Editors                             */
/* In   : -                                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void drawEditFrame (cConsole* cons)                 
/*---------------------------------------------------------------------------*/
{
    COORD cFramePos;
    cFramePos.X = ciFramePosX;
    cFramePos.Y = ciFramePosY;
    cons->enterSection ();
    cons->printfStrWithColorAtPos (cFramePos, "+", ciLGray);
    for (int i=0; i<74; i++)
    {
        cFramePos.X++;
        cons->printfStrWithColorAtPos (cFramePos, "-", ciLGray);
    }
    cFramePos.X++;
    cons->printfStrWithColorAtPos (cFramePos, "+", ciLGray);
    cFramePos.X = ciFramePosX;
    cFramePos.Y++;

    cons->printfStrWithColorAtPos (cFramePos, "|", ciLGray);
    for (int i=0; i<74; i++)
    {
        cFramePos.X++;
        cons->printfStrWithColorAtPos (cFramePos, " ", ciLGray);
    }
    cFramePos.X++;
    cons->printfStrWithColorAtPos (cFramePos, "|", ciLGray);
    cFramePos.X = ciFramePosX;
    cFramePos.Y++;

    cons->printfStrWithColorAtPos (cFramePos, "+", ciLGray);
    for (int i=0; i<74; i++)
    {
        cFramePos.X++;
        cons->printfStrWithColorAtPos (cFramePos, "-", ciLGray);
    }
    cFramePos.X++;
    cons->printfStrWithColorAtPos (cFramePos, "+", ciLGray);
    cFramePos.X = ciFramePosX;

    cons->leaveSection();
}
/*===========================================================================*/
/* Desc.: Zeichnet den Rahmen des Zeilen-Editors                             */
/* In   : -                                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void drawHints (cConsole* cons)                 
/*---------------------------------------------------------------------------*/
{
    COORD cHintsPos;
    cHintsPos.X = ciFramePosX;
    cHintsPos.Y = ciFramePosY+3;
    cons->enterSection ();
    char strHint[256];
    strcpy_s (strHint, 256, "Navigation: Pfeil links, Pfeil rechts; Ende: ALT-E;");
    cons->printfStrWithColorAtPos (cHintsPos, strHint, ciLGray); 
    cons->leaveSection();
}
DWORD WINAPI currTimeDate ( LPVOID lpParam )                                      
{
    cConsole* cons = (cConsole*)lpParam;                                          
    COORD Pos; bool bEnd = false; 
    Pos.X = 53; Pos.Y = 9;
    char strTimeDate[128] ={0}; 
    time_t currTime;
    tm timeinfo;                                                                                                                      
    while (!bEnd)
    {
        int iLoop = 0;
        while (iLoop<100)
        {
            Sleep (1);
            iLoop++;
        }

        currTime = time (NULL);
        localtime_s (&timeinfo, &currTime);
        asctime_s (strTimeDate, 128, &timeinfo);
        cons->enterSection();
        cons->HideCursor ();
        cons->GotoPos (Pos);
        cons->printfStrWithColorAtPos(Pos, strTimeDate, ciLGray);
        cons->ShowCursor ();
        cons->leaveSection();
        MSG msg;
        msg.message = 0;       
        BOOL bReceived = PeekMessage (&msg, 0, 0, 0, PM_REMOVE );
        if (bReceived==TRUE)
        {
            int iRecv = msg.wParam;                                                                             
            if (iRecv == (int)'e')                                                  
                bEnd = true;                                                        
        }               
        //Sleep (1000);
    }
    return 0; 
} 

int main(int argc, char* argv[])
{
    cConsole myConsole;  
    //=========================================
    LPCTSTR str = L"Auf2KE";
    myConsole.printConsole(str);
    //=========================================
    drawEditFrame (&myConsole);
    drawHints (&myConsole);
    HANDLE Array_Of_Thread_Handles[1];
    myConsole.initSection();                                                        
    HANDLE hTimeDate = 0; DWORD dwTID;
    char strTimeDate[128] ={0};
    COORD cHintPos;
    cHintPos.X = ciHintPosX;
    cHintPos.Y = ciHintPosY;
    bool bEndMain = false; char cChr = 0; 
    myConsole.enterSection();
    myConsole.printfStrWithColorAtPos(cHintPos, "Zeilen-Editor:", ciWhite);
    myConsole.leaveSection();
    hTimeDate = CreateThread( NULL, 0, currTimeDate,  &myConsole, 0, &dwTID);     
    Array_Of_Thread_Handles[0] = hTimeDate;  

    COORD cCursPos;
    cCursPos.X = ciCursPosX;
    cCursPos.Y = ciCursPosY;
    bool bLeft = false;                 //Links-Taste wurde gedrückt
    bool bRight= false;                 //Rechts-Taste wurde gedrückt
    bool bAlt  = false;                 //ALT-Taste wurde gedrückt
    bool bDel  = false;                 //Taste Entf wurde gedrückt
    tEditLine editLine;
    editLine.curPos = cCursPos;
    editLine.iIdxPos= 0;
    for (int i=0; i<iMaxCharInBuff; i++)
        editLine.strEditLine[i]=0x0;
    editLine.strEditLine[iMaxCharInBuff]=0x0;
    while (!bEndMain)                                                                 
    {
        myConsole.enterSection();
        myConsole.GotoPos (editLine.curPos);
        myConsole.leaveSection();
        cChr = myConsole.getKey();                                                
        if (cChr)
        { 
            if (bLeft == true)
            {
                bLeft = false;
                continue;
            }
            if (bRight == true)
            {
                bRight = false;
                continue;
            }
            short iRet = GetAsyncKeyState (VK_MENU);
            if (iRet) bAlt = true;
            iRet = GetAsyncKeyState (VK_LEFT);
            if (iRet) bLeft = true;
            iRet = GetAsyncKeyState (VK_RIGHT);
            if (iRet) bRight = true;
            iRet = GetAsyncKeyState (VK_DELETE);
            if (iRet) bDel = true;
            if ((cChr == 'e') && (bAlt) )                                                                                       
            {
                BOOL bRet = PostThreadMessage (dwTID, WM_COMMAND, 'e', 0);
                WaitForMultipleObjects(1, &Array_Of_Thread_Handles[0], TRUE, INFINITE);
                bEndMain = true;
                myConsole.enterSection();
                myConsole.delLine (cHintPos, 33);
                myConsole.printfStrWithColorAtPos(cHintPos, "Ende des Editierens.", ciWhite);
                myConsole.leaveSection();
            }
            else if (bLeft)
            {
                editLine.cOrder = 'l'; editLine.cChar = 0;
                int iErr = lineEditor (&editLine, &myConsole);
            }
            else if (bRight)
            {
                editLine.cOrder = 'r'; editLine.cChar = 0;
                int iErr = lineEditor (&editLine, &myConsole);
            }
            else if ( (cChr >=0x20) && (cChr <=0x7f ) )
            {
                //Alle ASCII-Zeichen
                editLine.cOrder = 'c'; editLine.cChar = cChr;
                int iErr = lineEditor (&editLine, &myConsole);
            }
        }
    }
    CloseHandle(hTimeDate);
    return 0;                                                          
}

