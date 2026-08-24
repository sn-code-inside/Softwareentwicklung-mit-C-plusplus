// P004KD_move.cpp
#include "stdafx.h"
#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <string>
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================
#define MAX_STR 2
class cStrList
{
public:
    cStrList (string str) {                             //1
        for (unsigned int i=0; i<MAX_STR; i++)
            myStrList_.push_back (str);
    }
    cStrList (const cStrList& str) {                    //2
        cout << "Copy-Constructor\n";
        myStrList_ = str.myStrList_;
    }
    cStrList& operator = (const cStrList& str) {        //3
        cout << "= operator\n";
        myStrList_ = str.myStrList_; return *this;
    }

    cStrList (const cStrList&& str) {                   //4
        cout << "move Copy-Constructor\n";
        myStrList_ = move (str.myStrList_);
    }
    cStrList& operator = (cStrList&& str) {             //5
        cout << "move operator\n";
        myStrList_ = move (str.myStrList_); return *this;
    }

    void getStr(void) {                                 //6
      for (list<string>::iterator it=myStrList_.begin(); it != myStrList_.end(); ++it)
        cout << *it << "; " << endl;
    }
private:
     list<string> myStrList_;                           //7
};

int main(void)
{
    //=========================================
    LPCTSTR str = L"P004KD_move";
    printConsole(str);
    //=========================================
    string str1 ("Das ist der String1.");               //8
    string str2 ("Das ist der String2.");
                                                        
    cout << "String1-Ausgabe vor move : " << str1.data() << endl; //9
    cout << "String2-Ausgabe vor move : " << str2.data() << endl;
    str2 = move (str1);                                 //10
    cout << "String1-Ausgabe nach move: " << str1.data() << endl;
    cout << "String2-Ausgabe nach move: " << str2.data() << endl << endl;

    cStrList myStrList1(str2);                          //11
    cout << "Ausgabe myStr1-Liste     : " << endl;
    myStrList1.getStr(); cout << endl;
    
    cStrList myStrList2(str1);                          //12
    cout << "Ausgabe myStr2-Liste     : " << endl;
    myStrList2.getStr(); cout << endl;

    myStrList2 = myStrList1;                            //13
    cout << "Ausgabe myStr2-Liste     : " << endl;
    myStrList2.getStr(); cout << endl;

    myStrList1 = move(myStrList2);                     //14
    cout << "Ausgabe myStr2-Liste     : " << endl;
    myStrList2.getStr(); cout << endl;

    cout << "Ausgabe myStr1-Liste     : " << endl;      //15
    myStrList1.getStr(); 
    
    return 0;
}
