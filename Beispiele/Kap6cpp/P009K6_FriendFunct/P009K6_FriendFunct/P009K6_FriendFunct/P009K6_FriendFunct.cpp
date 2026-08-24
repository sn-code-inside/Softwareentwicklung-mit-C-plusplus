// P009K6_FriendFunct.cpp
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
    friend int addToPriv (cFriendFunct&, int);                  //1
    public:
        cFriendFunct (int);                                                                                           //1
        ~cFriendFunct (void);                                   
        int getPriv (void) {return iMyTest_;};                  //2
    private:
        int iMyTest_;                                           //3 
};                                        
cFriendFunct::cFriendFunct (int iTest)                                          
{
    cout << "Konstruktor cFriendFunct\n";
    iMyTest_ = iTest;                                           //4                                
}
cFriendFunct::~cFriendFunct (void)                                              
{
    cout << "Destruktor cFriendFunct\n";                                        
}

int addToPriv (cFriendFunct& friendVar, int iAdd)
{
    friendVar.iMyTest_+=iAdd;                                   //5
    return friendVar.iMyTest_;                                  //6
}

int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P009K6_FriendFunct";
    printConsole (str);
    //=========================================  
    
    int iS = sizeof (cFriendFunct);
    cFriendFunct myFriend(1);                                   //7
    cout << "Ausgabe der privaten Var vor addToPriv : " << 
            myFriend.getPriv () << endl;                        //8
    cout << "Ausgabe der privaten Var via friendFkt.: " << 
            addToPriv (myFriend, 5) << endl;                    //9
    cout << "Ausgabe der privaten Var nach addToPriv: " << 
            myFriend.getPriv () << endl;                        //10                       
    return 0;                                                    
}                                                               //11