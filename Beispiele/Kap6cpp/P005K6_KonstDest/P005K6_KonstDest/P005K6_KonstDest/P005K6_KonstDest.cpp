// P005K6_KonstDest.cpp
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
class xString                                           //1
{
public:
    xString (char *str);                                //2
    ~xString ();                                        //3
    void print (void);                                  //4
    inline int getLength (void)                         //5
    {
        return strlen (strString_);                     //6
    }
private:
    char *strString_;                                   //7
};

xString::xString (char *str)                            //8
{
    int iStrLen = strlen (str);                         //9
    strString_ = new char [iStrLen+sizeof(char)];       //10
    strcpy_s (strString_, iStrLen+sizeof(char), str);   //11
    cout << "Konstruktor durchlaufen\n";                //12       
}
xString::~xString ()                                    //13
{
    delete []  strString_;                              //14
    strString_ = NULL;                                  //15
    cout << "Destruktor durchlaufen\n";                 //16
}
void xString::print (void)
{
    cout << strString_;                                 //17
}
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P005K6_KonstDest";
    printConsole (str);
    //========================================= 
    xString myStr ("Hallo Hans");                       //18
    myStr.print(); cout << endl;
    cout << "myStr ist " << myStr.getLength() 
         << " Zeichen lang\n";                          //19
    {                                                   //20
        xString myStr ("Hallo Peter");                  
        myStr.print(); cout << endl;
        cout << "myStr ist " << myStr.getLength() 
             << " Zeichen lang\n";                      //21     
    }
    return 0;                                                    
}