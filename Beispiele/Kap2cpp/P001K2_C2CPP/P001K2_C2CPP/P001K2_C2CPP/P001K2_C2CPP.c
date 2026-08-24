//P001K2_C2CPP.c
#include <stdio.h>                                                      //1
//#include <math.h> 
#include <windows.h>
#define iStrLen_ 32                                                     //2
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
struct tLiquid                                                          //3
{ 
    char cFarbe[iStrLen_];                                              //4
    char cFormel[iStrLen_];                                             //5
    double dMasse;                                                      //6
    double dVolumen;                                                    //7
    double (*dPtr2RetDichte)(double, double);                           //8
};

/*===========================================================================*/
/* Desc.: Ermittelt aus Masse und Volumen die Dichte eines Koerpers.         */
/* In   : dMasse (double): Masse                                             */
/*        dVolumen (double): Volumen                                         */
/* Out  : Dichete (double); Falls dVolumen <= 0 wird 0 zurueck gegeben.      */
/*===========================================================================*/
/*---------------------------------------------------------------------------*/
double retDichte (double dMasse, double dVolumen)                       //9
/*---------------------------------------------------------------------------*/
{
    if (dVolumen <= 0)
        return .0;
    return (double)fabs(dMasse/dVolumen);
}

int main (void)
{
    struct tLiquid liquid1;                                             //10
    struct tLiquid liquid2;                                             //11

    //=========================================
    CONST WCHAR * str = L"P001K2_C2CPP";
    printConsole (str);
    //========================================= 


    liquid1.dMasse   = 1;                                               //12              
    liquid1.dVolumen = 1;                                               //13                
    liquid1.dPtr2RetDichte  = retDichte;                                //14
    strcpy_s (liquid1.cFarbe, iStrLen_, "transparant");                 //15
    strcpy_s (liquid1.cFormel, iStrLen_, "H2O");                        //16
    printf ("Es handelt sich um eine Fluessigkeit die %s ist und\n"
            "der chemischen Formel %s genuegt.\n", 
            liquid1.cFarbe, liquid1.cFormel);                           //17
    printf ("Die Fluessigkeit hat eine Dichte von %.2f g/qcm.\n", 
            liquid1.dPtr2RetDichte(liquid1.dMasse, liquid1.dVolumen));  //18 
    printf ("Die Fluessigkeit heisst Wasser.\n");                       //19

    liquid2.dMasse   = 0.88;                                            //20 ff  
    liquid2.dVolumen = 1;                
    liquid2.dPtr2RetDichte  = retDichte;
    strcpy_s (liquid2.cFarbe, iStrLen_, "transparant");
    strcpy_s (liquid2.cFormel, iStrLen_, "C6H6");
    printf ("\nEs handelt sich um eine Fluessigkeit die %s ist und\n"
			"der chemischen Formel %s genuegt.\n", 
			liquid2.cFarbe, liquid2.cFormel);
    printf ("Die Fluessigkeit hat eine Dichte von %.2f g/qcm.\n", 
			liquid2.dPtr2RetDichte(liquid2.dMasse, liquid2.dVolumen)); 
    printf ("Die Fluessigkeit heisst Benzol.\n"); 

    return 0;                                                           //21
}