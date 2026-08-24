//P003K6_C2CPP.cpp
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
class tLiquid                                                          
{
    public:                                                                     //1
        tLiquid (void);                                                         
        double retDichte(void);                                                 
        void setMasse (double dMasse);                                          //2
        void setVolumen (double dVolumen);                                      //3
    private:                                                                    
        double dMasse_;                                                         
        double dVolumen_;                                                       
};
/*===========================================================================*/
/* Desc.: Konstruktur; er initialisiert die private Members dMasse_ und      */
/*        dVolumen_                                                          */
/* In   : dMasse: double; dVolumen: double                                   */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
tLiquid::tLiquid (void)                                                              
/*---------------------------------------------------------------------------*/
{
    dMasse_   = 1.0;
    dVolumen_ = 1.0;
}
/*===========================================================================*/
/* Desc.: Ermittelt aus Masse und Volumen die Dichte eines Koerpers.         */
/* In   : -                                                                  */
/* Out  : Dichete (double); Falls dVolumen <= 0 wird 0 zurueck gegeben.      */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
double tLiquid::retDichte (void)                                                
/*---------------------------------------------------------------------------*/
{
    if (dVolumen_ <= 0)
        return .0;
    return fabs(dMasse_/dVolumen_);
}
/*===========================================================================*/
/* Desc.: Setzt die Masse                                                    */
/* In   : dMasse (double)                                                    */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void tLiquid::setMasse (double dMasse)                                           //4            
/*---------------------------------------------------------------------------*/
{
    dMasse_ = dMasse;
}
/*===========================================================================*/
/* Desc.: Setzt das Volumen                                                  */
/* In   : dVolumen (double)                                                  */
/* Out  : -                                                                  */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
void tLiquid::setVolumen (double dVolumen)                                      //5                  
/*---------------------------------------------------------------------------*/
{
    dVolumen_ = dVolumen;
}
int main (void)
{
    tLiquid liquid1;                                                                                                                                  
    //=========================================
    CONST WCHAR * str = L"P003K6_C2CPP";
    printConsole (str);
    //=========================================  
    liquid1.setMasse (.88);                                                     //6
    cout << "Die Fluessigkeit hat eine Dichte von " 
         << liquid1.retDichte() << " g/qcm.\n";                                
    cout << "Die Fluessigkeit heisst Benzol.\n";                        
    return 0;                                                    
}
