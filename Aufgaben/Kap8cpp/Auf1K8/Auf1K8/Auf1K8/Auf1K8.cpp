// Auf1K8.cpp
#include "stdafx.h"
#include "Windows.h"
#include "P002K8_fileUtil.h"
#include <iostream>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
int main(int argc, char* argv[])
{
    //=========================================
    LPCTSTR str = L"Auf1K8";
    printConsole(str);
    //=========================================
    ULARGE_INTEGER uliFree;
    ULARGE_INTEGER uliTotal; ULARGE_INTEGER uliTotalFree;
    unsigned long long  ullFree;
    unsigned long long ullTotal; unsigned long long ullTotalFree;
    BOOL bDone  = GetDiskFreeSpaceEx (L"E:\\", &uliFree, &uliTotal, &uliTotalFree);
    if (bDone == FALSE) {
        MessageBox(NULL, L"FileCopy fehlgeschlagen\nLW E:\\ vorhanden?.", L"WARNUNG", MB_ICONWARNING);
        return 1;
    }

    ullFree     = uliFree.HighPart*0x100000000 + uliFree.LowPart;
    ullTotal    = uliTotal.HighPart*0x100000000 + uliTotal.LowPart;
    ullTotalFree= uliTotalFree.HighPart*0x100000000 + uliTotalFree.LowPart;

    cout << "Speicherbelegung auf Ziel vor CopyFile:\n";
    cout << "Frei           : " << ullFree << endl;
    cout << "Total          : " << ullTotal << endl << endl;

    cFUtils file("Auf1K8.cpp");                 //Es wäre natürlich geschickter Source und 
                                                //Target als Parameter zu handeln                                            
    int iFLen = file.getFileLen ();
    cout << "Filelaenge     : " << iFLen << endl << endl;
    if (iFLen > ullFree) {
        MessageBox (NULL, L"Zu wenig Speicher auf Ziel.\nFileCopy nicht möglich.", L"INFO", MB_ICONINFORMATION);
    }
    else
    {                           //Source        Target
        bDone = CopyFile (L"Auf1K8.cpp", L"E:\\Auf1K8.cpp", FALSE);    //Hier findet das Kopieren statt.
        if (bDone == FALSE)
            MessageBox (NULL, L"FileCopy fehlgeschlagen.", L"WARNUNG", MB_ICONWARNING);
    }
    bDone = GetDiskFreeSpaceEx (L"E:\\", &uliFree, &uliTotal, &uliTotalFree);
    ullFree     = uliFree.HighPart*0x100000000 + uliFree.LowPart;
    ullTotal    = uliTotal.HighPart*0x100000000 + uliTotal.LowPart;
    ullTotalFree= uliTotalFree.HighPart*0x100000000 + uliTotalFree.LowPart;

    cout << "Speicherbelegung auf Ziel nach CopyFile:\n";
    cout << "Frei           : " << ullFree << endl;
    cout << "Total          : " << ullTotal << endl;
    return 0;
}

