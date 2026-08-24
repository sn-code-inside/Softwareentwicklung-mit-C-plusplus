// P001K5_If.cpp 
#include <iostream>                                // 1
using namespace std;
#include <ctype.h>                                 // 2
//=============================================
#include <Windows.h>
void printConsole(LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle(lpConsoleTitle);
}
//=============================================
int main(void)
{
    char cChr;                                     //3
    cin >> cChr;                                   //4
    //=============================================
    CONST WCHAR* str = L"P001K5f";
    printConsole(str);
    //=============================================
    cChr = tolower(cChr);                          //5 
    cout << "Zeichen vor if :   " << cChr << endl; //6
    if (cChr == 'a')                               //7
        cChr++;
    cout << "Zeichen nach if:   " << cChr << endl; //8
    cout << "--------------------- \n";
    cin >> cChr;                                   //9
    cChr = tolower(cChr);                          //10
    cout << "Zeichen vor if :   " << cChr << endl; //11
    if (cChr == 'a')                               //12
        cChr++;
    cout << "Zeichen nach if:   " << cChr << endl; //13

    if (cChr == 'a')                               //7 ==>Programm5.2
        cChr++;
    else
    {
        if (cChr == 'b')
            cChr--;
        else
            cChr = 'c';
    }

    if (cChr == 'a')                               //7 ==>Programm5.3
        cChr++;
    else if (cChr == 'b')
        cChr--;
    else
        cChr = 'c';

    return 0;
}