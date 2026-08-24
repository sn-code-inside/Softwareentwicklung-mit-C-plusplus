// P004K4_Struct2
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
int main (void)
{
    //=========================================
    CONST WCHAR * str = L"P004K4_Struct2";
    printConsole (str);
    //========================================= 
    struct tPerson                                              
    {
        unsigned short usAge;                                     
        unsigned short usSize;                                  
        float fWeight;                                          
        char cName[256];                                        
    };
    tPerson person1 = {33, 180, 81.5, "Anton Aue"}; //1        
    cout << "Alter  : "   << person1.usAge   
         << "\nGroesse: " << person1.usSize 
         << "\nGewicht: " << person1.fWeight 
         << "\nName   : " << person1.cName << endl; //2
    return 0;
}
