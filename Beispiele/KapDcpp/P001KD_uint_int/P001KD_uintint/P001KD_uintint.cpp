// P001KC_uintint.cpp
#include <iostream>
using namespace std;
//#pragma warning(once : 4305 )

class cBasis { void nothing(void) {} };
class cAbgeleitet : public cBasis { double dTest_; };

//=============================================
#include <Windows.h>                                
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
//=============================================
#define MAX_NUMB  5                                                                   
int main(void)
{

    //=========================================
    {
        LPCTSTR str = L"P001KD_uintint";
        printConsole(str);
    }
    //=========================================
    //float fTest = 4.1f;


    int iT1           = -1;
    unsigned int uiT1 = 1;
    cout << "iT1      : " << iT1  << endl;
    cout << "uiT1     : " << uiT1 << endl;
    cout << "iT1/uiT1 : " << iT1 / (int)uiT1 << endl;
    cout << "uiT1/iT1 : " << (int)uiT1 / iT1 << endl;

    //float fTest2 = 5.1;

   return 0;
}