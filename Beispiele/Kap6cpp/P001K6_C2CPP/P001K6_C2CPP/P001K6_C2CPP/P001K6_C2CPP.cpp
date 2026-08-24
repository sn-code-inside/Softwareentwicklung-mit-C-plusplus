// P001K6_C2CPP.cpp
#include "stdafx.h"
#include <iostream>                                                     
using namespace std;
//#include <cmath>                                                          //1
#define iStrLen_ 32                                                     
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
struct tLiquid                                                          
{ 
    char cFarbe[iStrLen_];                                              
    char cFormel[iStrLen_];                                             
    double dMasse;                                                      
    double dVolumen;                                                    
    double retDichte(double, double);                                       //2                              
};

/*===========================================================================*/
/* Desc.: Ermittelt aus Masse und Volumen die Dichte eines Koerpers.         */
/* In   : dMasse (double): Masse                                             */
/*        dVolumen (double): Volumen                                         */
/* Out  : Dichete (double); Falls dVolumen <= 0 wird 0 zurueck gegeben.      */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
double tLiquid::retDichte (double dMasse, double dVolumen)                  //3         
/*---------------------------------------------------------------------------*/
{
    if (dVolumen <= 0)
        return .0;
    return fabs(dMasse/dVolumen);
}

int main (void)
{
    struct tLiquid liquid1;                                             
    struct tLiquid liquid2;                                             

    //=========================================
    CONST WCHAR * str = L"P001K6_C2CPP";
    printConsole (str);
    //========================================= 

    liquid1.dMasse   = 1;                                                             
    liquid1.dVolumen = 1;                                                               
    strcpy_s (liquid1.cFarbe, iStrLen_, "transparant");                 
    strcpy_s (liquid1.cFormel, iStrLen_, "H2O");                        
    cout << "Es handelt sich um eine Fluessigkeit die " << liquid1.cFarbe 
         << " ist und\n"
         << "der chemischen Formel " << liquid1.cFormel << " genuegt.\n";
    cout << "Die Fluessigkeit hat eine Dichte von " 
         << liquid1.retDichte(liquid1.dMasse, liquid1.dVolumen) << " g/qcm.\n";  
    cout << "Die Fluessigkeit heisst Wasser.\n\n";                        

    liquid2.dMasse   = .88;                                                             
    liquid2.dVolumen = 1.0;                                                               
    strcpy_s (liquid2.cFarbe, iStrLen_, "transparant");                 
    strcpy_s (liquid2.cFormel, iStrLen_, "C6H6");                        
    cout << "Es handelt sich um eine Fluessigkeit die " << liquid2.cFarbe 
         << " ist und\n"
         << "der chemischen Formel " << liquid2.cFormel << " genuegt.\n";
    cout << "Die Fluessigkeit hat eine Dichte von " 
         << liquid2.retDichte(liquid2.dMasse, liquid2.dVolumen) << " g/qcm.\n";  
    cout << "Die Fluessigkeit heisst Wasser.\n";                        

    return 0;                                                    
}