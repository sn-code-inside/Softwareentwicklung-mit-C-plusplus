//P007K6_Static.cpp
#include "stdafx.h"
#include <iostream>                                                     
using namespace std;  

int iGlobal_ = 0;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 
#define strAnzVorhObj   "Anzahl vorhandener Objekte von cStatic: "      //1
class cStatic                                                           //2                                    
{ 
    public:
        cStatic (void);                                                      
        ~cStatic ();
        static int getCounter(void);                                    //3                           
    private:                                                                 
        static int iObjCount_;                                          //4                                                                                                
};
int cStatic::iObjCount_;                                                //5

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
const int iKonst_ = 5;                                                  //8
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P007K6_Static";
    //printConsole (str);
    //=========================================  
    cout << strAnzVorhObj << cStatic::getCounter() << endl;             //9 
    cStatic *staticTest[iKonst_];                                                //10
    cout << strAnzVorhObj << cStatic::getCounter() << endl;             //11
    for (int i=0; i<iKonst_; i++)
    { 
        staticTest[i] = new cStatic;                                    //12
    }
    cout << strAnzVorhObj << staticTest[0]->getCounter() << endl;       //13
    for (int i=0; i<iKonst_-2; i++)                                     //14
    { 
        delete staticTest[i];                                           //15
        staticTest[i] = NULL;
    }
    cout << strAnzVorhObj << staticTest[0]->getCounter() << endl;       //16
    return 0;                                                    
}
