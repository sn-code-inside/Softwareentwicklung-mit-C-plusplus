// P00AK6_FriendClass.cpp
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

class cFriendClass {
    friend class cClass;                                                        //1
    public:
        cFriendClass (int iTest=4711);                                          //2
        ~cFriendClass (void);
        int getXFriendTest (void) {return iMyTest_;}
    private:
        int iMyTest_;                                                           //3
};
class cClass {
    public:
        cClass (int iTest);                                                     //4
        ~cClass (void);
        void add (const cFriendClass& cVar) {iMyTest_+=cVar.iMyTest_;}          //5
        void sub (const cFriendClass& cVar) {iMyTest_-=cVar.iMyTest_;}          //6
        int getMyTest (void) {return iMyTest_;}                                 //7
        int getFriendTest (const cFriendClass& cVar) {return cVar.iMyTest_;}    //8
    private:
        int iMyTest_;                                                           //9
};
cFriendClass::cFriendClass (int iTest) {                                        //10
    cout << "Konstruktor cFriendClass\n";
    iMyTest_ = iTest;
}
cFriendClass::~cFriendClass (void) {
    cout << "Destruktor cFriendClass\n";
}
cClass::cClass (int iTest) {
    cout << "Konstruktor cClass\n";
    iMyTest_ = iTest;
}
cClass::~cClass (void) {
    cout << "Destruktor cClass\n";
}
int main (void) {
    //=========================================
    CONST WCHAR * str = L"P00AK6_FriendClass";
    printConsole (str);
    //=========================================    
    cFriendClass myFriend;                                                      //11         
    cClass myClass (4811);                                                      //12
    cout << "Ausgabe der privaten Var von myClass          : " <<
            myClass.getMyTest() << endl;                                        //13
    cout << "Ausgabe der privaten Var von myFriend         : " <<
             myClass.getFriendTest(myFriend) << endl;
    myClass.sub (myFriend);                                                     //14
    cout << "Ausgabe der privaten Var von myClass nach sub : " <<
            myClass.getMyTest() << endl;
    cout << "Ausgabe der privaten Var von myFriend nach sub: " <<
             myClass.getFriendTest(myFriend) << endl;
    cout << "Gleiche Ausgabe via myFriend direkt           : " <<
            myFriend.getXFriendTest () << endl <<endl;                          
    myClass.add (myFriend);                                                     //15
    cout << "Ausgabe der privaten Var von myClass nach add : " <<
            myClass.getMyTest() << endl;
    cout << "Ausgabe der privaten Var von myFriend nach add: " <<
             myClass.getFriendTest(myFriend) << endl;
    return 0;
}                                                                               //16                                            