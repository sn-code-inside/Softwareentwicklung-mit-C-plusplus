// P009K4_Auto.cpp
#include <iostream>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
//============================================= 

int main(void) {
    auto cTest = 'A';                                                               // 1
    auto iTest = 3;
    auto fTest = 3.14f;
    auto dTest = 22./7.;
    //=========================================
    CONST WCHAR* str = L"P009K4_Auto";
    printConsole(str);
    //========================================= 
    cout << "Ausgabe von Inhalt und Speicherbededarf der auto-Variablen: \n";
    cout << "cTest: " << cTest << "\t Size: " << sizeof(cTest) << endl;            // 2
    cout << "iTest: " << iTest << "\t Size: " << sizeof(iTest) << endl;
    cout << "fTest: " << fTest << "\t Size: " << sizeof(fTest) << endl;
    cout << "dTest: " << dTest << "\t Size: " << sizeof(dTest) << endl;
    return 0;
}
