#pragma once
#pragma warning(disable: 4996)

#define MAX_KAP_1000  1000
#define MAX_KAP_100    100
#define KAPREKAR_1000 6174
#define KAPREKAR_100   495

#define MAX_TRY         10

#define KAP_WIDTH_1000   4
#define KAP_WIDTH_100    3

class kaprekUtil
{
private:
    typedef struct
    {
        int iNumb;                  //Zahl die zu KAPREKAR führen soll
        int iTry;                   //wann wird 6174 erreicht
        int iHigh[MAX_TRY];         //Speicher für HighZahlen 
        int iLow[MAX_TRY];          //Speicher für LowZahlen 
        int iTempKap[MAX_TRY];      //Diff von h und l

    } tOneKaprek;

    tOneKaprek allKaprek_[MAX_KAP_1000];

    int iKapWidth_;
    int iMaxKap_;

public:
    kaprekUtil(int iMaxKap);
    ~kaprekUtil(void);

    int getMaxKap(void);
    int getKapWidth(void);

    // Desc.: Trace alles Daten in ein csv-File "Data.csv"
    void traceData(void);
    void traceTry(void);
    // Desc.: Definition der Zahlen, die ignoriert werden
    int ignore(int iKap, int iKapWidth);
    // Desc.: cast eines char-Arrays auf ein int-Array
    void char2int(char* sChar, int* iNumb);
    // Desc.: cast eines int-Arrays auf ein char-Array
    void int2char(int* iNumb, char* sChar, int iLen);

    // Desc.: Definiert einen Fakor für die hKap
    int getHighFactor(char* strKap);
    // Desc.: Sortiert ein char arry so, dass rechtsstehende Nullen besteigt werden
    //        Hinweis: Faktor ist immer 1
    int getLowFactor(char* strKap);
    // Desc.: Sortiert ein int arry so, dass die gößte Zahl am kleinsten Index steht
    void highSort(int* iNumb, int iLen);
    // Desc.: Sortiert ein int arry so, dass die kleinste Zahl am kleinsten Index steht
    void lowSort(int* iNumb, int iLen);
    // Desc.: Sortiert eine Zahl so, dass die größte Ziffer links steht
    int kapToHigh(int iKap);
    // Desc.: Sortiert eine Zahl so, dass die kleinste Ziffer links steht
    int kapToLow(int iKap);

    // Desc.: korrigiert die aktuelle "Kaprekarzahl" auf vierstellige Zahl
    int corrTempKapp(int iTempKap);

    // Desc.: Sichert die aktuelle Nummer (1, 2, 3, etc.) in die Struktur aller Zahlen
    void setNumb(int iIdx, int iKap);
    // Desc.: Sichert die temporäre "Kaprekar-Zahl" in die Struktur aller Zahlen
    void setTempKap(int iIdx, int iTry, int iTempKap);
    // Desc.: Sichert die "große" "Kaprekar-Zahl" in die Struktur aller Zahlen
    void setHigh(int iIdx, int iTry, int hKap);
    // Desc.: Sichert die "kleine" "Kaprekar-Zahl" in die Struktur aller Zahlen
    void setLow(int iIdx, int iTry, int lKap);
    // Desc.: Sichert die Anzahl der Versuche in die Struktur aller Zahlen
    void setTry(int iIdx, int iTry);
};

