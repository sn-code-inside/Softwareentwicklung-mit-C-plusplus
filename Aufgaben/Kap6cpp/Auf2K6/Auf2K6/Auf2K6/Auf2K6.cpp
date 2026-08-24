// Auf2K6.cpp
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

class cIntAndArray                                                              
{
    public:
        cIntAndArray (int iT1, char* str)
        {
            iTest1_= iT1; 
            strArr_ = new char[strlen(str)+1]; 
            strcpy_s (strArr_, strlen(str)+1, str);
        }
        ~cIntAndArray(){delete[] strArr_;}
        /**/
        cIntAndArray& operator = (const cIntAndArray& src)
        {
            int iLen = strlen (src.strArr_);
            delete [] strArr_;
            strArr_ = new char [iLen+1];
            strcpy_s (strArr_, iLen+1, src.strArr_);
            return *this;
        }
        //*/
        int getT1(void){return iTest1_;}
        char* getString (void){return strArr_;}

    private:
        char *strArr_;
        int iTest1_;
};
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"Auf2K6";
    printConsole (str);
    //========================================= 
    cIntAndArray obj1(1,"Test 1.");
    cIntAndArray obj2(3,"Das ist der Test 2.");
    cout << "obj1.getT1: " << obj1.getT1() << "; obj1.getString: " 
         << obj1.getString() <<endl;
    cout << "obj2.getT1: " << obj2.getT1() << "; obj2.getString: " 
         << obj2.getString() <<endl;
    obj1 = obj2;   //Hier weisen Sie das Objekt 2 dem Objekt 1 zu.
    cout << "obj1.getT1: " << obj1.getT1() << "; obj1.getString: " 
         << obj1.getString() <<endl;
    cout << "obj2.getT1: " << obj2.getT1() << "; obj2.getString: " 
         << obj2.getString() <<endl;                                               
    return 0;                                                                       //1                                                   
}                                                                                   //2