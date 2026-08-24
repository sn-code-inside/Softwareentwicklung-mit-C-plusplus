// P005KB_TCList.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <typeinfo>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_POS     5                                                       //1
template <typename T=double, int iMaxPos=MAX_POS> class cList               //2
{
    public:                                                                 //3
        cList (T param);                                                    //4
        ~cList (void);                                                      //5
        void fillParam (T param, int iPos);                                 //6
        T retParam (int iPos, int &iErr);
    private:
        T tList_[iMaxPos];                                                  //7
};

template <typename T, int iMaxPos> cList<T, iMaxPos>::cList (T param)       //8
{
    const type_info* p2TI = &typeid (T);
    const char *strName = p2TI->name();
    if (strcmp (strName, "char *") == 0)
    {
        int i=1;
        i++;
    }

    for (int i=0; i<iMaxPos; i++)
        tList_[i] = param;
}
template <typename T, int iMaxPos> cList<T, iMaxPos>::~cList (void)
{}
template <typename T, int iMaxPos> 
    void cList<T, iMaxPos>::fillParam (T param, int iPos)                   //9
{
    if (iPos<iMaxPos)
    {
        tList_[iPos] = param;
    }
}
template <typename T, int iMaxPos> 
    T cList<T, iMaxPos>::retParam (int iPos, int &iErr)                     //10
{
    iErr = 0;
    if (iPos<iMaxPos)                                                       //11
        return tList_[iPos];
    else {
        iErr++;                                                             //12
        return tList_[0];
    }
}
int main(void)  {
    //=========================================
    {
    LPCTSTR str = L"P005KB_TCList";
    printConsole(str);
    }
    //=========================================
    cout << "Default-Liste:\n";
    cList<> list1(.1);                                                      //13
    for (int i=0; i<MAX_POS; i++)
        list1.fillParam (.1*(double)i, i);                                  //14
    cout << "Ausgabe der Default-Liste\n";
    int iErr=0; 
    for (int i=0; i<MAX_POS+1; i++) {
        cout << "Pos: " << i << "; Param: " << list1.retParam (i, iErr);    //15
        cout << ";\tiErr: " << iErr << "\n";
    }
    cout << "\nInteger-Liste:\n";

    cList<int, 3> list2(0);                                                 //16
    for (int i=0; i<MAX_POS; i++) {
        list2.fillParam (2*i+1, i);                                         //17
    }
    cout << "Ausgabe der Integer-Liste\n";
    iErr=0;
    for (int i=0; i<MAX_POS; i++) {
        cout << "Pos: " << i << "; Param: " << list2.retParam (i, iErr);    //18
        cout << ";\tiErr: " << iErr << "\n";
    }


    cList<char*, MAX_POS> list3("");                                         
    for (int i=0; i<MAX_POS; i++) {
        list3.fillParam ("AAA", i);                                         
    }
    /*
    cout << "Ausgabe der char*-Liste\n";
    iErr=0;
    for (int i=0; i<MAX_POS; i++) {
        cout << "Pos: " << i << "; Param: " << list3.retParam (i, iErr);   
        cout << ";\tiErr: " << iErr << "\n";
    }
    */
    return 0;
}

