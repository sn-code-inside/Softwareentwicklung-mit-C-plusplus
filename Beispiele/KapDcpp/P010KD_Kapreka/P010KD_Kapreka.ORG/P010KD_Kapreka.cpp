// P010KD_Kapreka.cpp 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "kaprekUtil.h"

using namespace std;


int main(void)
{
    int iNumb = 0;
    int iIdx = 0;

    kaprekUtil kapVar (MAX_KAP_1000);

    while (iNumb < kapVar.getMaxKap())
    {
        if (0 == kapVar.ignore(iNumb, kapVar.getKapWidth()))       
        {
            int iTempKap = iNumb;
            int iBreak = 0;
            int iOldKapreka = 0;
            int iTry = 0;
            while (iBreak == 0)
            {
                kapVar.setNumb(iIdx, iNumb);
                int hKap = kapVar.kapToHigh(iTempKap);
                int lKap = kapVar.kapToLow(iTempKap);
                iTempKap = hKap - lKap;
                if (iTempKap == iOldKapreka)
                {
                    iBreak = 1;
                    kapVar.setTempKap(iIdx, iTry, iTempKap);
                    iTempKap = kapVar.corrTempKapp(iTempKap);
                    kapVar.setHigh(iIdx, iTry, hKap);
                    kapVar.setLow(iIdx, iTry, lKap);
                    kapVar.setTry(iIdx, iTry);
                    iIdx++;
                }
                else
                {
                    iOldKapreka = iTempKap;
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
    return 0;
}