//P00CK5_ggT.cpp
#include "stdafx.h"
#include <iostream>                                 //1
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
    int iX, iY, iZ, iM, iNr, iggT;                  //2
    //=============================================
    CONST WCHAR * str = L"P00CK5_ggT";
    printConsole(str);
    //============================================= 
    iX = 28; iY=18; iNr=1;                          //3
    do                                              //4
    {
        iZ = iX/iY;                                 //5
        iM = iX % iY;
        cout << "iNr="  << iNr << ";\tiX="      << iX 
             << ";\tiY="<< iY  << ";\tiZ=iX/iY="<< iX/iY
             << ";\tiM="<< iM  << endl;             //6
        iX   = iY;                                  //7
        iggT = iY;                                  //8
        iY   = iM;                                  //9
        iNr++;                                      //10
    } while (iM);                                   //11
    cout << "\t\t\t\t\tggT= " << iggT 
         << "; Fertig!\n";                          //12
    return 0;                                       //13                                                        
}