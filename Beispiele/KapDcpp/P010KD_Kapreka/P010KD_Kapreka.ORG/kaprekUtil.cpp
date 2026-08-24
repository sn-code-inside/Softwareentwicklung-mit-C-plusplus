#include "kaprekUtil.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

kaprekUtil::kaprekUtil(int iMaxKap)
{
    iMaxKap_ = iMaxKap;
    iKapWidth_ = KAP_WIDTH_1000;
    if (iMaxKap == MAX_KAP_100)
        iKapWidth_ = KAP_WIDTH_100;

    for (int i = 0; i < iMaxKap; i++)
    {
        allKaprek_[i].iNumb = 0;
        allKaprek_[i].iTry = 0;
        for (int j = 0; j < MAX_TRY; j++)
        {
            allKaprek_[i].iTempKap[j] = 0;
            allKaprek_[i].iHigh[j] = 0;
            allKaprek_[i].iLow[j] = 0;
        }
    }
}

kaprekUtil::~kaprekUtil()
{

}
int kaprekUtil::getMaxKap(void)
{ 
    return iMaxKap_; 
}

int kaprekUtil::getKapWidth(void)
{
    return iKapWidth_;
}

//******************************************************************************
// Desc.: Trace alles Daten in ein csv-File "Data.csv"
// In   : -
// Out  : -
//******************************************************************************
void kaprekUtil::traceData(void)
{
    FILE* fp = NULL;
    if (getKapWidth()== KAP_WIDTH_1000)
        fp = fopen("Data_1000.csv", "w");
    else if (getKapWidth() == KAP_WIDTH_100)
        fp = fopen("Data_100.csv", "w");
    else
        fp = fopen("Data.csv", "w");

    int iIdx = 0;
    while (iIdx < getMaxKap ())
    {
        fprintf(fp, "iNumb:; %d;", allKaprek_[iIdx].iNumb);
        int iDataIdx = 0;
        while (allKaprek_[iIdx].iHigh[iDataIdx])
        {
            fprintf(fp, "%d;", allKaprek_[iIdx].iHigh[iDataIdx]);
            iDataIdx++;
        }
        fprintf(fp, "\n;;");
        iDataIdx = 0;
        while (allKaprek_[iIdx].iLow[iDataIdx])
        {
            fprintf(fp, "%d;", allKaprek_[iIdx].iLow[iDataIdx]);
            iDataIdx++;
        }
        fprintf(fp, "\n;;");
        iDataIdx = 0;
        while (allKaprek_[iIdx].iLow[iDataIdx])
        {
            fprintf(fp, "%d;", allKaprek_[iIdx].iTempKap[iDataIdx]);
            iDataIdx++;
        }
        iIdx++;
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void kaprekUtil::traceTry(void)
{
    FILE* fp = fopen("try.csv", "w");

    int iIdx = 0;
    while (iIdx < MAX_KAP_1000)
    {
        fprintf(fp, "iNumb:; %d; iTry:; %d\n", allKaprek_[iIdx].iNumb, allKaprek_[iIdx].iTry);
        iIdx++;
    }
    fclose(fp);
}

//******************************************************************************
// Desc.: Definition der Zahlen, die ignoriert werden
// In   : int iKap: Zahl
// Out  : 1: Zahl wird ignoriert; sonst 0
//******************************************************************************
int kaprekUtil::ignore(int iKap, int iKapWidth)
{
    if (iKapWidth == 4)
    {
        if ((iKap == 0) || (iKap == 1111) || (iKap == 2222) || (iKap == 3333) || (iKap == 4444) ||
            (iKap == 5555) || (iKap == 6666) || (iKap == 7777) || (iKap == 8888) || (iKap == 9999))
            return 1;
    }
    else if(iKapWidth == 3)
    {
        if ((iKap == 0) || (iKap == 111) || (iKap == 222) || (iKap == 333) || (iKap == 444) ||
            (iKap == 555) || (iKap == 666) || (iKap == 777) || (iKap == 888) || (iKap == 999))
            return 1;
    }
    else if (iKapWidth == 2)
    {
        if ((iKap == 0) || (iKap == 11) || (iKap == 22) || (iKap == 33) || (iKap == 44) ||
            (iKap == 55) || (iKap == 66) || (iKap == 77) || (iKap == 88) || (iKap == 99))
            return 1;
    }
    return 0;
}

//******************************************************************************
// Desc.: cast eines char-Arrays auf ein int-Array
// In   : char* sChar: char-Array, int* iNumb: int-Array
// Out  : int* iNumb
//******************************************************************************
void kaprekUtil::char2int(char* sChar, int* iNumb)
{
    int iLen = (int)strlen(sChar);
    for (int i = 0; i < iLen; i++)
    {
        iNumb[i] = (int)sChar[i];
    }
}

//******************************************************************************
// Desc.: cast eines int-Arrays auf ein char-Array
// In   : int* iNumb: int-Array, char* sChar: char-Array, int iLen: L‰nge des Array
// Out  : char* sChar
//******************************************************************************
void kaprekUtil::int2char(int* iNumb, char* sChar, int iLen)
{
    for (int i = 0; i < iLen; i++)
    {
        sChar[i] = (char)iNumb[i];
    }
}

//******************************************************************************
// Desc.: Definiert einen Fakor f¸r die hKap
// In   : char* strKap: char-Array
// Out  : int iFac: Faktor
//******************************************************************************
int kaprekUtil::getHighFactor(char* strKap)
{
    int iFac = (int)strlen(strKap);
    if (getKapWidth() == KAP_WIDTH_1000)
    {
        if (iFac == 1)
            iFac = 1000;        //9 wird zu 9000
        if (iFac == 2)
            iFac = 100;         //90 wird zu 9000   
        if (iFac == 3)
            iFac = 10;          //900 wird zu 9000
        if (iFac == 4)
            iFac = 1;           //9000 wird zu 9000
    }
    else if (getKapWidth() == KAP_WIDTH_100)
    {
        if (iFac == 1)
            iFac = 100;        //9 wird zu 900
        if (iFac == 2)
            iFac = 10;         //90 wird zu 900   
        if (iFac == 3)
            iFac = 1;          //900 wird zu 900
    }
    return iFac;
}

//******************************************************************************
// Desc.: Sortiert ein char arry so, dass rechtsstehende Nullen besteigt werden
//        Hinweis: Faktor ist immer 1
// In   : char* strKap: char-Array
// Out  : char* strKap: sortiertes char-Array
//******************************************************************************
int kaprekUtil::getLowFactor(char* strKap)
{
    int iFac = (int)strlen(strKap);
    if (iFac == 1)
        iFac = 1;                                           //kleinste Zahl, weil einstellig; Bsp: 9
    if (iFac == 2)
    {
        if (strKap[0] == '0')                               //90 wird zu 9 
        {
            strKap[0] = strKap[1];
            strKap[1] = 0;
            iFac = 1;
        }
        else
            iFac = 1;
    }
    if (iFac == 3)
    {
        if ((strKap[0] == '0') && (strKap[1] == '0'))       //900 wird zu 9
        {
            strKap[0] = strKap[2];
            strKap[1] = 0;
            iFac = 1;
        }
        else if ((strKap[0] == '0') && (strKap[1] != '0'))  //990 zu 99
        {
            strKap[0] = strKap[1];
            strKap[1] = strKap[2];
            strKap[2] = 0;
            iFac = 1;
        }
        iFac = 1;
    }
    if (iFac == 4)                                          //9999 bleibt konstant
        iFac = 1;
    return iFac;
}

//******************************************************************************
// Desc.: Sortiert ein int arry so, dass die gˆﬂte Zahl am kleinsten Index steht
// In   : int* iNumb: int-Array; int iLen: L‰nge des Arrys
// Out  : int* iNumb: sortiertes int-Array
//******************************************************************************
void kaprekUtil::highSort(int* iNumb, int iLen)
{
    for (int i = 0; i < iLen - 1; i++)
    {
        for (int j = 0; j < iLen - i - 1; j++)
        {
            if (iNumb[j] <= iNumb[j + 1])
            {
                int iTemp = iNumb[j];
                iNumb[j] = iNumb[j + 1];
                iNumb[j + 1] = iTemp;
            }
        }
    }
}

//******************************************************************************
// Desc.: Sortiert ein int arry so, dass die kleinste Zahl am kleinsten Index steht
// In   : int* iNumb: int-Array; int iLen: L‰nge des Arrys
// Out  : int* iNumb: sortiertes int-Array
//******************************************************************************
void kaprekUtil::lowSort(int* iNumb, int iLen)
{
    for (int i = 0; i < iLen - 1; i++)
    {
        for (int j = 0; j < iLen - i - 1; j++)
        {
            int iT0 = iNumb[j];
            int iT1 = iNumb[j + 1];
            if (iNumb[j] > iNumb[j + 1])
            {
                int iTemp = iNumb[j];
                iNumb[j] = iNumb[j + 1];
                iNumb[j + 1] = iTemp;
            }
        }
    }
}

//******************************************************************************
// Desc.: Sortiert eine Zahl so, dass die grˆﬂte Ziffer links steht
// In   : int iKap: Zahl
// Out  : sortierte Zahl
//******************************************************************************
int kaprekUtil::kapToHigh(int iKap)
{
    int iHigh = 0;
    char strKap[10];
    itoa(iKap, strKap, 10);

    int iNumb[10] = { 0 };
    char2int(strKap, iNumb);
    int iRes = atoi(strKap);
    highSort(iNumb, (int)strlen(strKap));
    int2char(iNumb, strKap, (int)strlen(strKap));

    int iFactor = getHighFactor(strKap);
    iHigh = iFactor * atoi(strKap);

    return iHigh;
}
//******************************************************************************
// Desc.: Sortiert eine Zahl so, dass die kleinste Ziffer links steht
// In   : int iKap: Zahl
// Out  : sortierte Zahl
//******************************************************************************
int kaprekUtil::kapToLow(int iKap)
{
    int iLow = 0;
    char strKap[10];
    itoa(iKap, strKap, 10);

    int iNumb[10] = { 0 };
    char2int(strKap, iNumb);
    lowSort(iNumb, (int)strlen(strKap));
    int2char(iNumb, strKap, (int)strlen(strKap));

    int iFactor = getLowFactor(strKap);
    iLow = iFactor * atoi(strKap);

    return iLow;
}
//******************************************************************************
// Desc.: korrigiert die aktuelle "Kaprekarzahl" auf vierstellige Zahl
// In   : int iTempKap
// Out  : korriegierte vierstellige "Kaprekarzahl"
//******************************************************************************
int kaprekUtil::corrTempKapp(int iTempKap)
{
    char strKap[10];
    int iMaxKap = getKapWidth();
    if (iMaxKap == KAP_WIDTH_1000)
    {
        itoa(iTempKap, strKap, 10);
        if ((int)strlen(strKap) == 3)               //900 wird zu 9000
            return (10 * iTempKap);
        else if ((int)strlen(strKap) == 2)          //90 wird zu 9000
            return (100 * iTempKap);
        else if ((int)strlen(strKap) == 1)          //9 wird zu 9000
            return (1000 * iTempKap);
        else
            return (1 * iTempKap);                  //9000 bleibt 9000
    }
    else if (iMaxKap == KAP_WIDTH_100)
    {
        itoa(iTempKap, strKap, 10);
        if ((int)strlen(strKap) == 2)               //90 wird zu 900
            return (10 * iTempKap);
        else if ((int)strlen(strKap) == 1)          //9 wird zu 900
            return (100 * iTempKap);
        else
            return (1 * iTempKap);                  //900 bleibt 900
    }
    else
        return (1 * iTempKap);                      //9000 bleibt 9000
}

//******************************************************************************
// Desc.: Sichert die aktuelle Nummer (1, 2, 3, etc.) in die Struktur aller Zahlen
// In   : int iIdx: Aktuelle Pos in dem Array; int iNumb: aktuelle Zahl
// Out  : -
//******************************************************************************
void kaprekUtil::setNumb(int iIdx, int iNumb)
{
    allKaprek_[iIdx].iNumb = iNumb;
}
//******************************************************************************
// Desc.: Sichert die tempor‰re "Kaprekar-Zahl" in die Struktur aller Zahlen
// In   : int iIdx: Aktuelle Pos in dem Array; int iTry: "Versuchszahl" 
//        int iTempKap: tempor‰re "Kaprekar-Zahl"
// Out  : -
//******************************************************************************
void kaprekUtil::setTempKap(int iIdx, int iTry, int iTempKap)
{
    allKaprek_[iIdx].iTempKap[iTry] = iTempKap;
}
//******************************************************************************
// Desc.: Sichert die "groﬂe" "Kaprekar-Zahl" in die Struktur aller Zahlen
// In   : int iIdx: Aktuelle Pos in dem Array; int iTry: "Versuchszahl
//        int hKap: "groﬂe" "Kaprekar-Zahl"
// Out  : -
//******************************************************************************
void kaprekUtil::setHigh(int iIdx, int iTry, int hKap)
{
    allKaprek_[iIdx].iHigh[iTry] = hKap;
}
//******************************************************************************
// Desc.: Sichert die "kleine" "Kaprekar-Zahl" in die Struktur aller Zahlen
// In   : int iIdx: Aktuelle Pos in dem Array; int iTry: "Versuchszahl
//        int lKap: "kleine" "Kaprekar-Zahl"
// Out  : -
//******************************************************************************
void kaprekUtil::setLow(int iIdx, int iTry, int lKap)
{
    allKaprek_[iIdx].iLow[iTry] = lKap;
}
//******************************************************************************
// Desc.: Sichert die Anzahl der Versuche in die Struktur aller Zahlen
// In   : int iIdx: Aktuelle Pos in dem Array; int iTry: "Versuchszahl
// Out  : -
//******************************************************************************
void kaprekUtil::setTry(int iIdx, int iTry)
{
    allKaprek_[iIdx].iTry = iTry;
}


