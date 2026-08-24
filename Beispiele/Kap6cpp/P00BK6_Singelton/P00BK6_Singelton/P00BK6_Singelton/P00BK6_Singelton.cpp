// P00BK6_Singelton.cpp
#include "stdafx.h"
#include <iostream>                                                     
using namespace std;  

//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//============================================= 

class cSingleton  {                                   
    public:
        static cSingleton *createSingelton (void);                                  //1
        static cSingleton *destroySingelton (void);                                 //2
        static int getHowOftenUsed (void);                                          //3

    private:
        cSingleton (void);                                                          //4     
        ~cSingleton (void);                                                         //5
        cSingleton& operator = (cSingleton&);
        cSingleton (const cSingleton&);
        static int iNumbOfSingleton_;                                               //6
        static cSingleton * mySingleObj_;                                           //7
};
cSingleton *cSingleton::mySingleObj_;                                               //8
int cSingleton::iNumbOfSingleton_;                                                  //9
cSingleton *cSingleton::createSingelton (void)  {                                   //10
    if (NULL == mySingleObj_)  {                                                    //11
        mySingleObj_ = new cSingleton;
    }
    iNumbOfSingleton_++;                                                            //12
    return mySingleObj_;
}
cSingleton *cSingleton::destroySingelton (void)  {                                  //13
    if (mySingleObj_)                                                               //14
        iNumbOfSingleton_--;                                                        //15
    if ( 0 == iNumbOfSingleton_ )                                                   //16
    {
        if (mySingleObj_) delete mySingleObj_;                                      //17
        mySingleObj_ = NULL;                                                        //18
    }
    return mySingleObj_;                                                            //19
}
cSingleton::cSingleton (void) {
    cout << "=== Singleton wurde angelegt! ===\n";
}
cSingleton::~cSingleton (void) {
    cout << "=== Singleton wurde vernichtet! ===\n";
}
int cSingleton::getHowOftenUsed (void) {
    return iNumbOfSingleton_;
}
int main (void) {
    //=========================================
    CONST WCHAR * str = L"P00BK6_Singelton";
    printConsole (str);
    //=========================================
    cSingleton* mySingle = NULL;
    for (int i=0; i<3; i++) {
        mySingle = cSingleton::createSingelton ();
        cout << "Adresse des Singelton: " << hex << (int)mySingle << endl;
        cout << "Anzahl der Benutzung : " << mySingle->getHowOftenUsed() << endl;
    }
    cout << "\nAnzahl der Benutzung : " << mySingle->getHowOftenUsed() << endl;
    for (int i=0; i<4; i++) {                                                       //20
        mySingle = cSingleton::destroySingelton ();
        cout << "Adresse des Singelton: " << hex << (int)mySingle << endl;
        cout << "Anzahl der Benutzung : " << cSingleton::getHowOftenUsed() << endl; //21
    }
    return 0;
}                        