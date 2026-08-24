// P005KB_TCList.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <string.h>
#include <typeinfo>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_POS     5
template <typename T, int iMaxPos=MAX_POS> class cList
{
    public:
        cList (T param);
        ~cList (void);
        void fillParam (T param, int iPos);
        T retParam (int iPos, int &iErr);
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
template <typename T, int iMaxPos> void cList<T, iMaxPos>::fillParam (T param, int iPos)
{
    if (iPos<iMaxPos)
    {
        const type_info *p2TI = &typeid (param);
        if ( strcmp (p2TI->name (), "char *")==0 )
        {
            iPos++; iPos--;
            strcpy_s ((char*)tList_[iPos], 16, param);
        }
        else
            tList_[iPos] = param;
    }
}
template <typename T, int iMaxPos> T cList<T, iMaxPos>::retParam (int iPos, int &iErr)
{
    iErr = 0;
    if (iPos<iMaxPos)
        return tList_[iPos];
    else
    {
        iErr++;
        return tList_[0];
    }
}

int main(void)
{
    //=========================================
    {
    LPCTSTR str = L"P005KB_TCList";
    printConsole(str);
    }
    //=========================================
    cout << "Default-Liste:\n";
    cList<double> list1(.1);
    for (int i=0; i<MAX_POS; i++)
        list1.fillParam (.1*(double)i, i);
    cout << "Ausgabe der Default-Liste\n";
    int iErr=0;
    for (int i=0; i<MAX_POS+1; i++)
    {
        cout << "Pos: " << i << "; Param: " << list1.retParam (i, iErr);
        cout << ";\tiErr: " << iErr << "\n";
    }
    cout << "\nString-Liste:\n";

    cList<char*, 3> list2(""); 
    for (int i=0; i<MAX_POS; i++)
    {
        char str[16];
        sprintf_s (str, 16, "string%d", i);
        list2.fillParam (str, i);
    }
    cout << "Ausgabe der String-Liste\n";
    iErr=0;
    for (int i=0; i<MAX_POS; i++)
    {
        cout << "Pos: " << i << "; Param: " << list2.retParam (i, iErr);
        cout << ";\tiErr: " << iErr << "\n";
    }
    
    return 0;
}

