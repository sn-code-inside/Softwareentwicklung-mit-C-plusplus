// P008K9_moveConst.cpp
// move algorithm example
#include "stdafx.h"
#include <iostream>     // std::cout
#include <algorithm>    // std::move (ranges)
#include <utility>      // std::move (objects)
#include <vector>       // std::vector
#include <string>       // std::string

int main (void) 
{

    std::vector<std::string> foo(4);// = {"air","water","fire","earth"};
    foo[0].assign ("air");
    foo[1].assign ("water");
    foo[2].assign ("fire");
    foo[3].assign ("earth");
    std::vector<std::string> bar (4);

    // moving ranges:
    std::cout << "Moving ranges...\n";
    std::move ( foo.begin(), foo.begin()+4, bar.begin() );

    std::cout << "foo contains " << foo.size() << " elements:";
    std::cout << " (each in an unspecified but valid state)";
    std::cout << '\n';

    std::cout << "bar contains " << bar.size() << " elements:";
    for (std::string& x: bar) std::cout << " [" << x << "]";
    std::cout << '\n';

    // moving container:
    std::cout << "Moving container...\n";
    foo = std::move (bar);

    std::cout << "foo contains " << foo.size() << " elements:";
    for (std::string& x: foo) std::cout << " [" << x << "]";
    std::cout << '\n';

    std::cout << "bar is in an unspecified but valid state";
    std::cout << '\n';

  return 0;
}

/*
#include "stdafx.h"
#include "xString.h"                                            
#include <iostream>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================

int main(void)
{
    //=========================================
    LPCTSTR str = L"P008K9_moveConst";
    printConsole(str);
    //========================================= 
    xString str1("Hallo ");                     //1                         
    xString str2 = str1;                        //2
    xString str5(&&str1);
    xString str3;                               //3
    str3 = str1;                                //4
    str3+="3";                                  //5
    str2+="2";
    str1+="1";
    cout << str1.getString() << endl;           //6
    cout << str2.getString() << endl; 
    cout << str3.getString() << endl;   
    
    return 0;
}                                               //7                                                      

*/
