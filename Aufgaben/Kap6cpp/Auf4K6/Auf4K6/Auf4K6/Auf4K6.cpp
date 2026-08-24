// Auf4K6.cpp
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

class cGobalFriend                                                              
{
    friend void addString (cGobalFriend&, char*);
    public:
        cGobalFriend (char* str)
        {
            strArr_ = new char[strlen(str)+1]; 
            strcpy_s (strArr_, strlen(str)+1, str);
        }
        ~cGobalFriend(){delete[] strArr_;}
        char* getString (void){return strArr_;}

    private:
        char *strArr_;
};
void addString (cGobalFriend& obj, char* strAdd)
{
    int iLen = strlen (strAdd)+strlen(obj.strArr_)+1;           //1
    char *strTemp = new char [iLen];                            //2
    strcpy_s (strTemp, iLen, obj.strArr_);                      //3
    delete [] obj.strArr_;                                      //4
    obj.strArr_ = new char [iLen];                              //5
    strcpy_s (obj.strArr_, iLen, strTemp);                      //6
    strcat_s (obj.strArr_, iLen, strAdd);                       //7
}
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"Auf4K6";
    printConsole (str);
    //========================================= 
    cGobalFriend obj1("Hallo ");
    cout << "strArr_ vor addString : " << obj1.getString() << endl;
    addString (obj1, "Peter!")  ;
    cout << "strArr_ nach addString: " << obj1.getString() << endl;
    return 0;                                                                                                                         
}               