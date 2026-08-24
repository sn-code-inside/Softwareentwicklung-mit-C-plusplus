// Auf1K6.cpp
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
                                    

class cInt                                                              
{
    public:
        cInt (int iT1, int iT2){iTest1_= iT1; iTest2_=iT2;}
        int getT1(void){return iTest1_;}
        int getT2(void){return iTest2_;}
        ~cInt(){}
    private:
        int iTest1_;
        int iTest2_;
};
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"Auf1K6";
    printConsole (str);
    //========================================= 
    cInt obj1(1,2);
    cInt obj2(3,4);
    cout << "obj1.getT1: " << obj1.getT1() << "; obj1.getT2: " << obj1.getT2() <<endl;
    cout << "obj2.getT1: " << obj2.getT1() << "; obj2.getT2: " << obj2.getT2() <<endl;
    obj1 = obj2;   //Hier weisen Sie das Objekt 2 dem Objekt 1 zu.
    cout << "obj1.getT1: " << obj1.getT1() << "; obj1.getT2: " << obj1.getT2() <<endl;
    cout << "obj2.getT1: " << obj2.getT1() << "; obj2.getT2: " << obj2.getT2() <<endl;                                               
    return 0;                                                    
}