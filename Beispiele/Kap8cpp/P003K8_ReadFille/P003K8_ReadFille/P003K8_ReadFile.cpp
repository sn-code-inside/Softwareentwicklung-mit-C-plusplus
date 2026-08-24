// P003K8_ReadFille.cpp
#include "P002K8_fileUtil.h"
#include <iostream>
using namespace std;
#include <conio.h>
//=============================================
#include <Windows.h>                                
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
//=============================================  
/* =========================================================================== */
/* Desc.: Gibt den Inhalt von ucBuffer auf der Konsole aus.                    */
/*        Die Ausgabe erfolgt in Form eines Hex−Ascii − Listing.               */
/* In   : char* ucBuffer: LeseBuffer des Files.                                */
/*        int iFileLen : Filelänge.                                            */
/*        int iNrLines : Anzahl der Zeilen, die auf der Konsole gezeigt werden */
/*                       sollen.                                               */
/* Out  : − */
/* =========================================================================== */
void printFile2Console(char* ucBuffer, int iFileLen, int iNrLines)          // A1
{
    HANDLE hConsole = GetStdHandle (STD_OUTPUT_HANDLE);
    int iIdx, iIdx4Ascii = 0, iLn = 0;                                      // A2
    unsigned char ucAsciiBuff[17] = { 0 };
    unsigned char ucRead = 0;
    for (iIdx = 0; iIdx < iFileLen; iIdx++)                                 // A3
    {
        SetConsoleTextAttribute(hConsole, 2);
        if (iIdx4Ascii == 0) {
            cout.width(8); cout.fill('0');
            cout << hex << iIdx << ' ';
        }
        SetConsoleTextAttribute(hConsole, 12);
        cout.width(1); cout.fill(' ');
        cout << ' ';
        cout.width(2); cout.fill('0');
        ucRead = (unsigned char)ucBuffer[iIdx];
        cout << hex << (int)ucRead;
        if (ucBuffer[iIdx] >= 0x20)                                         // A4
            ucAsciiBuff[iIdx4Ascii++] = ucRead;
        else
            ucAsciiBuff[iIdx4Ascii++] = '.';                                // A5
        if (iIdx4Ascii == 16) {                                             // A6
            SetConsoleTextAttribute(hConsole, 11);
            cout << "  " << ucAsciiBuff << endl;                            // A7
            iIdx4Ascii = 0; iLn++;
            if (iLn % iNrLines == 0) {                                      // A8
                SetConsoleTextAttribute(hConsole, 7);
                cout << " Mit ENTER erfolgt die Ausgabe der naechsten Bytes\n";
                char chr = _getch();
                if (chr == 'a') {
                    SetConsoleTextAttribute(hConsole, 7);
                    return;
                }
            }
        }
    }
    SetConsoleTextAttribute(hConsole, 7);
}

int main (void)
{
    int iRet = 0;
    //=========================================
    CONST WCHAR* str = L"P003K8_ReadFile";
    printConsole(str);
    //========================================= 

    cFUtils file("x64\\Debug\\P003K8_ReadFile.EXE");            // 1
    int iFLen = file.readFile();                                // 2
    if(iFLen > 0) {
        char* strFBuff = file.getFileBuff();                    // 3
        printFile2Console(strFBuff, iFLen, 23);                 // 4
    }
    else {
        cout << "File P003K8_ReadFile.EXE nicht vorhanden.\n";  // 5
        iRet = 1;                                               // 6
    }
    return iRet;                                                // 7
}

