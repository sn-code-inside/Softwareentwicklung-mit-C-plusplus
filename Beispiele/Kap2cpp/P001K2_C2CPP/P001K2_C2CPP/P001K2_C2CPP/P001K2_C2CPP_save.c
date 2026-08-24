//P001K2_C2CPP.c
#include <stdio.h>
#define iStrLen_ 32                                                     //1
//=============================================
#include <Windows.h>                                
void printConsole (LPCTSTR lpConsoleTitle)
{
    SetConsoleTitle (lpConsoleTitle);
}
//=============================================  
struct tLiquid                                                          //2
{
    char cFarbe[iStrLen_];                                              //3
    char cFormel[iStrLen_];                                             //4
    double dMasse;                                                      //5
    double dVolumen;                                                    //6
    double (*dPtr2RetDichte)(double, double);                           //7
};

double retDichte (double dMasse, double dVolumen)                       //8
{
    return dMasse/dVolumen;
}

int main (void)
{
    struct tLiquid liquid1;                                             //9
    struct tLiquid liquid2;                                             //10

    //=========================================
    CONST WCHAR * str = L"P001K2_C2CPP";

    //========================================= 
    printConsole (str);

    liquid1.dMasse   = 1;                                               //11              
    liquid1.dVolumen = 1;                                               //12                
    liquid1.dPtr2RetDichte  = retDichte;                                //13
    strcpy_s (liquid1.cFarbe, iStrLen_, "transparant");                 //14
    strcpy_s (liquid1.cFormel, iStrLen_, "H2O");                        //15
    printf ("Es handelt sich um eine Fluessigkeit die %s ist und\n"
			"der chemischen Formel %s genuegt.\n", 
			liquid1.cFarbe, liquid1.cFormel);                           //16
    printf ("Die Fluessigkeit hat eine Dichte von %.2f g/qcm.\n", 
			liquid1.dPtr2RetDichte(liquid1.dMasse, liquid1.dVolumen));  //17 
    printf ("Die Fluessigkeit heisst Wasser.\n");                       //18

    liquid2.dMasse   = 0.88;                                            //19 ff  
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

    return 0;
}