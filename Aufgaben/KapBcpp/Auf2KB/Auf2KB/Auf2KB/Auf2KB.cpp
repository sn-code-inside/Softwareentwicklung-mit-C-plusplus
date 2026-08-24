// Auf2KB.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <time.h> 
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_POS     5                                                      
template <typename T=double, int iMaxPos=MAX_POS> class cList              
{
    public:                                                                
        cList (T param);                                                   
        ~cList (void);                                                     
        void fillParam (T param, int iPos);                                
        T retParam (int iPos, int &iErr);
        void xSort (void);
    private:
        T tList_[iMaxPos];                                                 
};

template <typename T, int iMaxPos> cList<T, iMaxPos>::cList (T param)      
{
    for (int i=0; i<iMaxPos; i++)
        tList_[i] = param;
}
template <typename T, int iMaxPos> cList<T, iMaxPos>::~cList (void)
{}
template <typename T, int iMaxPos> 
    void cList<T, iMaxPos>::fillParam (T param, int iPos)                  
{
    if (iPos<iMaxPos)
    {
        tList_[iPos] = param;
    }
}
template <typename T, int iMaxPos> 
    T cList<T, iMaxPos>::retParam (int iPos, int &iErr)                    
{
    iErr = 0;
    if (iPos<iMaxPos)                                                      
        return tList_[iPos];
    else {
        iErr++;                                                            
        return tList_[0];
    }
}

template <typename T, int iMaxPos> 
    void cList<T, iMaxPos>::xSort (void)                     
{
    T tTemp = tList_[0];
    for (int i=0; i<iMaxPos; i++)
    {
        tTemp = tList_[i];
        for (int j=0; j<iMaxPos; j++)
        {
            if (tList_[i] < tList_[j])
            {
                tTemp = tList_[i];
                tList_[i] = tList_[j];
                tList_[j] = tTemp;
            }
        }
    }
}

int main(void)  
{
    //=========================================
    {
    LPCTSTR str = L"Auf2KB";
    printConsole(str);
    }
    //=========================================
    cout << "Aufbau einer zufaelligen Integer-Liste...\n";
    int iErr=0;
    srand( (unsigned int)time(NULL));
    cList<int, MAX_POS> list(0);                                        
    for (int i=0; i<MAX_POS; i++) 
    {
        list.fillParam (rand(), i);                                      
    }
    cout << "... fertig\n";
    cout << "\nAusgabe der zufaelligen Integer-Liste\n";
    for (int i=0; i<MAX_POS; i++) 
    {
        cout << "Pos: " << i << "; Param: " << list.retParam (i, iErr) << "\n";
    }

    list.xSort ();
    cout << "\nAusgabe der zufaelligen Integer-Liste (sortiert)\n";
    for (int i=0; i<MAX_POS; i++) 
    {
        cout << "Pos: " << i << "; Param: " << list.retParam (i, iErr) << "\n";
    }
    return 0;
}
