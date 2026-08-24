// P005K4_Alignas.cpp 
#include <iostream>
using namespace std;
//=============================================
#include <Windows.h>                                
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
//============================================= 
// 
//struct alignas(4) tDemo                                          //1
//#pragma pack (1)                                                  //2
struct tDemo
{
    //char cTest2;
    char cTest;
    //double dTest2;

    double dTest;
};
int main()
{
    //=========================================
    CONST WCHAR* str = L"P005K4_Alignas";
    printConsole(str);
    //========================================= 

    tDemo demo;
    cout << "alignof(tDemo)     " << alignof(tDemo) << endl;        //3
    cout << "sizeof(tDemo)      " << sizeof(tDemo) << endl;         //4
    demo.cTest = 'A';
    demo.dTest = 0.0;
    cout << "sizeof(demo.cTest) " << sizeof(demo.cTest) << endl;
    cout << "sizeof(demo.dTest) " << sizeof(demo.dTest) << endl;
#pragma pack (show)
    return 0;
}
