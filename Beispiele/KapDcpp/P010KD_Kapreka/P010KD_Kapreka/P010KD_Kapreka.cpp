// P010KD_Kaprekar.cpp 
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "kaprekUtil.h"

using namespace std;
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
int main(void) 
{
    //=========================================
    LPCTSTR str = L"P010KD_Kaprekar";
    printConsole(str);
    //=========================================
    int iNumb = 0;
    int iIdx  = 0;
    kaprekUtil kapVar (MAX_KAP_10000);                           //Hier wird entschieden, ob wir drei- oder 
                                                                //vier-stellige Konstanten ermitteln wollen
    while (iNumb < (kapVar.getMaxKap()-1))                      //Ausschluss der Zahlen 999 bzw. 9999
    {
        if (0 == kapVar.ignore(iNumb, kapVar.getKapWidth()))    //Hier schließen wir Zahlen aus, die aus       
        {                                                       //gleichen Ziffern bestehen
            int iTempKap    = iNumb;
            bool bBreak     = false;
            int iOldKaprekar = 0;
            int iTry        = 0;
            while (bBreak == false)
            {
                kapVar.setNumb(iIdx, iNumb);
                int hKap = kapVar.kapToHigh(iTempKap);
                int lKap = kapVar.kapToLow(iTempKap);
                iTempKap = hKap - lKap;
                if (iTempKap == iOldKaprekar)
                {
                    bBreak = true;
                    kapVar.setTempKap(iIdx, iTry, iTempKap);
                    //iTempKap = kapVar.corrTempKapp(iTempKap);
                    kapVar.setHigh(iIdx, iTry, hKap);
                    kapVar.setLow(iIdx, iTry, lKap);
                    kapVar.setTry(iIdx, iTry);
                    iIdx++;
                }
                else
                {
                    iOldKaprekar = iTempKap;
                    kapVar.setTempKap(iIdx, iTry, iTempKap);
                    iTempKap = kapVar.corrTempKapp(iTempKap);
                    kapVar.setHigh(iIdx, iTry, hKap);
                    kapVar.setLow(iIdx, iTry, lKap);
                    kapVar.setTry(iIdx, iTry);
                    iTry++;
                    cout << "iTry: " << iTry << endl;
                }
            }
        }
        iNumb++;
        cout << "iNumb: " << iNumb << endl;
    }
    kapVar.traceData();
    //kapVar.traceKapTryData();
    return 0;
}