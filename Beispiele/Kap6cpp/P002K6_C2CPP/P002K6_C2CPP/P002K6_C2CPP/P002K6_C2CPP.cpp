// P002K6_C2CPPa.cpp
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
struct tLiquid                                                          
{                                                                                               
        tLiquid (void);                                                         //1
        double retDichte(void);                                                 //2
    private:                                                                    //3
        double dMasse_;                                                         //4 
        double dVolumen_;                                                       //5 
};
/*===========================================================================*/
/* Desc.: Konstruktur; er initialisiert die private Members dMasse_ und      */
/*        dVolumen_                                                          */
/* In   : dMasse: double; dVolumen: double                                   */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
tLiquid::tLiquid (void)                                                         //6            
/*---------------------------------------------------------------------------*/
{
    dMasse_ = 1;
    dVolumen_ = 1;
}
/*===========================================================================*/
/* Desc.: Ermittelt aus Masse und Volumen die Dichte eines Koerpers.         */
/* In   : -                                                                  */
/* Out  : Dichete (double); Falls dVolumen <= 0 wird 0 zurueck gegeben.      */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
double tLiquid::retDichte (void)                                                //7         
/*---------------------------------------------------------------------------*/
{
    if (dVolumen_ <= 0)
        return .0;
    return fabs(dMasse_/dVolumen_);
}



int main (void)
{
    tLiquid liquid1;                                                     //8                                                                               

    //=========================================
    CONST WCHAR * str = L"P002K6_C2CPPa";
    printConsole (str);
    //=========================================  
    liquid1.dMasse_ = 5.0;     
    //Compilerfehler: Auf "Member "tLiquid::dMasse_" (deklariert in Zeile 17)" kann nicht zugegriffen werden.

    cout << "Die Fluessigkeit hat eine Dichte von " 
         << liquid1.retDichte() << " g/qcm.\n";                                 //9
    cout << "Die Fluessigkeit heisst Wasser.\n";                        
    return 0;                                                    
}