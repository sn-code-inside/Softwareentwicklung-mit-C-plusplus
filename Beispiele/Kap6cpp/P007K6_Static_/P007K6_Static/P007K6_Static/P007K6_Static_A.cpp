//P007K6_Static.cpp
#include "stdafx.h"
#include <iostream>                                                     
using namespace std;  

int iGlobal_ = 0;
int iObjCount_ = 0;   
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 
#define strAnzVorhObj   "Anzahl vorhandener Objekte von cStatic: "      //1
class cStatic                                                         //2                                    
{ 
    public:
        cStatic (void);                                                      
        ~cStatic ();
        int getCounter(void);                                    //3                           
        void nothing (void);
    private:                                                                 
        int iTest;                                          //4                                                                                                
};
                                             //5

cStatic::cStatic (void)                                                                    
{
    cout << "Konstruktor cStatic\n";
    iObjCount_++;  iGlobal_++;                                                     //6
}
cStatic::~cStatic (void)                                                                    
{
    cout << "Destruktor cStatic\n";
    iObjCount_--;  iGlobal_--;                                                    //7
}
int cStatic::getCounter(void)
{
    return iObjCount_;
}

void cStatic::nothing (void)
{
    int i=0;
    i++;
}
const int iKonst_ = 5;                                                  //8
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P007K6_Static";
    printConsole (str);
    //=========================================  
    //cout << strAnzVorhObj << cStatic::getCounter() << endl;             //9 
    //cStatic *staticTest[iKonst_];  
    cStatic * test = nullptr;
    test->getCounter ();

    //staticTest[0]->getCounter();
    //cout << strAnzVorhObj << cStatic::getCounter() << endl;             //11
    /*
    for (int i=0; i<iKonst_; i++)
    { 
        staticTest[i] = new cStatic;                                    //12
    }
    */
    cStatic * staticTest = new cStatic[5];
    cout << strAnzVorhObj << staticTest[0].getCounter() << endl;       //
    delete [] staticTest;                                           //15
    staticTest = NULL;
    cout << strAnzVorhObj << staticTest[0].getCounter() << endl;       //16
    staticTest[0].nothing ();
    return 0;                                                    
}