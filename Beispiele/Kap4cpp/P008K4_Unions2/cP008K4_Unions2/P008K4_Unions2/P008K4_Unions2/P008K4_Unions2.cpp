// P008K4_Unions2
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
    union souUnion                                                      //1                                                     
    {
        char cTest;                                                     //2
        short siTest;                                                   //3
        int iTest;                                                      //4
        long long llTest;                                               //5
    } vUnion;                                                           //6

    vUnion.llTest  = 0x4c4c4c4c4c4c4c4c;                                //7
    vUnion.iTest   = 0x5d5d5d5d;                                        
    vUnion.siTest  = 0x6e6e;                                            
    vUnion.cTest   = 0x7f;           
    //=========================================
    CONST WCHAR * str = L"P008K4_Unions2";
    printConsole(str);
    //========================================= 
    cout << "Variablen wurden von der groessten Size zur kleinsten hin definiert:\n";
    cout << hex;                                                        //8
    cout << "cTest: "   << (int)vUnion.cTest << "; siTest: " << vUnion.siTest
         << "; iTest: " << vUnion.iTest << "; llTest: " << vUnion.llTest
         << "\n";                                                       //9   
    vUnion.cTest   = 0x7f;                                              //10
    vUnion.siTest  = 0x6e6e;  
    vUnion.iTest   = 0x5d5d5d5d;   
    vUnion.llTest  = 0x4c4c4c4c4c4c4c4c; 
    cout << "cTest: "   << (int)vUnion.cTest << "; siTest: " << vUnion.siTest
         << "; iTest: " << vUnion.iTest << "; llTest: " << vUnion.llTest
         << "\n";                                                       //11
    cout << "Variablen wurden von der kleinsten Size zur groessten hin definiert.\n\n";                                    
                                            
    cout << "Der belegte Speicher von vUnion: " << sizeof (vUnion) << " Bytes." 
         << endl;                                                       //12
    return 0;
}