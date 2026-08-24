// P008K6_this.cpp
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

class cFriendFunct                                                                                      
{ 
    public:
        cFriendFunct (int);                                                         //1
        ~cFriendFunct (void);                                                              
        int getItsAdr(void);                                                        //2
        int getiTestByFct(void);                                                    //3
        int getiTestByThis(void);                                                   //4
    private:
        int iMyTest_; //Test-Variable, zur Verdeutlichung von this                    5
};                                        
cFriendFunct::cFriendFunct (int iTest)                                                            //6                                                                 
{
    cout << "Konstruktor cFriendFunct\n";
    iMyTest_ = iTest;                                                               //7          
}
cFriendFunct::~cFriendFunct (void)                                                       
{
    cout << "Destruktor cFriendFunct\n";                                            //8                                         
}
int cFriendFunct::getItsAdr(void)
{
    return (int)this;                                                               //9
}
int cFriendFunct::getiTestByFct(void)
{
    return iMyTest_;                                                                //10
}
int cFriendFunct::getiTestByThis(void)
{
    return (*this).iMyTest_;                                                        //11
}
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P008K6_this";
    printConsole (str);
    //=========================================  
        
    cFriendFunct myThis1(1);                                                        //12                           
    cFriendFunct myThis2(10);                                                       //13
    cout<<endl;
    cout<<"Adresse von myThis1 via AdrOp : "<< hex<<(int)&myThis1           <<endl; //14
    cout<<"Adresse von myThis1 via this  : "<< hex<<myThis1.getItsAdr()     <<endl; //15
    cout<<"iMyTest_ durch getiTestByFct  : "<< hex<<myThis1.getiTestByFct() <<endl; //16
    cout<<"iMyTest_ durch getiTestByThis : "<< hex<<myThis1.getiTestByThis()<<endl; //17
    cout<<endl;
    cout<<"Adresse von myThis2 via AdrOp : "<< hex<<(int)&myThis2           <<endl; 
    cout<<"Adresse von myThis2 via this  : "<< hex<<myThis2.getItsAdr()     <<endl;
    cout<<"iMyTest_ durch getiTestByFct  : "<< hex<<myThis2.getiTestByFct() <<endl;
    cout<<"iMyTest_ durch getiTestByThis : "<< hex<<myThis2.getiTestByThis()<<endl;
    cout<<endl;
    return 0;                                                    
}