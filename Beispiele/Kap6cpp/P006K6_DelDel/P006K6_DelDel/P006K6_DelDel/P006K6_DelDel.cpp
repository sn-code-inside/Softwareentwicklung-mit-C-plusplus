// P006K6_DelDel.cpp
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
class delTest                                               //1                           
{
public:
    delTest ();                                
    ~delTest ();                                                                      
};

delTest::delTest ()                                         //2       
{
    cout << "Konstruktor delTest durchlaufen\n";                      
}
delTest::~delTest ()                                        //3                       
{                               
    cout << "Destruktor delTest durchlaufen\n";                 
}

int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P006K6_DelDel";
    printConsole (str);
    //========================================= 
    delTest *delTestArr = new delTest [3];                  //4
    delete [] delTestArr;                                   //5

    int * iTest = new int[2];                               //6
    delete [] iTest;                                        //7

    int * iTest2 = new int;                                 //7
    delete iTest2;                                          //8
    return 0;                                               
}